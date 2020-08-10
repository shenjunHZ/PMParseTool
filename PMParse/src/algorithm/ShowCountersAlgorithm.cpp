#include "ShowCountersAlgorithm.hpp"
#include "App/DataManagement.hpp"
#include "common/PmDatas.hpp"

namespace algorithm
{

    ShowCountersAlgorithm::ShowCountersAlgorithm(const App::IDataManagement& dataManagement)
        : dataManagement_{dataManagement}
    {

    }

CounterValues ShowCountersAlgorithm::getCounterValues(const std::string& unitId, const std::string& counter)
{
    CounterValues pmCounterValuess;
    const auto& pmDatas = dataManagement_.getPmDatas();
    const auto& pmTargets = pmDatas.getPmTarget(unitId);
    for (const auto& target : pmTargets)
    {
        for (const auto& counterValue : target.counters)
        {
            if (counterValue.first == counter)
            {
                pmCounterValuess.insert(std::pair<std::string, std::string>(target.startTime, counterValue.second));
            }
        }
    }
    return pmCounterValuess;
}

}