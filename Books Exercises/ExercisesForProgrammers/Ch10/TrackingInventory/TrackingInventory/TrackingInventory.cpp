#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <json/json.h> 
#include<json/writer.h>

#pragma warning(disable  : 4996)

using namespace std;

void parseJson(vector<tuple< string, string, double >>& productsList);
void askForDelimiter(string &delimiter);
void outputCsv(const vector<tuple< string, string, double >>& productsList,const string& delimiter);
void outputHTML(const vector<tuple< string, string, double >>& productsList, const string& delimiter);

int main()
{
    vector<tuple< string, string, double >> productsList;
    string choice, delimiter;

    askForDelimiter(delimiter);
    parseJson(productsList);
    outputCsv(productsList, delimiter);
    outputHTML(productsList, delimiter);
}

void askForDelimiter(string& delimiter) {
    string input;
    cout << "Due to localization problems, insert your csv delimiter (',' or ';'): ";
    cin >> input;

    while (input != "," && input != ";") {
        cout << "That is not a valid option, please try again.";
        cin >> input;
    }

    delimiter = input;
}

void parseJson(vector<tuple< string, string, double >>& productsList) {
    ifstream productsFile;

    productsFile.open("products.json");

    Json::Reader reader;
    Json::Value data;

    reader.parse(productsFile, data);
    const Json::Value& products = data["products"];

    for (auto const& id : products) {
        tuple<string, string, double> tupleProduct;

        get<0>(tupleProduct) = id["name"].asString();
        get<1>(tupleProduct) = id["serial"].asString();
        get<2>(tupleProduct) = id["price"].asDouble();

        productsList.push_back(tupleProduct);
    }
    productsFile.close();
}

void outputCsv(const vector<tuple< string, string, double >>& productsList, const string& delimiter) {
    std::ofstream myfile;
    myfile.open("products.csv");
    myfile << "Name"<< delimiter<< "Serial"<< delimiter<<"Price\n";

    for (auto p : productsList) {
        myfile << get<0>(p) << delimiter << get<1>(p) << delimiter << "$" << get<2>(p) << endl;
    }

    myfile.close();
}

void outputHTML(const vector<tuple< string, string, double >>& productsList, const string& delimiter) {
    std::ofstream myfile;
    myfile.open("products.html");

    myfile << "<table style=\"width:50vw\">";
    myfile << "<tr><th>Name</th><th>Serial</th><th>Price</th></tr>";

    for (auto p : productsList) {
        myfile << "<tr>" << "<th>" << get<0>(p) << "</th><th>" << get<1>(p) <<"</th><th>$" << get<2>(p) << "</th></tr>";
    }
    myfile << "</table>";

    myfile.close();
}