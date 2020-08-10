#pragma once
#include <string>
#include <vector>

namespace FileRead
{
class IFileReader
{
public:
    virtual ~IFileReader() = default;

    virtual bool getAllFiles(const std::string& rootPath, std::vector<std::string>& files) = 0;
};
} // namespace FileRead