#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>

/*
    <PMSetup startTime="2019-08-20T09:30:00.000+09:00" interval="15">
        <PMMOResult>
            <MO dimension="network_element">
                <DN>PLMN-PLMN/MRBTS-1281769/NRBTS-1281769</DN>
            </MO>
            <PMTarget measurementType="NX2CB">
                <M55110C00001>0</M55110C00001>
                <M55110C00002>0</M55110C00002>
            </PMTarget>
        </PMMOResult>
    </PMSetup>
*/

namespace FileRead
{
class IFileParser
{
public:
    virtual ~IFileParser() = default;

    virtual bool parseFile(const std::string& fileName, boost::property_tree::ptree& propertyTree) = 0;
    virtual boost::property_tree::ptree& getData(boost::property_tree::ptree& propertyTree) = 0;

    virtual std::string getAttrStartTime(const boost::property_tree::ptree& pmNode) const = 0 ;
    virtual std::string getAttrInterval(const boost::property_tree::ptree& pmNode) const = 0;

    virtual std::string getPmDistName(const boost::property_tree::ptree& pmNode) const = 0;
    virtual std::string getPmMeasurementType(const boost::property_tree::ptree& pmNode) const = 0;

    virtual const boost::property_tree::ptree& getPmTargetData(const boost::property_tree::ptree& propertyTree) = 0;
    virtual std::string getXmlAttrValue(const boost::property_tree::ptree::value_type& pmNode) const = 0;
};
} // namespace FileRead