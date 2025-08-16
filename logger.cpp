#include "logger.h" //  Logging utility header
#include <fstream> // File stream operations
#include <stdexcept> // Exception handling
#include <chrono> // Time utilities
#include <iomanip> // Formatting utilities

namespace Logger { // Namespace for logging utilities
    void logAudit(const std::string& filename, const std::vector<std::string>& findings) {
        std::ofstream logFile("audit.log", std::ios::app); // Open audit log file in append mode
        if (!logFile.is_open()) { // Check if the log file opened successfully
            throw std::runtime_error("Failed to open audit log"); // Throw an error if the log file cannot be opened
        }

        auto now = std::chrono::system_clock::now(); // Get the current time
        auto time = std::chrono::system_clock::to_time_t(now);
        logFile << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
                << " | File: " << filename << " | Findings: ";
        if (findings.empty()) { // If no findings, log that no sensitive data was found
            logFile << "None\n"; // Log that no sensitive data was found
        } else { // If findings exist, log them
            for (size_t i = 0; i < findings.size(); ++i) { // Iterate through findings
                logFile << findings[i];
                if (i < findings.size() - 1) logFile << ", "; // Add a comma between findings
            }
            logFile << "\n";
        }
        logFile.close(); // Close the log file after writing
    }
}