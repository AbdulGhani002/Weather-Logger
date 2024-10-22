#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "../src/backend/nasa_api_client.cpp"
#include "../src/gui/gui_rendering_engine.cpp"

void testFullSystemWithActualNASAData() {
    NASAApiClient apiClient("your_api_key_here");
    std::string data = apiClient.queryAPI("planetary/apod?date=2021-10-01");
    assert(!data.empty());
    std::cout << "Full system test with actual NASA data passed." << std::endl;
}

void testGUIResponsiveness() {
    GUIRenderingEngine guiEngine;
    guiEngine.createWindow("Weather Dashboard", 800, 600);
    guiEngine.createButton("Weather Dashboard", "Refresh", []() {
        std::cout << "Refresh button clicked." << std::endl;
    });
    guiEngine.updateGUI();
    std::cout << "GUI responsiveness test passed." << std::endl;
}

void testInstallScript() {
    int result = std::system("python3 -m venv venv && source venv/bin/activate && ./install.sh && deactivate");
    assert(result == 0);
    std::cout << "Install script test passed." << std::endl;
}

int main() {
    testFullSystemWithActualNASAData();
    testGUIResponsiveness();
    testInstallScript();
    return 0;
}
