#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "CurrencyConverter.h"
#include <curl/curl.h>
#include <json/json.h> 

using namespace std;

int main()
{
    map<string, double> ratesApi;

    bool retflag;
    int retval = fetchExchangeRates(ratesApi, retflag);
    if (retflag) return retval;

    map<string, string> countryToCurrency;
    string inputCountry;
    double quantity;

    initializeCountries(countryToCurrency);

    getInputCountry(inputCountry, countryToCurrency, countryToCurrency);

    cout << inputCountry << " currency is the " << countryToCurrency[inputCountry] << endl;

    getExchangeQuantity(quantity);

    string selectedCurrency = countryToCurrency[inputCountry];
    double exchangeRate = ratesApi[selectedCurrency];

    outputEchangeValue(quantity, selectedCurrency, exchangeRate);
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


int fetchExchangeRates(std::map<std::string, double>& ratesApi, bool& retflag)
{
    retflag = true;
    CURL* curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.exchangeratesapi.io/latest?base=USD");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    if (res == CURLE_OK) {
        Json::Value root;
        Json::CharReaderBuilder builder;
        const auto rawJsonLength = static_cast<int>(readBuffer.length());
        JSONCPP_STRING err;

        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
        if (!reader->parse(readBuffer.c_str(), readBuffer.c_str() + rawJsonLength, &root,
            &err)) {
            std::cout << "error" << std::endl;
            return EXIT_FAILURE;
        }

        const Json::Value& ratesJson = root["rates"];

        for (auto const& id : ratesJson.getMemberNames()) {
            ratesApi[id] = ratesJson[id].asDouble();
        }
    }
    else {
        cerr << "Could not fetch exchange rates, check internet connection and try again\n";
        return 1;
    }

    retflag = false;
    return {};
}

void getExchangeQuantity(double& quantity)
{
    cout << "How much are you exchanging? ";
    cin >> quantity;
}

void outputEchangeValue(double quantity, std::string& selectedCurrency, double exchangeRate)
{
    cout.precision(2);
    cout << std::fixed;

    cout << quantity << " " << selectedCurrency << " at an exchange rate of " << exchangeRate << " is " <<
        quantity / exchangeRate << " dollars.\n";
}

void getInputCountry(std::string& inputCountry, std::map<std::string, std::string>& currencies, map<string, string> & countryToCurrency)
{
    cout << "Insert the country code for the exchange rate (write list for help): ";
    cin >> inputCountry;

    inputToUpperCase(inputCountry);

    
    while (!currencies.count(inputCountry))
    {
        if (inputCountry == "LIST") {
            for (map<string, string>::iterator it = countryToCurrency.begin(); it != countryToCurrency.end(); ++it) {
                cout << it->first << "\n";
            }
            cin >> inputCountry;
            inputToUpperCase(inputCountry);
        }
        else {
            cout << "Sorry the inserted code is invalid or not implemented, please try again.\n";
            cin >> inputCountry;
            inputToUpperCase(inputCountry);
        }
        
    }
}

void inputToUpperCase(std::string& inputCountry)
{
    std::for_each(inputCountry.begin(), inputCountry.end(), [](char& c) {c = ::toupper(c); });
}
