#pragma once
#include "IFileParser.hpp"

namespace FileRead
{
class XMLFileParser : public IFileParser
{
public:
    XMLFileParser() = default;
    ~XMLFileParser() = default;

    bool parseFile(const std::string& fileName, boost::property_tree::ptree& propertyTree) override;
    boost::property_tree::ptree& getData(boost::property_tree::ptree& propertyTree) override;

    std::string getAttrStartTime(const boost::property_tree::ptree& pmNode) const override;
    std::string getAttrInterval(const boost::property_tree::ptree& pmNode) const override;

    std::string getPmDistName(const boost::property_tree::ptree& pmNode) const override;
    std::string getPmMeasurementType(const boost::property_tree::ptree& pmNode) const override;

    const boost::property_tree::ptree& getPmTargetData(const boost::property_tree::ptree& propertyTree) override;
    std::string getXmlAttrValue(const boost::property_tree::ptree::value_type& pmNode) const override;

private:

};
} // namespace FileRead
