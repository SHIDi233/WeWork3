#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>

namespace Encryption
{
    void encryptFileCBC(const std::string& inputFileName, const std::string& outputFileName);
    void decryptFileCBC(const std::string& inputFileName, const std::string& outputFileName);
    std::string encryptWords(const std::string& content);
    std::string dencryptWords(const std::string& content);
};

#endif // ENCRYPTION_H
