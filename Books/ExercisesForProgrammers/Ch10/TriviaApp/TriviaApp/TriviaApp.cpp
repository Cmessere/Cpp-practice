#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include <json/json.h> 

using namespace std;

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string &category, const string & numberOfQuestions);
void parseJson(const CURLcode& res, const string& readBuffer, vector < tuple<string, vector<string>>>& trivia);
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
void askQuestion(vector < tuple<string, vector<string>>> &trivia);
void initializeCategories(map<string, int> &categoriesCodes);
void getCategory( map<string, int>& categoriesCodes, string & category);
void getNumberOfQuestions(string &numberOfQuestions);

int main()
{
    vector < tuple<string, vector<string>>> trivia;
    map<string, int> categoriesCodes;
    CURLcode res;
    string readBuffer, category, numberOfQuestions;
    CURL* curl;
    curl = curl_easy_init();

    initializeCategories(categoriesCodes);
    getCategory(categoriesCodes, category);
    getNumberOfQuestions(numberOfQuestions);
    fetchData(curl, readBuffer, res, category, numberOfQuestions);
    parseJson(res, readBuffer, trivia);
    askQuestion(trivia);
}

void getPossibleCategories(const map<string, int>& categoriesCodes, vector<string>& possibleCategories) {
    for (auto c : categoriesCodes) {
        possibleCategories.push_back(c.first);
    }
}
void getNumberOfQuestions(string& numberOfQuestions){
    int num;

    cout << "How many questions do you want [10 - 50]? ";
    cin >> num;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> num;
    }

    if (num < 10)
        numberOfQuestions = to_string(10);
    else if(num > 50)
        numberOfQuestions = to_string(50);
    else
        numberOfQuestions = to_string(num);
}


void getCategory( map<string, int>& categoriesCodes, string& category) {
    string input;
    vector<string> possibleCategories;
    getPossibleCategories(categoriesCodes, possibleCategories);
    bool selected = false;

    cout << "Which category of questions would you like ('list' for help)? " << endl;
    getline(cin , input);

    while (1) {
        if (input == "list") {
            for (auto c : possibleCategories) {
                cout << c << endl;
            }
        }
        else {
            selected = (find(possibleCategories.begin(), possibleCategories.end(), input)) != possibleCategories.end();
            if (selected) {
                break;
            }
            else {
                cout << "Sorry, not a valid option, try again: " << endl;
                getline(cin, input);
            }
        }
        getline(cin, input);       
    }

    category = to_string(categoriesCodes[input]);
}

void initializeCategories(map<string, int>& categoriesCodes) {
    categoriesCodes["generalculture"] = 9;
    categoriesCodes["books"] = 10;
    categoriesCodes["movies"] = 11;
    categoriesCodes["music"] = 12;
    categoriesCodes["musicals&theater"] = 13;
    categoriesCodes["television"] = 14;
    categoriesCodes["games"] = 15;
    categoriesCodes["boardgames"] = 16;
    categoriesCodes["nature"] = 17;
    categoriesCodes["computers"] = 18;
    categoriesCodes["math"] = 19;
    categoriesCodes["mythology"] = 20;
    categoriesCodes["sports"] = 21;
    categoriesCodes["geography"] = 22;
    categoriesCodes["history"] = 23;
    categoriesCodes["politics"] = 24;
    categoriesCodes["art"] = 25;
    categoriesCodes["celebtrities"] = 26;
    categoriesCodes["animals"] = 27;
    categoriesCodes["vehicles"] = 28;
    categoriesCodes["comics"] = 29;
    categoriesCodes["gadgets"] = 30;
    categoriesCodes["manga&anime"] = 31;
    categoriesCodes["cartoons&animations"] = 32;
}

void askQuestion(vector < tuple<string, vector<string>>>& trivia) {
    int score = 0, correctIndex, userAnswer;
    string correctAnswer;
    vector<string> possibleAnswers;

    for (auto q : trivia) {
        possibleAnswers = get<1>(q);
        correctAnswer = possibleAnswers[0];

        std::random_shuffle(possibleAnswers.begin(), possibleAnswers.end());

        auto it = (find(possibleAnswers.begin(), possibleAnswers.end(), correctAnswer));
        correctIndex = std::distance(possibleAnswers.begin(), it);

        cout << get<0>(q) << endl;
        for (int i = 0; i < possibleAnswers.size(); i++) {
            cout << i + 1 << ") " << possibleAnswers[i] << endl;
        }

        cin >> userAnswer;

        if (correctIndex == userAnswer-1) {
            cout << "That is correct! Good job!" << endl;
            score++;
        }
        else {
            cout << "That is not correct unfortunately." << endl;
            cout << "The correct answer was number " << correctIndex+1 << endl;
        }

        cout << "Next question!\n\n";
    }

}

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res, const string& category, const string& numberOfQuestions)
{
    string baseUrl = "https://opentdb.com/api.php?", amount = "amount=" + numberOfQuestions;
    string categoryQuery = "&category=" + category, type = "&type=multiple", url;

    url = baseUrl + amount + categoryQuery + type;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

void parseJson(const CURLcode& res, const string& readBuffer, vector < tuple<string, vector<string>>>&trivia)
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

        const Json::Value& questionsJson = data["results"];

        for (auto question : questionsJson) {
            vector<string> answers;
            tuple<string, vector<string>> triviaTuple;

            answers.push_back(question["correct_answer"].asString());

            for (auto a : question["incorrect_answers"]) {
                answers.push_back(a.asString());
            }

            get<0>(triviaTuple) = question["question"].asString();
            get<1>(triviaTuple) = answers;

            trivia.push_back(triviaTuple);
        }
    }
    else {
        cerr << "Could not fetch questions, check internet connection and try again\n";
        exit(1);
    }
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}