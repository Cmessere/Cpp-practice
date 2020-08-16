#include <vector>

void getInputCountry(std::string& inputCountry, std::map<std::string, std::string>& currencies, std::map<std::string, std::string>& countryList);

void inputToUpperCase(std::string& inputCountry);

void outputEchangeValue(double quantity, std::string& selectedCurrency, double exchangeRate);

void getExchangeQuantity(double& quantity);

int fetchExchangeRates(std::map<std::string, double>& ratesApi, bool& retflag);

void initializeCountries(std::map<std::string, std::string>& currencies);

void initializeCountries(std::map<std::string, std::string>& currencies)
{
    currencies["US"] = "USD";
    currencies["UK"] = "GBP";
    currencies["HK"] = "HDK";
    currencies["IS"] = "ISK";
    currencies["PH"] = "PHP";
    currencies["DK"] = "DKK";
    currencies["HU"] = "HUF";
    currencies["CZ"] = "CZK";
    currencies["RO"] = "RON";
    currencies["SE"] = "SEK";
    currencies["RI"] = "IDR";
    currencies["IN"] = "INR";
    currencies["BR"] = "BRL";
    currencies["RU"] = "RUB";
    currencies["HR"] = "HRK";
    currencies["MAL"] = "MYR";
    currencies["T"] = "THB";
    currencies["CH"] = "CHF";
    currencies["BG"] = "BGN";
    currencies["TR"] = "TRY";
    currencies["N"] = "NOK";
    currencies["NZ"] = "NZD";
    currencies["ZA"] = "ZAR";
    currencies["MX"] = "MXN";
    currencies["SG"] = "SGD";
    currencies["IL"] = "ILS";
    currencies["ROK"] = "KRW";
    currencies["PL"] = "PLN";
    currencies["CA"] = "CAN";
    currencies["AU"] = "AUD";

    currencies["IT"] = "EUR";
    currencies["FR"] = "EUR";
    currencies["DE"] = "EUR";
    currencies["E"] = "EUR";
    currencies["P"] = "EUR";
    currencies["A"] = "EUR";
    currencies["B"] = "EUR";
    currencies["CY"] = "EUR";
    currencies["EST"] = "EUR";
    currencies["FIN"] = "EUR";
    currencies["GR"] = "EUR";
    currencies["IRL"] = "EUR";
    currencies["LT"] = "EUR";
    currencies["LV"] = "EUR";
    currencies["L"] = "EUR";
    currencies["M"] = "EUR";
    currencies["NL"] = "EUR";
    currencies["SLO"] = "EUR";
    currencies["SK"] = "EUR";

    currencies["JP"] = "JPY";
    currencies["CH"] = "CNY";
}