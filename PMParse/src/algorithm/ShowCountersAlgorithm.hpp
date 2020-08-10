#pragma once
#include "IShowCounterAlgorithm.hpp"

namespace App
{
class IDataManagement;
} // namespace App

namespace algorithm
{
class ShowCountersAlgorithm : public IShowCountersAlgorithm
{
public:
    ShowCountersAlgorithm(const App::IDataManagement& dataManagement);
    ~ShowCountersAlgorithm() = default;

    CounterValues getCounterValues(const std::string& unit, const std::string& counter) override;

private:
    const App::IDataManagement& dataManagement_;
};
} // namespace algorithm
