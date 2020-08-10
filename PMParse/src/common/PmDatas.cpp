#include "common/PmDatas.hpp"

namespace db
{
void PmDatas::setPmTarget(const std::string& unitId, const common::SPmTarget& pmTarget)
{
    const auto& pmData = datas_.find(unitId);
    if (pmData != datas_.end())
    {
        pmData->second.push_back(pmTarget);
    }
    else
    {
        std::vector<common::SPmTarget> targets{pmTarget};
        datas_.insert(std::pair<std::string, std::vector<common::SPmTarget>>(unitId, targets));
    }
}

void PmDatas::clearPmTarget()
{
    datas_.clear();
}

const std::vector<common::SPmTarget>& PmDatas::getPmTarget(const std::string& unitId) const
{
    const auto& pmData = datas_.find(unitId);
    if (pmData != datas_.end())
    {
        return pmData->second;
    }
    return {};
}

std::set<std::string> PmDatas::getAllPmTargetUnits() const
{
    std::set<std::string> unitIds;
    for (const auto& data : datas_)
    {
        unitIds.insert(data.first);
    }
    return unitIds;
}

} // namespace db