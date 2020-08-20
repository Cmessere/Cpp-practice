#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <json/json.h> 
#include <tuple>

#pragma warning(disable  : 4996)

using namespace std;

void parseJson(vector<tuple< string, double, int >>& productsList);
void getInputFromCustomer(const string& question, string& choice);

int main()
{
    vector<tuple< string, double, int >> productsList;
    string choice;

    parseJson(productsList);
    while (true) {
        getInputFromCustomer("What would you like to purchase? ", choice);
        std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });
        bool found = false;

        for (auto p : productsList) {
            string temp = get<0>(p);
            
            std::for_each(temp.begin(), temp.end(), [](char& c) {c = ::toupper(c); });
            
            if (temp == choice) {
                found = true;
                cout << "Price: " << get<1>(p) <<endl;
                cout << "Quantity: " << get<2>(p) <<endl;
                break;
            }
            
        }
        if (!found) {
            cout << "Sorry, that product was not found in our inventory." << endl;
        }
    }
}

void parseJson(vector<tuple< string, double, int >>& productsList) 
{
    ifstream productsFile;

    productsFile.open("products.json");

    Json::Reader reader;
    Json::Value data;

    reader.parse(productsFile, data);
    const Json::Value& products = data["products"];

    for (auto const& id : products) {
        tuple<string, double, int> tupleProduct;


        get<0>(tupleProduct) = id["name"].asString();
        get<1>(tupleProduct) = id["price"].asDouble();
        get<2>(tupleProduct) = id["quantity"].asInt();

        productsList.push_back(tupleProduct);
    }
}

void getInputFromCustomer(const string& question, string& choice) {

    cout << question;
    cin >> choice;

}