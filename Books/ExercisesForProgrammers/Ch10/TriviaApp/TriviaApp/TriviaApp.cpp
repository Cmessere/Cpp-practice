#include <iostream>
#include <curl/curl.h>
#include <json/json.h> 

using namespace std;

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res);
void parseJson(const CURLcode& res, const string& readBuffer);
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

int main()
{
    CURLcode res;
    string readBuffer;
    CURL* curl;
    curl = curl_easy_init();

    fetchData(curl, readBuffer, res);
    parseJson(res, readBuffer);
}

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res)
{
    string baseUrl = "https://opentdb.com/api.php?amount=50&category=15&type=multiple";

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, baseUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

void parseJson(const CURLcode& res, const string& readBuffer)
{
    if (res == CURLE_OK) {
        Json::Value data;
        Json::CharReaderBuilder builder;
        const auto rawJsonLength = static_cast<int>(readBuffer.length());
        JSONCPP_STRING err;

        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        if (!reader->parse(readBuffer.c_str(), readBuffer.c_str() + rawJsonLength, &data,
            &err)) {
            std::cout << "error" << std::endl;
        }

        const Json::Value& questionsJson = data;
        cout << data["results"];
    }
    else {
        cerr << "Could not fetch questions, check internet connection and try again\n";
        exit(1);
    }
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}