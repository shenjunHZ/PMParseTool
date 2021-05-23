#include <boost/filesystem.hpp>
#include "XMLFileParser.hpp"
#include "Logger/Logger.hpp"

namespace FileRead
{
    bool XMLFileParser::parseFile(const std::string& fileName, boost::property_tree::ptree& propertyTree)
    {
        boost::filesystem::path pathFile(fileName);
        if (! boost::filesystem::exists(pathFile))
        {
            LOG_WARNING_MSG("parse {} doesn't exist.", fileName);
            return false;
        }

        if (! boost::filesystem::is_regular_file(pathFile))
        {
            LOG_WARNING_MSG("{} is not regular file", fileName);
            return false;
        }

        try
        {
            read_xml(fileName, propertyTree);
        }
        catch (const std::exception& e)
        {
            LOG_WARNING_MSG(e.what());
            return false;
        }

        return true;
    }

    boost::property_tree::ptree& XMLFileParser::getData(boost::property_tree::ptree& propertyTree)
    {
        const std::string OMeS = "OMeS";
        return propertyTree.get_child(OMeS);
    }

    std::string XMLFileParser::getAttrStartTime(const boost::property_tree::ptree& pmNode) const
    {
        const std::string startTime = "<xmlattr>.startTime";
        try
        {
            return pmNode.get<std::string>(startTime);
        }
        catch (...)
        {
            LOG_ERROR_MSG("Get start time failed.");
            return "";
        }
    }

    std::string XMLFileParser::getAttrInterval(const boost::property_tree::ptree& pmNode) const
    {
        const std::string interval = "<xmlattr>.interval";
        try
        {
            return pmNode.get<std::string>(interval);
        }
        catch (...)
        {
            LOG_ERROR_MSG("Get interval failed.");
            return "";
        }
    }

    std::string XMLFileParser::getPmDistName(const boost::property_tree::ptree& pmNode) const
    {
        const std::string distName = "MO.DN";
        try
        {
            return pmNode.get<std::string>(distName);
        }
        catch (...)
        {
            LOG_ERROR_MSG("Get distName failed.");
            return "";
        }
    }

    std::string XMLFileParser::getPmMeasurementTypeForPmTarget(const boost::property_tree::ptree& pmNode) const
    {
        const std::string measurementType = "PMTarget.<xmlattr>.measurementType";
        try
        {
            return pmNode.get<std::string>(measurementType);
        }
        catch (...)
        {
            LOG_ERROR_MSG("Get measurement type failed.");
            return "";
        }
    }

    std::string XMLFileParser::getPmMeasurementTypeForWBTS(const boost::property_tree::ptree& pmNode) const
    {
        const std::string measurementType = "<xmlattr>.measurementType";
        try
        {
            return pmNode.get<std::string>(measurementType);
        }
        catch (const std::exception& e)
        {
            LOG_ERROR_MSG("Get measurement type failed {}.", e.what());
            return "";
        }
    }

    const boost::property_tree::ptree& XMLFileParser::getPmTargetData(const boost::property_tree::ptree& propertyTree)
    {
        const std::string PMTarget = "PMTarget";
        return propertyTree.get_child(PMTarget);
    }

    std::string XMLFileParser::getXmlAttrValue(const boost::property_tree::ptree::value_type& pmNode) const
    {
        try
        {
            return pmNode.second.get_value<std::string>();
        }
        catch (...)
        {
            return "";
        }
    }

} // nsmaespace FileRead