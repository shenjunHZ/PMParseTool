#include <boost/property_tree/xml_parser.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "DataManagement.hpp"
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

    void DataManagement::readPmTargetObject(const boost::property_tree::ptree& node, common::SPmTarget& pmTarget)
    {
        const std::string distName = fileParser_->getPmDistName(node);
        pmTarget.measurementType = fileParser_->getPmMeasurementType(node);
        auto pmCounters = fileParser_->getPmTargetData(node);
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