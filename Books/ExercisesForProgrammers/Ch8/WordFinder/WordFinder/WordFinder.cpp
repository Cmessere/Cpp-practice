#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool replace(string& str, const string& from, const string& to);


int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string input, outputFileName;

    inputFile.open("input.txt");

    cout << "What is the name of the output file? ";
    cin >> outputFileName;

    outputFileName += ".txt";
    outputFile.open(outputFileName);

    while (getline(inputFile, input)) {
        replace(input, "utilize", "use");

        outputFile << input << endl;
    }

}

bool replace(string& str, const string& toReplace, const string& newSubstr) {

    size_t position = str.find(toReplace);

    if (position == string::npos)
        return false;

    str.replace(position, toReplace.length(), newSubstr);
    return true;
}