#include "PmReportParseUtils.hpp"

namespace FileRead
{

    PmReportParseUtils::PmReportParseUtils(std::shared_ptr<IFileParser> parser)
        : xmlParser_{std::move(parser)}
    {

    }

} // namespace FileRead