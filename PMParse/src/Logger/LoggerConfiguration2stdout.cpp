#include <spdlog/common.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <vector>
#include "logger/LoggerConfiguration.hpp"

namespace
{
    const std::string PARSE_TOOL_LOG = "parseTool.log";
    const int maxFileSize = 3 * 1024 * 1024;
    const int maxRotateFiles = 3;
}
std::vector<spdlog::sink_ptr> LoggerConfiguration::sinks = {
        std::make_shared<spdlog::sinks::rotating_file_sink_mt>(PARSE_TOOL_LOG, maxFileSize, maxRotateFiles),
        std::make_shared<spdlog::sinks::stdout_sink_mt>() };

