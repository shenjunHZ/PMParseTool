#pragma once
#include <string>
#include <map>

namespace algorithm
{
using CounterValues = std::map<std::string, std::string>; // reportTime - counterValue
class IShowCountersAlgorithm
{
public:
    virtual ~IShowCountersAlgorithm() = default;

    virtual CounterValues getCounterValues(const std::string& unit, const std::string& counter) = 0;
};
} // namespace algorithm
