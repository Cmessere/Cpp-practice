#include <iostream>
#include <string>

using namespace std;

void askText(string const prompt, string* const value);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main()
{
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";

    string name, *namePtr = &name;
    string noun, *nounPtr = &noun;
    string bodyPart, *bodyPartPtr = &bodyPart;
    string verb, *verbPtr = &verb;


    askText("Please enter a name: ", namePtr);
    askText("Please enter a plural noun: ", nounPtr);
    int number = askNumber("Please enter a number: ");
    askText("Please enter a body part: ", bodyPartPtr);
    askText("Please enter a verb: ", verbPtr);

    tellStory(name, noun, number, bodyPart, verb);

    return 0;
}

void askText(string const prompt, string* const value)
{
    string text;
    cout << prompt;
    cin >> *value;
}

int askNumber(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
    cout << "\nHere's your story:\n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " when one day, the ";
    cout << noun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << number;
    cout << " " << noun;
    cout << ", a tear came to ";
    cout << name << "'s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.";
}

