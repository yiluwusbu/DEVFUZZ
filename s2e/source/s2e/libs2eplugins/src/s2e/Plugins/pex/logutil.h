#ifndef _LOG_UTIL_
#define _LOG_UTIL_

#include <ctime>
#include <fstream>
#include <iostream>
#include "color.h"

#define outs() std::cout
#define errs() std::cerr

#define WARN(X) outs() << ANSI_COLOR_RED << "WARN:" << X << ANSI_COLOR_RESET << "\n"

#define INFO(X) outs() << ANSI_COLOR_RESET << "INFO:" << X << "\n"

#define unreachable(XXX)                                             \
    {                                                                \
        errs() << ANSI_COLOR_RED << XXX << ANSI_COLOR_RESET << "\n"; \
        throw;                                                       \
    }

//#define hexval(X) std::hex << X << std::dec

///
/// log to file -- append mode
///

#define LOG_TO_FILE(X, Y)                                          \
    if (1) {                                                       \
        std::ofstream log;                                         \
        log.open(X, std::ofstream::out | std::ofstream::app);      \
        std::time_t result = std::time(nullptr);                   \
        log << std::asctime(std::localtime(&result)) << Y << "\n"; \
        log.close();                                               \
    }

#endif
