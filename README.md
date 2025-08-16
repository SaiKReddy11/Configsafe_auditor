ConfigSafe PII Audit Tool
Overview
ConfigSafe PII Audit Tool is a C++ command-line application that scans configuration files for personally identifiable information (PII) like emails and SSNs, ensuring compliance with GDPR and HIPAA. It outputs findings and logs them to audit.log for regulatory auditing, ideal for a government agency demo.
Features Implemented

Command-line argument parsing (-f <filename>).
File I/O (read config file, write audit log).
String parsing with regex (detect emails, SSNs).
Error handling (try/catch for file/input errors).
Modular design (separate main.cpp, utils.cpp, logger.cpp).

Dependencies

g++ compiler with C++17 support.

## Build Instructions
1. Install MSYS2 and g++:
   - Run: `pacman -S mingw-w64-ucrt-x86_64-gcc`
   - Add `C:\msys64\ucrt64\bin` to system PATH.
2. Open project folder in VS Code (`C:\Users\samas\Downloads\configsafe_auditor`).
3. Build:
   - Press Ctrl+Shift+B and select “Build ConfigSafe Auditor”.
   - Or run: `g++ -std=c++17 main.cpp utils.cpp logger.cpp -o configsafe_auditor.exe`


Run:
./configsafe_auditor -f <filename>


Example Usage
Valid Input
./configsafe_auditor.exe -f sample.conf

Output:
Sensitive data found in sample.conf:
- Line 2: Email (john.doe@example.com)
- Line 3: SSN (123-45-6789)
- Line 5: Email (alice.smith@company.org)
Audit logged to audit.log

audit.log:
2025-07-30 21:23:00 | File: sample.conf | Findings: Line 2: Email (john.doe@example.com), Line 3: SSN (123-45-6789), Line 5: Email (alice.smith@company.org)

Invalid Input
./configsafe_auditor -f nonexistent.conf

Output:
Error: Unable to open file: nonexistent.conf

Files

main.cpp: Argument parsing and main logic.
utils.h/cpp: PII detection with regex.
logger.h/cpp: Audit logging.
.vscode/tasks.json: VS Code build task.
sample.conf: Test configuration file.

Author
Sai Kumar Reddy Sama
A00288903
