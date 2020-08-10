#include <spdlog/common.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <vector>
#include "logger/LoggerConfiguration.hpp"

std::vector<spdlog::sink_ptr> LoggerConfiguration::sinks = {};

