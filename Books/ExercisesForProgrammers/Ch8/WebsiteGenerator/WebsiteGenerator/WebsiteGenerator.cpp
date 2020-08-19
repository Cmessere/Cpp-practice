#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include<direct.h>
#include <filesystem>
#include <fstream>  

using namespace std;

void getString(const string& question, string& input);
void getBool(const string& question, bool& flag);
void createFolder(const string& name, const string& author, const bool& jsFlag, const bool& cssFlag);
void getCurrentDirectory(string& path);

void createIndexHTML(std::string& path, const std::string& author, const std::string& name);
void createSubfolder(std::string& subFolderPath, std::string& path);

void getString(const string& question, string& input) {
    cout << question;
    cin >> input;
}

void getBool(const string& question, bool& flag) {
    string input;

    cout << question;
    cin >> input;

    std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });

    while (input != "Y" && input != "N") {
        cout << "Sorry, option not recognized. Please try again ";
        cin >> input;

        std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });
    }

    input == "Y" ? flag = true : flag = false;
}

void getCurrentDirectory(string& path) {
    char buff[FILENAME_MAX];
    _getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    path = current_working_dir;
}


void createFolder(const string& name, const string& author, const bool& jsFlag, const bool& cssFlag) {
    
    string path, subFolderPath;
    getCurrentDirectory(path);

    path += "\\" + name;

    auto root = _mkdir(path.c_str());

    if (jsFlag) {
        subFolderPath = path + "\\js";
        createSubfolder(subFolderPath, path);
    }
    if (cssFlag) {
        subFolderPath = path + "\\css";
        createSubfolder(subFolderPath, path);
    }

    createIndexHTML(path, author, name);
    
}

void createIndexHTML(std::string& path, const std::string& author, const std::string& name)
{
    path += "\\index.html";
    ofstream file(path);
    string meta = "<meta>" + author + "<meta>";
    string title = "<title>" + name + "<\\title>";
    file << meta << endl << title << endl;
}

void createSubfolder(std::string& subFolderPath, std::string& path)
{
    _mkdir(subFolderPath.c_str());
}

int main()
{
    string name, author;
    bool jsFlag, cssFlag;

    getString("Enter site name: ", name);
    getString("Enter author name: ", author);
    getBool("Do you want a Javascript folder (Y/N)? ", jsFlag);
    getBool("Do you want a CSS folder (Y/N)? ", cssFlag);

    createFolder(name, author, jsFlag, cssFlag);
}