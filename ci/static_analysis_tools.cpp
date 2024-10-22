#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

class StaticAnalysisTool {
public:
    StaticAnalysisTool() {}

    void analyzeFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filePath << std::endl;
            return;
        }

        std::string line;
        int lineNumber = 0;
        while (std::getline(file, line)) {
            lineNumber++;
            checkLineLength(line, lineNumber);
            checkNamingConventions(line, lineNumber);
            checkMagicNumbers(line, lineNumber);
        }

        file.close();
    }

private:
    void checkLineLength(const std::string& line, int lineNumber) {
        const int maxLength = 80;
        if (line.length() > maxLength) {
            std::cerr << "Line " << lineNumber << " exceeds " << maxLength << " characters." << std::endl;
        }
    }

    void checkNamingConventions(const std::string& line, int lineNumber) {
        std::regex variableRegex("[a-z][a-zA-Z0-9]*");
        std::regex functionRegex("[a-z][a-zA-Z0-9]*\\(");
        std::regex classRegex("[A-Z][a-zA-Z0-9]*");

        if (std::regex_search(line, variableRegex)) {
            std::cerr << "Line " << lineNumber << " contains a variable not following camelCase convention." << std::endl;
        }
        if (std::regex_search(line, functionRegex)) {
            std::cerr << "Line " << lineNumber << " contains a function not following camelCase convention." << std::endl;
        }
        if (std::regex_search(line, classRegex)) {
            std::cerr << "Line " << lineNumber << " contains a class not following PascalCase convention." << std::endl;
        }
    }

    void checkMagicNumbers(const std::string& line, int lineNumber) {
        std::regex magicNumberRegex("\\b\\d+\\b");
        if (std::regex_search(line, magicNumberRegex)) {
            std::cerr << "Line " << lineNumber << " contains a magic number." << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    StaticAnalysisTool tool;
    tool.analyzeFile(argv[1]);

    return 0;
}
