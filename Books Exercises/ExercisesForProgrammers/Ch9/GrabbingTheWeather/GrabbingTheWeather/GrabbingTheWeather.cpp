#include <iostream>
#include <iomanip>
#include <curl/curl.h>
#include <json/json.h> 
#include <map>
#include <string>
#include <algorithm>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string& city);
void parseJson(const CURLcode& res, const string& readBuffer, string &weather);
void addCustomMessage(double fDegree, Json::Value& data, std::string& weather, double cDegree);
void getSunriseAndSunset(Json::Value& data, std::string& weather);
void getWindDirection(Json::Value& data, std::string& weather);
void getTemperature(double& cDegree, double kelvinTemperature, double& fDegree, std::string& weather);
void getWeatherAndHumidity(std::string& weather, const Json::Value& weatherJson, Json::Value& data);
void getCityFromUser(string &city);

int main()
{
    string weather, city, sunriseTime, sunsetTime;
    CURLcode res;
    string readBuffer;
    CURL* curl;
    curl = curl_easy_init();
   
    getCityFromUser(city);
    fetchData(curl, readBuffer, res, city);
    parseJson(res, readBuffer, weather);

    cout << weather << endl;
}

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string &city)
{
    string baseUrl, apiKey, requestUrl;
    baseUrl = "api.openweathermap.org/data/2.5/weather?q=";
    apiKey = "&appid=6898878055e725e63cf04ef3659a9df6";

    requestUrl = baseUrl + city + apiKey;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, requestUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

void getCityFromUser(string& city) {
    cout << "Insert city to check: ";
    getline(cin , city);
}

void parseJson(const CURLcode& res, const string& readBuffer, string& weather)
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

        const Json::Value& weatherJson = data["weather"];

        getWeatherAndHumidity(weather, weatherJson, data);

        double kelvinTemperature = data["main"]["temp_max"].asDouble(), cDegree, fDegree;

        getTemperature(cDegree, kelvinTemperature, fDegree, weather);
        getWindDirection(data, weather);
        getSunriseAndSunset(data, weather);
        addCustomMessage(fDegree, data, weather, cDegree);

    }
    else {
        cerr << "Could not fetch exchange rates, check internet connection and try again\n";
        exit(1);
    }
}

void addCustomMessage(double fDegree, Json::Value& data, std::string& weather, double cDegree)
{
    if (fDegree > 70 && data["weather"][0]["main"].asString() == "Clear") {
        weather += "It is a nice day out!\n";
    }
    else if (cDegree < 15 && data["weather"][0]["main"].asString() == "Cloudy") {
        weather += "You will need a coat\n";
    }
    else if (data["weather"][0]["main"].asString() == "Rain") {
        weather += "Don't forget your umbrella!\n";
    }
}

void getSunriseAndSunset(Json::Value& data, std::string& weather)
{
    uint32_t sunrise, sunset;
    string sunriseTime, sunsetTime;

    const Json::Value& sunriseJson = data["sys"];

    sunrise = sunriseJson["sunrise"].asUInt();
    sunset = sunriseJson["sunset"].asUInt();

    time_t a = sunrise;
    sunriseTime = ctime(&a);

    weather += "The sun rised : " + sunriseTime;

    a = sunset;
    sunsetTime = ctime(&a);

    weather += "The sun will set : " + sunsetTime + "\n";
}

void getWindDirection(Json::Value& data, std::string& weather)
{
    int windDegree = data["wind"]["deg"].asInt();

    if (windDegree >= 0 && windDegree < 90) {
        weather += "There are winds blowing North\n";
    }
    else if (windDegree >= 90 && windDegree < 180) {
        weather += "There are winds blowing East\n";
    }
    else if (windDegree >= 180 && windDegree < 270) {
        weather += "There are winds blowing South\n";
    }
    else {
        weather += "There are winds blowing West\n";
    }
}

void getTemperature(double& cDegree, double kelvinTemperature, double& fDegree, std::string& weather)
{
    cDegree = kelvinTemperature - 273.15;
    fDegree = (kelvinTemperature - 273.15) * 9 / 5 + 32;

    weather += "The temperature is " + to_string(cDegree) + " Celsius degrees or " + to_string(fDegree) + " Fahrenheits\n";
}

void getWeatherAndHumidity(std::string& weather, const Json::Value& weatherJson, Json::Value& data)
{
    weather += weatherJson[0]["description"].asString();
    weather += ", with a humidity of " + data["main"]["humidity"].asString() + "%\n";
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}