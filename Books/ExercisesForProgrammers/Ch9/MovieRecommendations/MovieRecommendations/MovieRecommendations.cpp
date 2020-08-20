#include <iostream>
#include <curl/curl.h>
#include <json/json.h> 

using namespace std;

void getCityFromUser(string & movie);
void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string& movie);
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
void parseJson(const CURLcode& res, const string& readBuffer, string& description);

int main()
{
    string description, movie;
    CURLcode res;
    string readBuffer;
    CURL* curl;
    curl = curl_easy_init();
   
    getCityFromUser(movie);
    fetchData(curl, readBuffer, res, movie);
    parseJson(res, readBuffer, description);

    cout << description;
}

void getCityFromUser(string& movie) {
    cout << "Insert movie name: ";
    getline(cin, movie);

    std::replace(movie.begin(), movie.end(), ' ', '+'); //replacing blanks with '+' for queryString
}

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string& movie)
{
    string baseUrl, apiKey, requestUrl;
    baseUrl = "http://www.omdbapi.com/?t=";
    apiKey = "&apikey=7625da83&";


    requestUrl = baseUrl + movie + apiKey;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, requestUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void parseJson(const CURLcode& res, const string& readBuffer, string& description) {
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

        const Json::Value& movieJson = data;

        description += "Title: " + data["Title"].asString() + "\n";
        description += "Year: " + data["Year"].asString() + "\n";
        description += "Rated: " + data["Rated"].asString() + "\n";
        description += "Runtime: " + data["Runtime"].asString() + "\n\n";
        description += "Plot: " + data["Plot"].asString() + "\n";

        if (stoi(data["Metascore"].asString()) > 75)
            description += "You should watch this movie!";
    }
    else {
        cout << "Movie not found!";
        exit(0);
    }
}