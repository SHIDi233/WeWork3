#ifndef FILEENCRYPTION_H
#define FILEENCRYPTION_H

#include <iostream>

class FileEncryption
{
public:
    FileEncryption();
private:
    void encryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr);
    void decryptFileCBC(const std::string& inputFileName, const std::string& outputFileName, const std::string& keyStr, const std::string& ivStr);

};

#endif // FILEENCRYPTION_H
