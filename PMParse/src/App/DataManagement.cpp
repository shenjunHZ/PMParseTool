#include <boost/property_tree/xml_parser.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "app/DataManagement.hpp"
#include "FileRead/XMLFileReader.hpp"
#include "FileRead/XMLFileParser.hpp"
#include "Logger/Logger.hpp"
#include "common/PmTargetData.hpp"
#include "common/PmDatas.hpp"

namespace App
{
    using boost::property_tree::ptree;
    DataManagement::DataManagement(const std::string& rootPath)
        : rootPath_{ rootPath }
        , fileReader_{std::make_unique<FileRead::XMLFileReader>()}
        , fileParser_{std::make_unique<FileRead::XMLFileParser>()}
        , pmDatas_{ std::make_unique<db::PmDatas>() }
    {
        getAllXmlFiles();
        parseAllXmlFiles();
    }

    void DataManagement::getAllXmlFiles()
    {
        files_.clear();
        if (fileReader_)
        {
            fileReader_->getAllFiles(rootPath_, files_);
        }
    }

    void DataManagement::parseAllXmlFiles()
    {
        if (pmDatas_)
        {
            pmDatas_->clearPmTarget();
        }

        for (const auto file : files_)
        {
            parseXmlFile(file);
        }
    }

    bool DataManagement::parseXmlFile(const std::string& fileName)
    {
        ptree pmTree;
        std::string startPosixTime = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
        if (! fileParser_->parseFile(fileName, pmTree))
        {
            LOG_ERROR_MSG("Parse xml file: {} failed.", fileName);
            return false;
        }
        std::string endPosixTime = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
        LOG_DEBUG_MSG("Parse xml file: {}, start time: {}, end time: {}.", fileName, startPosixTime, endPosixTime);
        auto pmData = fileParser_->getData(pmTree);
        const std::string firstNodeValue = "PMSetup";
        for (const ptree::value_type& valueNode : pmData)
        {
            if (firstNodeValue == valueNode.first)
            {
                readPMMOResultObject(valueNode.second);
            }
        }
        return true;
    }

    void DataManagement::readPMMOResultObject(const boost::property_tree::ptree& node)
    {
        common::SPmTarget pmTargetData;
        pmTargetData.startTime = fileParser_->getAttrStartTime(node);
        pmTargetData.interval = fileParser_->getAttrInterval(node);

        const std::string firstNodeValue = "PMMOResult";
        for (const ptree::value_type& valueNode : node)
        {
            if (firstNodeValue == valueNode.first)
            {
                readPmTargetObject(valueNode.second, pmTargetData);
            }
        }
    }

    void DataManagement::readPmTargetObject(const boost::property_tree::ptree& nodes, common::SPmTarget& pmTarget)
    {
        const std::string distName = fileParser_->getPmDistName(nodes);
        std::string measurementTpyeAttr = "NE-WBTS_1.0";
        for (const auto& node : nodes)
        {
            if (measurementTpyeAttr == node.first)
            {
                pmTarget.measurementType = fileParser_->getPmMeasurementTypeForWBTS(node.second); // first second is xmlattr

                for (const auto& meas : node.second)
                {
                    if (std::string::npos == meas.first.find("xmlattr"))
                    {
                        const std::string counter = meas.first;
                        const std::string value = fileParser_->getXmlAttrValue(meas);
                        if (!counter.empty() && !value.empty())
                        {
                            if (!pmTarget.counters.insert(std::make_pair(counter, value)).second)
                            {
                                LOG_WARNING_MSG("Insert counter failed: {}, {}.", counter, value);
                            }
                        }
                    }
                }
            }
        }
        if (pmTarget.measurementType.empty())
        {
            pmTarget.measurementType = fileParser_->getPmMeasurementTypeForPmTarget(nodes);
            auto pmCounters = fileParser_->getPmTargetData(nodes);
            for (const ptree::value_type& valueNode : pmCounters)
            {
                const std::string counter = valueNode.first;
                const std::string value = fileParser_->getXmlAttrValue(valueNode);
                if (!counter.empty() && !value.empty())
                {
                    if (!pmTarget.counters.insert(std::make_pair(counter, value)).second)
                    {
                        LOG_WARNING_MSG("Insert counter failed: {}, {}.", counter, value);
                    }
                }
            }
        }

        std::size_t pos = distName.find_last_of("/");
        if (std::string::npos != pos && pmDatas_)
        {
            const std::string unit = distName.substr(pos + 1);
            pmDatas_->setPmTarget(unit, pmTarget);
        }
        pmTarget.clearMeasurement();
    }

    const db::IPmDatas& DataManagement::getPmDatas() const
    {
        return *pmDatas_;
    }

} // namespace App