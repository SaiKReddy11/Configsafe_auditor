#include "utils.h" // Utility functions header
#include <fstream> // File stream operations
#include <regex> // Regular expression utilities
#include <stdexcept> // Exception handling

namespace Utils { // Namespace for utility functions
    std::vector<std::string> scanFileForPII(const std::string& filename) { // Function to scan a file for Personally Identifiable Information (PII)
        std::ifstream file(filename); // Open the file for reading
        if (!file.is_open()) { // Check if the file opened successfully
            throw std::runtime_error("Unable to open file: " + filename);
        }

        std::regex email_pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
        std::regex ssn_pattern(R"(\b\d{3}-\d{2}-\d{4}\b)");

        std::vector<std::string> findings; // Vector to store findings
        std::string line;
        int line_number = 0;

        while (std::getline(file, line)) { // Read the file line by line
            ++line_number;
            std::smatch match;

            auto words_begin = std::sregex_iterator(line.begin(), line.end(), email_pattern);
            auto words_end = std::sregex_iterator(); // End iterator for regex search
            for (auto i = words_begin; i != words_end; ++i) {
                findings.push_back("Line " + std::to_string(line_number) + ": Email (" + i->str() + ")");
            }

            words_begin = std::sregex_iterator(line.begin(), line.end(), ssn_pattern); // 
            for (auto i = words_begin; i != words_end; ++i) { // Search for SSNs
                findings.push_back("Line " + std::to_string(line_number) + ": SSN (" + i->str() + ")");
            }
        }

        file.close(); // Close the file after readingd
        return findings; // Return the findings vector
    }
}