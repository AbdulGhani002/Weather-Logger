#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <mutex>

class TelemetryLogger {
public:
    TelemetryLogger(const std::string& logFile) : logFile(logFile) {}

    void logEvent(const std::string& event) {
        std::lock_guard<std::mutex> lock(mutex);
        std::ofstream file(logFile, std::ios::app);
        if (file.is_open()) {
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            file << std::ctime(&now_time) << ": " << event << std::endl;
            file.close();
        } else {
            std::cerr << "Failed to open log file." << std::endl;
        }
    }

    void logUsageData(const std::string& data) {
        std::lock_guard<std::mutex> lock(mutex);
        std::ofstream file(logFile, std::ios::app);
        if (file.is_open()) {
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            file << std::ctime(&now_time) << ": " << data << std::endl;
            file.close();
        } else {
            std::cerr << "Failed to open log file." << std::endl;
        }
    }

    void runInstallScript() {
        int result = std::system("./install.sh");
        if (result != 0) {
            std::cerr << "Error running install.sh script." << std::endl;
        }
    }

private:
    std::string logFile;
    std::mutex mutex;
};

int main() {
    TelemetryLogger logger("telemetry.log");

    logger.logEvent("Application started");
    logger.logUsageData("User clicked on 'Start' button");
    logger.runInstallScript();

    return 0;
}
