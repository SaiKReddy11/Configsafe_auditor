#include <iostream> // Standard input/output streams
#include <string> // String manipulation
#include <stdexcept> // Exception handling
#include "utils.h" // Utility functions for scanning files
#include "logger.h" // Logging utility

// Main function
int main(int argc, char* argv[]) { // Entry point of the program
    try { // Try block to catch exceptions
        if (argc != 3 || std::string(argv[1]) != "-f") { // Check command line arguments
            throw std::invalid_argument("Usage: ./configsafe_auditor -f <filename>");
        }

        std::string filename = argv[2]; // Get the filename from command line arguments
        auto findings = Utils::scanFileForPII(filename);

        if (findings.empty()) { // Check if any sensitive data was found
            std::cout << "No sensitive data found in " << filename << "\n";
        } else { // If sensitive data was found, print it
            std::cout << "Sensitive data found in " << filename << ":\n";
            for (const auto& finding : findings) { // Iterate through findings
                std::cout << "- " << finding << "\n";
            }
        }

        Logger::logAudit(filename, findings); // Log the audit findings
        std::cout << "Audit logged to audit.log\n";
    }
    catch (const std::exception& e) { // Catch any exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return error code
    }
    return 0; // Successful execution
}