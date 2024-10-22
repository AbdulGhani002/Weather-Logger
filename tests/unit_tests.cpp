#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "../src/backend/nasa_api_client.cpp"
#include "../src/backend/database_engine.cpp"
#include "../src/image_analysis/image_processing.cpp"
#include "../src/weather_forecasting/forecasting_algorithms.cpp"
#include "../src/data_structures/advanced_data_structures.cpp"

void testNASAApiClient() {
    NASAApiClient client("DEMO_KEY");
    std::string response = client.queryAPI("planetary/apod?date=2021-10-01");
    assert(!response.empty());
    std::cout << "testNASAApiClient passed" << std::endl;
}

void testDatabaseEngine() {
    DatabaseEngine db;
    db.storeData("key1", "value1");
    assert(db.retrieveData("key1") == "value1");
    std::cout << "testDatabaseEngine passed" << std::endl;
}

void testImageProcessing() {
    ImageProcessing imgProc;
    cv::Mat image = imgProc.loadImage("test.jpg");
    assert(!image.empty());
    cv::Mat grayImage = imgProc.convertToGrayscale(image);
    assert(!grayImage.empty());
    std::cout << "testImageProcessing passed" << std::endl;
}

void testForecastingAlgorithms() {
    ForecastingAlgorithms forecast;
    std::vector<double> rawData = {1.0, 2.0, 3.0};
    std::vector<double> forecasts = forecast.calculateForecasts(rawData);
    assert(forecasts.size() == rawData.size());
    std::cout << "testForecastingAlgorithms passed" << std::endl;
}

void testAdvancedDataStructures() {
    CustomTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.traverse();
    std::cout << "testAdvancedDataStructures passed" << std::endl;
}

void testInstallScript() {
    int result = std::system("./install.sh");
    assert(result == 0);
    std::cout << "Install script test passed." << std::endl;
}

int main() {
    testNASAApiClient();
    testDatabaseEngine();
    testImageProcessing();
    testForecastingAlgorithms();
    testAdvancedDataStructures();
    testInstallScript();
    return 0;
}
