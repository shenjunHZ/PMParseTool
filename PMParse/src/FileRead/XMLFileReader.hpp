#pragma once

#include "IFileReader.hpp"

namespace FileRead
{
class XMLFileReader : public IFileReader
{
public:
    XMLFileReader() = default;
    ~XMLFileReader() = default;

    bool getAllFiles(const std::string& rootPath, std::vector<std::string>& files);
};
} // namespace FileRead