#include <iostream>
#include <vector>
using namespace std;

void initializeQuestions(vector<string>& q) {
    q.push_back("Enter a verb :");
    q.push_back("Enter a noun :");
    q.push_back("Enter a adjective :");
    q.push_back("Enter another adjective :");
    q.push_back("Enter an adverb :");
    q.push_back("Enter another adverb :");
    q.push_back("Enter a number :");
}

void askForWords(vector<string>& questions, vector<string>& words) {
    string temp;

    for (auto c : questions) {
        cout << c << endl;
        cin >> temp;
        words.push_back(temp);
     }
}

void generatePhraseOne( const vector<string>& words) {
    cout << "Do you " << words[0] << " your " << words[1] << " " << words[2] << " " << words[3] << " and " << words[4] << "? That's " << words[5] << " hilarious!" << endl;

}

void generatePhraseTwo(const vector<string>& words) {
    cout << "Hey were you " << words[0] << " before? was it because of that " << words[3] << " " << words[2] << " " << words[1] << "? It's " << words[4] <<  " hard to " << words[5] << " know." << endl;
}

int main()
{
    vector<string> words, questions;
    string input;
    
    initializeQuestions(questions);
    askForWords(questions, words);
    words[6].size() % 2 == 0? generatePhraseOne(words) : generatePhraseTwo(words);

}