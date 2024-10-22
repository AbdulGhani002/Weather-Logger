#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "../src/backend/nasa_api_client.cpp"
#include "../src/backend/database_engine.cpp"
#include "../src/gui/gui_rendering_engine.cpp"

void testGUIBackendAPIIntegration() {
    NASAApiClient client("DEMO_KEY");
    std::string response = client.queryAPI("planetary/apod?date=2021-10-01");
    assert(!response.empty());

    DatabaseEngine db;
    db.storeData("apod", response);
    std::string retrievedData = db.retrieveData("apod");
    assert(retrievedData == response);

    GUIRenderingEngine gui;
    gui.createWindow("Main Window", 800, 600);
    gui.createButton("Main Window", "Fetch Data", [&client, &db, &gui]() {
        std::string data = client.queryAPI("planetary/apod?date=2021-10-02");
        db.storeData("apod", data);
        gui.createWeatherChart("Main Window", {1.0, 2.0, 3.0});
    });

    std::cout << "testGUIBackendAPIIntegration passed" << std::endl;
}

void testPerformanceUnderLoad() {
    NASAApiClient client("DEMO_KEY");
    std::vector<std::string> endpoints;
    for (int i = 0; i < 100; ++i) {
        endpoints.push_back("planetary/apod?date=2021-10-" + std::to_string(i + 1));
    }

    client.queryAPIMultiThreaded(endpoints);

    DatabaseEngine db;
    for (const auto& endpoint : endpoints) {
        std::string data = client.queryAPI(endpoint);
        db.storeData(endpoint, data);
    }

    std::cout << "testPerformanceUnderLoad passed" << std::endl;
}

int main() {
    testGUIBackendAPIIntegration();
    testPerformanceUnderLoad();
    return 0;
}
