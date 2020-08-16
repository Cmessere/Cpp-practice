#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "CurrencyConverter.h"

using namespace std;

void initializeRates(map<string, double>& rates) {
    rates["GBP"] = 1.308527;
    rates["USD"] = 1;
    rates["EUR"] = 1.184204;
    rates["AUD"] = 0.717205;
    rates["CAN"] = 0.753668;
    rates["JPY"] = 0.009384;
    rates["CNY"] = 0.143871;
}

void initializeCountries( map<string, string> &currencies) {
    currencies["UK"] = "GBP";
    currencies["US"] = "USD";
    currencies["CA"] = "CAN";
    currencies["AU"] = "AUD";
    currencies["IT"] = "EUR";
    currencies["FR"] = "EUR";
    currencies["DE"] = "EUR";
    currencies["JP"] = "JPY";
    currencies["CH"] = "CNY";
}

int main()
{
    map<string, string> currencies;
    map<string, double> rates;
    string inputCountry;
    double quantity;

    initializeCountries(currencies);
    initializeRates(rates);

    getInputCountry(inputCountry, currencies);

    cout << inputCountry << " currency is the " << currencies[inputCountry] << endl;

    getExchangeQuantity(quantity);

    string selectedCurrency = currencies[inputCountry];
    double exchangeRate = rates[selectedCurrency];

    outputEchangeValue(quantity, selectedCurrency, exchangeRate);
}

void getExchangeQuantity(double& quantity)
{
    cout << "How much are you exchanging? ";
    cin >> quantity;
}

void outputEchangeValue(double quantity, std::string& selectedCurrency, double exchangeRate)
{
    cout.precision(5);
    cout << quantity << " " << selectedCurrency << " at an exchange rate of " << exchangeRate << " is " <<
        quantity * exchangeRate << " dollars.\n";
}

void getInputCountry(std::string& inputCountry, std::map<std::string, std::string>& currencies)
{
    cout << "Insert the country for the exchange rate( ex UK, US, or IT): ";
    cin >> inputCountry;

    std::for_each(inputCountry.begin(), inputCountry.end(), [](char& c) {c = ::toupper(c); });

    while (!currencies.count(inputCountry))
    {
        cout << "Sorry the inserted code is invalid or not implemented, please try again.\n";
        cin >> inputCountry;
    }
}