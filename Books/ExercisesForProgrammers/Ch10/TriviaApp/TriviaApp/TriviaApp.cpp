#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include <json/json.h> 

using namespace std;

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res);
void parseJson(const CURLcode& res, const string& readBuffer, vector < tuple<string, vector<string>>>& trivia);
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
void askQuestion(vector < tuple<string, vector<string>>> &trivia);

int main()
{
    vector < tuple<string, vector<string>>> trivia;
    CURLcode res;
    string readBuffer;
    CURL* curl;
    curl = curl_easy_init();

    fetchData(curl, readBuffer, res);
    parseJson(res, readBuffer, trivia);
    askQuestion(trivia);
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

void fetchData(CURL* curl, std::string& readBuffer, CURLcode& res)
{
    string baseUrl = "https://opentdb.com/api.php?amount=50&category=15&type=multiple";

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, baseUrl.c_str());
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