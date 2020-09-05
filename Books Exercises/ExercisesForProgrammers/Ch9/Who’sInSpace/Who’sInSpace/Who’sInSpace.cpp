#include <iostream>
#include <iomanip>
#include <curl/curl.h>
#include <json/json.h> 
#include <map>
#include <string>
#include <algorithm>

using namespace std;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
void fetchSpacePeople(CURLcode &res, string &readBuffer);
void printOutput(const map<string,string> &astronauts);
void parseJson(const CURLcode& res,const string& readBuffer, map<string, string>& astronauts);

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res);

int main()
{
    map<string, string> astronauts;
    CURLcode res;
    string readBuffer;
    CURL* curl;
    curl = curl_easy_init();

    fetchData(curl, readBuffer, res);
    parseJson(res, readBuffer, astronauts);
    printOutput(astronauts);
}

void printOutput(const map<string, string> &astronauts) {
    typedef pair<string, string> pair;
    vector<pair> sortedAstronauts;

    copy(astronauts.begin(), astronauts.end(), back_inserter<std::vector<pair>>(sortedAstronauts));

    std::sort(sortedAstronauts.begin(), sortedAstronauts.end(), [](const pair& l, const pair& r) {
        return l.first < r.first;
        });

    cout << setw(22) << right << "Name " << setw(20) << "Craft " << endl;
    for (auto a : sortedAstronauts) {
        cout << setw(20) << right << a.first << setw(20) << a.second << endl;
    }
}

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res)
{
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://api.open-notify.org/astros.json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

void parseJson(const CURLcode& res, const string& readBuffer, map<string, string>& astronauts)
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

        const Json::Value& ratesJson = data["people"];

        for (auto const& id : ratesJson) {
            astronauts[id["name"].asString()] = id["craft"].asString();
        }
    }
    else {
        cerr << "Could not fetch exchange rates, check internet connection and try again\n";
        exit(1);
    }
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}