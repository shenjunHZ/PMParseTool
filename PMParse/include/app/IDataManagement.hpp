#pragma once

namespace db
{
class IPmDatas;
} // namespace db

namespace App
{
class IDataManagement
{
public:
    virtual ~IDataManagement() = default;
    virtual const db::IPmDatas& getPmDatas() const = 0;
};
} // namespace App
