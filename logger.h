#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>

namespace Logger {
    void logAudit(const std::string& filename, const std::vector<std::string>& findings);
}

#endif