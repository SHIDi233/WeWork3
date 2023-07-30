/************************************************
Author: Apple_Grey
Date: 2023-7-25
Description: 使用openssl库对文件加密解密的测试源码
*************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <openssl/evp.h>
#include <openssl/aes.h>


/** 使用AES-128 CBC算法对文件进行加密
 * 
 *  参数:
 *   inputFileName: 源文件路径
 *   outputFileName: 输出文件路径
 *   keyStr: 密钥
 *   ivStr: 初始化向量
 **/
void encryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr) {
    const int AES_KEY_LENGTH = 128;

    // 将密钥和初始化向量转换为unsigned char数组
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(key, keyStr.c_str(), AES_KEY_LENGTH / 8);
    memcpy(iv, ivStr.c_str(), AES_BLOCK_SIZE);

    // 初始化AES上下文进行加密
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key, iv);

    // 打开输入和输出文件
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile || !outputFile) {
        std::cerr << "无法打开文件。" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    // 加密缓冲区
    const int bufferSize = 1024;
    unsigned char inputBuffer[bufferSize];
    unsigned char outputBuffer[bufferSize + AES_BLOCK_SIZE];

    int bytesRead, encryptedLength;
    while ((bytesRead = inputFile.read(reinterpret_cast<char*>(inputBuffer), bufferSize).gcount()) > 0) {
        // 加密数据
        EVP_EncryptUpdate(ctx, outputBuffer, &encryptedLength, inputBuffer, bytesRead);

        // 将加密后的数据写入输出文件
        outputFile.write(reinterpret_cast<char*>(outputBuffer), encryptedLength);
    }

    // 完成加密
    EVP_EncryptFinal_ex(ctx, outputBuffer, &encryptedLength);
    outputFile.write(reinterpret_cast<char*>(outputBuffer), encryptedLength);

    // 清理资源
    EVP_CIPHER_CTX_free(ctx);
    inputFile.close();
    outputFile.close();

    std::cout << "文件加密成功。" << std::endl;
}


/** 使用AES-128 CBC算法对文件进行解密
 * 
 *  参数:
 *   inputFileName: 源文件路径
 *   outputFileName: 输出文件路径
 *   keyStr: 密钥
 *   ivStr: 初始化向量
 **/
void decryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr) {
    const int AES_KEY_LENGTH = 128;

    // 将密钥和初始化向量转换为unsigned char数组
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(key, keyStr.c_str(), AES_KEY_LENGTH / 8);
    memcpy(iv, ivStr.c_str(), AES_BLOCK_SIZE);

    // 初始化AES上下文进行解密
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key, iv);

    // 打开输入和输出文件
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile || !outputFile) {
        std::cerr << "无法打开文件。" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    // 解密缓冲区
    const int bufferSize = AES_BLOCK_SIZE;
    unsigned char inputBuffer[bufferSize + 1024];
    unsigned char outputBuffer[bufferSize];

    int bytesRead, decryptedLength;
    while ((bytesRead = inputFile.read(reinterpret_cast<char*>(inputBuffer), bufferSize).gcount()) > 0) {
        // 解密数据
        EVP_DecryptUpdate(ctx, outputBuffer, &decryptedLength, inputBuffer, bytesRead);

        // 将解密后的数据写入输出文件
        outputFile.write(reinterpret_cast<char*>(outputBuffer), decryptedLength);
    }

    // 完成解密
    EVP_DecryptFinal_ex(ctx, outputBuffer, &decryptedLength);
    outputFile.write(reinterpret_cast<char*>(outputBuffer), decryptedLength);

    // 清理资源
    EVP_CIPHER_CTX_free(ctx);
    inputFile.close();
    outputFile.close();

    std::cout << "文件解密成功。" << std::endl;
}

