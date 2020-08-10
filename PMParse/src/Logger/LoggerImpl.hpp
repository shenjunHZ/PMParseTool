#pragma once

#include "LoggerEnabled.hpp"

#define LOG_MSG_IMPL(loggerInstance, prio, ...)                                                             \
    if (::logger::internals::globalLogEnabled() && ::logger::internals::logEnabled(logger::Priority::prio)) \
    loggerInstance.prio(__VA_ARGS__); \
    loggerInstance.flush();
