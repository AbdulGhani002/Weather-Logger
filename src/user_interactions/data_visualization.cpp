#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

class DataVisualization {
public:
    DataVisualization() {}

    void plotBarChart(const std::string& title, const std::map<std::string, double>& data) {
        std::cout << "Bar Chart: " << title << std::endl;
        for (const auto& entry : data) {
            std::cout << entry.first << ": " << std::string(static_cast<int>(entry.second), '|') << std::endl;
        }
    }

    void plotPieChart(const std::string& title, const std::map<std::string, double>& data) {
        std::cout << "Pie Chart: " << title << std::endl;
        double total = 0;
        for (const auto& entry : data) {
            total += entry.second;
        }
        for (const auto& entry : data) {
            std::cout << entry.first << ": " << (entry.second / total) * 100 << "%" << std::endl;
        }
    }

    void plotLineGraph(const std::string& title, const std::vector<std::pair<std::string, double>>& data) {
        std::cout << "Line Graph: " << title << std::endl;
        for (const auto& entry : data) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    }

    void visualizeMapData(const std::string& title, const std::vector<std::vector<int>>& mapData) {
        std::cout << "Map Data Visualization: " << title << std::endl;
        for (const auto& row : mapData) {
            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }

    void showWeatherAlert(const std::string& alertMessage) {
        std::cout << "Weather Alert: " << alertMessage << std::endl;
    }

    void createInteractiveTimeline(const std::string& title, const std::vector<std::pair<std::string, std::string>>& events) {
        std::cout << "Interactive Timeline: " << title << std::endl;
        for (const auto& event : events) {
            std::cout << event.first << ": " << event.second << std::endl;
        }
    }
};