// 使用AES-128 CBC算法对字符串进行加密
std::string encryptStringCBC(const std::string& plaintext, const std::string& keyStr, const std::string& ivStr) {
    const int AES_KEY_LENGTH = 128;

    // 将密钥和初始化向量转换为unsigned char数组
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(key, keyStr.c_str(), AES_KEY_LENGTH / 8);
    memcpy(iv, ivStr.c_str(), AES_BLOCK_SIZE);

    // 初始化AES上下文进行加密
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key, iv);

    // 明文转换为unsigned char数组
    const unsigned char* plaintextData = reinterpret_cast<const unsigned char*>(plaintext.c_str());

    // 加密缓冲区
    const int bufferSize = plaintext.size() + AES_BLOCK_SIZE;
    unsigned char encryptedBuffer[bufferSize];

    int encryptedLength;
    // 加密数据
    EVP_EncryptUpdate(ctx, encryptedBuffer, &encryptedLength, plaintextData, plaintext.size());

    // 完成加密
    int finalLength;
    EVP_EncryptFinal_ex(ctx, encryptedBuffer + encryptedLength, &finalLength);
    encryptedLength += finalLength;

    // 清理资源
    EVP_CIPHER_CTX_free(ctx);

    // 将加密后的数据转换为std::string
    return std::string(reinterpret_cast<char*>(encryptedBuffer), encryptedLength);
}

// 使用AES-128 CBC算法对字符串进行解密
std::string decryptStringCBC(const std::string& ciphertext, const std::string& keyStr, const std::string& ivStr) {
    const int AES_KEY_LENGTH = 128;

    // 将密钥和初始化向量转换为unsigned char数组
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(key, keyStr.c_str(), AES_KEY_LENGTH / 8);
    memcpy(iv, ivStr.c_str(), AES_BLOCK_SIZE);

    // 初始化AES上下文进行解密
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key, iv);

    // 密文转换为unsigned char数组
    const unsigned char* ciphertextData = reinterpret_cast<const unsigned char*>(ciphertext.c_str());

    // 解密缓冲区
    const int bufferSize = ciphertext.size();
    unsigned char decryptedBuffer[bufferSize];

    int decryptedLength;
    // 解密数据
    EVP_DecryptUpdate(ctx, decryptedBuffer, &decryptedLength, ciphertextData, bufferSize);

    // 完成解密
    int finalLength;
    EVP_DecryptFinal_ex(ctx, decryptedBuffer + decryptedLength, &finalLength);
    decryptedLength += finalLength;

    // 清理资源
    EVP_CIPHER_CTX_free(ctx);

    // 将解密后的数据转换为std::string
    return std::string(reinterpret_cast<char*>(decryptedBuffer), decryptedLength);
}

int main() {
    std::string plaintext = "Hello, this is a test string哈哈哈哈哈哈1212313213";
    std::string key = "MySecretKey12345"; // 替换为您自己的密钥
    std::string iv = "InitializationVec"; // 替换为您自己的初始化向量

    // 加密字符串
    std::string ciphertext = encryptStringCBC(plaintext, key, iv);

    std::string s = decryptStringCBC(ciphertext, key, iv);

    std::cout << "明文: " << plaintext << std::endl;
    std::cout << "密文: " << ciphertext << std::endl;
    std::cout << "明文: " << s << std::endl;

    return 0;
}

/*int main() {
    std::string inputFile = R"(D:\Qt\WeWork3\ase\test.txt)"; // 源文件
    std::string encryptedFile = R"(D:\Qt\WeWork3\ase\1.txt)"; // 加密后文件路径
    std::string decryptedFile = R"(D:\Qt\WeWork3\ase\2.txt)"; // 解密后文件路径
    std::string key = "MySecretKey12345"; // 密钥
    std::string iv = "InitializationVe"; // 初始化向量

    encryptFileCBC(inputFile, encryptedFile, key, iv); // 加密
    decryptFileCBC(encryptedFile, decryptedFile, key, iv); // 解密

    return 0;
}*/
