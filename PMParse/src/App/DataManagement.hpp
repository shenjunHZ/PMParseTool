#pragma once
#include <memory>
#include <vector>
#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include "IDataManagement.hpp"

namespace FileRead
{
class IFileReader;
class IFileParser;
} // FileRead
namespace db
{
class IPmDatas;
} // namespace db
namespace common
{
struct SPmTarget;
} // namespace common

namespace App
{
class DataManagement : public IDataManagement
{
public:
    DataManagement(const std::string& rootPath);

    const db::IPmDatas& getPmDatas() const;

private:
    void getAllXmlFiles();
    void parseAllXmlFiles();

    bool parseXmlFile(const std::string& fileName);
    void readPmTargetObject(const boost::property_tree::ptree& node, common::SPmTarget& pmTarget);
    void readPMMOResultObject(const boost::property_tree::ptree& node);

private:
    const std::string rootPath_{""};
    std::vector<std::string> files_;
    std::unique_ptr<FileRead::IFileReader> fileReader_{ nullptr };
    std::unique_ptr<FileRead::IFileParser> fileParser_{ nullptr };
    std::unique_ptr<db::IPmDatas> pmDatas_{ nullptr };
};
} // namespace App
