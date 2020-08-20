#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <json/json.h> 
#include <tuple>
#include<json/writer.h>

#pragma warning(disable  : 4996)

using namespace std;

void parseJson(vector<tuple< string, double, int >>& productsList);
void getInputFromCustomer(const string& question, string& choice);
void askToAddProduct(const string& question, bool &flag);
void addProduct(string& choice, vector<tuple<string, double, int>> &productsList);
void addProductToJson(std::string& choice, double price, int quantity);
void createNewProductToAdd(std::string& choice, double price, int quantity, std::vector<std::tuple<std::string, double, int>>& productsList);
void askPrice(double& price);
void askQuantity(int& quantity);

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

            bool addFlag = false;
            askToAddProduct("Would you like to add it? (Y/N)", addFlag);

            if (addFlag) {
                addProduct(choice, productsList);
            }
        }
    }
}

void addProduct(string& choice, vector<tuple<string,double,int>> &productsList) {

    double price;
    int quantity;
    std::for_each(choice.begin()+1, choice.end(), [](char& c) {c = ::tolower(c); });

    askPrice(price);
    askQuantity(quantity);

    createNewProductToAdd(choice, price, quantity, productsList);

    addProductToJson(choice, price, quantity);
    cout << "'" << choice << "' has been added to the product list!" << endl;
}

void addProductToJson(std::string& choice, double price, int quantity)
{
    ifstream productsFile;

    productsFile.open("products.json");

    Json::Reader reader;
    Json::Value data;

    reader.parse(productsFile, data);
    Json::Value& products = data["products"];
    Json::Value dataArray(Json::arrayValue);
    Json::Value newProductJson;

    for (auto const& id : products) {
        Json::Value vec;
        vec["name"] = id["name"];
        vec["price"] = id["price"];
        vec["quantity"] = id["quantity"];

        dataArray.append(vec);
    }

    std::ofstream file_id;
    file_id.open("products.json");

    Json::Value value_obj;
    value_obj["name"] = choice;
    value_obj["price"] = price;
    value_obj["quantity"] = quantity;

    dataArray.append(value_obj);

    newProductJson["products"] = dataArray;
    Json::StyledWriter styledWriter;
    file_id << styledWriter.write(newProductJson);

    file_id.close();
}

void createNewProductToAdd(std::string& choice, double price, int quantity, std::vector<std::tuple<std::string, double, int>>& productsList)
{
    tuple<string, double, int> tupleProduct;

    get<0>(tupleProduct) = choice;
    get<1>(tupleProduct) = price;
    get<2>(tupleProduct) = quantity;

    productsList.push_back(tupleProduct);
}

void askPrice(double& price)
{
    cout << "What is the price of the product? ";
    cin >> price;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> price;
    }
}

void askQuantity(int& quantity)
{
    cout << "What is the quantity of the product? ";
    cin >> quantity;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> quantity;
    }
}

void askToAddProduct(const string& question, bool &flag) {
    string input;
    
    cout << question;
    cin >> input;

    std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });

    while (input != "Y" && input != "N") {
        cout << "Sorry, not a valid option. Please try again: ";
        cin >> input;

        std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });
    }

    input == "Y" ? flag = true : flag = false;
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
    productsFile.close();

}

void getInputFromCustomer(const string& question, string& choice) {

    cout << question;
    getline(cin ,choice);

}