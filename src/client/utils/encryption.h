#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <fstream>

namespace Encryption
{
    void encryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr);
    void decryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr);
    std::string encryptWords(const std::string& plaintext, const std::string& keyStr, const std::string& ivStr);
    std::string decryptWords(const std::string& ciphertext, const std::string& keyStr, const std::string& ivStr);
};

#endif // ENCRYPTION_H
