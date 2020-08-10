#include <boost/filesystem.hpp>
#include "XMLFileReader.hpp"
#include "Logger/Logger.hpp"

namespace
{
    bool checkPathIsDirectory(const std::string& rootPath)
    {
        boost::system::error_code error;
        auto file_status = boost::filesystem::status(rootPath, error);
        if (error)
        {
            return false;
        }

        if (!boost::filesystem::exists(file_status))
        {
            return false;
        }

        if (boost::filesystem::is_directory(file_status))
        {
            return true;
        }

        return false;
    }

    const std::string XMLFILE = ".xml";
} // namespace

namespace FileRead
{

bool XMLFileReader::getAllFiles(const std::string& rootPath, std::vector<std::string>& files)
{
    if (!checkPathIsDirectory(rootPath))
    {
        return false;
    }

    namespace fs = boost::filesystem;
    fs::path fullpath(rootPath);
    fs::recursive_directory_iterator end_iter;
    for (fs::recursive_directory_iterator iter(fullpath); iter != end_iter; iter++)
    {
        try
        {
            std::string file = iter->path().string();
            if ( fs::is_regular_file(iter->status()) && XMLFILE == iter->path().extension())
            {
                files.push_back(file);
            }
        }
        catch (const std::exception & e)
        {
            LOG_WARNING_MSG( e.what() );
            continue;
        }
    }
    return true;
}

} // namespace FileRead