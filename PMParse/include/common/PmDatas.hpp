#pragma once
#include <map>
#include <vector>
#include <set>
#include "common/PmTargetData.hpp"

namespace db
{
class IPmDatas
{
public:
    virtual ~IPmDatas() = default;
    virtual void setPmTarget(const std::string& unitId, const common::SPmTarget& pmTarget) = 0;
    virtual void clearPmTarget() = 0;
    virtual const std::vector<common::SPmTarget>& getPmTarget(const std::string& unitId) const = 0;
    virtual std::set<std::string> getAllPmTargetUnits() const = 0;
};

class PmDatas : public IPmDatas
{
public:
    void setPmTarget(const std::string& unitId, const common::SPmTarget& pmTarget) override;
    void clearPmTarget() override;
    const std::vector<common::SPmTarget>& getPmTarget(const std::string& unitId) const override;
    std::set<std::string> getAllPmTargetUnits() const override;

private:
    std::map<std::string, std::vector<common::SPmTarget> > datas_;
};

} // namespace db
