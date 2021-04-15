#pragma once
#include <string>
#include <map>
#include "MeasurementType.hpp"

namespace common
{
struct SPmTarget
{
    std::string startTime;       // 2019-08-20T09:30:00.000+09:00
    std::string interval;        // 15
    std::string measurementType; // NX2CB
    std::map<std::string, std::string> counters; // key: M55110C00001 - value

    void operator = (SPmTarget inputData)
    {
        startTime = inputData.startTime;
        interval = inputData.interval;
        measurementType = inputData.measurementType;
        for (const auto& counter : inputData.counters)
        {
            counters.insert(counter);
        }
    }
    void clearMeasurement()
    {
        measurementType = "";
        counters.clear();
    }
};
} // namespace common