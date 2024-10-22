#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <curl/curl.h>

class NASAApiClient {
public:
    NASAApiClient(const std::string& apiKey) : apiKey(apiKey) {}

    std::string queryAPI(const std::string& endpoint) {
        std::lock_guard<std::mutex> lock(mutex);
        if (cache.find(endpoint) != cache.end()) {
            return cache[endpoint];
        }

        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, (baseURL + endpoint + "&api_key=" + apiKey).c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                return "";
            }

            cache[endpoint] = readBuffer;
        }

        return readBuffer;
    }

    void queryAPIMultiThreaded(const std::vector<std::string>& endpoints) {
        std::vector<std::thread> threads;
        for (const auto& endpoint : endpoints) {
            threads.emplace_back(&NASAApiClient::queryAPI, this, endpoint);
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }

private:
    std::string apiKey;
    std::string baseURL = "https://api.nasa.gov/";
    std::mutex mutex;
    std::unordered_map<std::string, std::string> cache;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};
