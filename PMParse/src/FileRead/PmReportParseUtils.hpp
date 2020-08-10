#pragma once
#include <memory>
#include "IFileParser.hpp"

namespace FileRead
{
class PmReportParseUtils
{
public:
    PmReportParseUtils(std::shared_ptr<IFileParser> parser);

private:
    std::shared_ptr<IFileParser> xmlParser_;
};
} // namespace FileRead