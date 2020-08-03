#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
struct Quote
{
    string author;
    string phrase;
};

enum options {
    tell,
    hear,
    all,
    stop
};

options StringToEnum( const string s)
{
    static map<string, options> string2Enum{
       { "tell", tell },
       { "hear", hear },
       { "all", all },
       { "stop", stop }
    };

    auto x = string2Enum.find(s);
    if (x != end(string2Enum)) {
        return x->second;
    }
    throw std::invalid_argument("s");
}


void tellQuote(map<short, Quote*>&quotes, short &learnedQuotes)
{
    string quote, author;

    cout << "Tell me a quote!" <<endl;
    cin >> quote;
    cout << "Oh, interesting, and who said that?\n";
    cin >> author;

    Quote* newQuote = new Quote();

    newQuote->author = author;
    newQuote->phrase = quote;

    quotes.insert({ learnedQuotes, newQuote });
    learnedQuotes++;
    cout << "I now know " << learnedQuotes << " quotes."<< endl;
}

void hearQuote(const map<short, Quote*>& quotes, const short &learnedQuotes)
{
    if(learnedQuotes <= 0)
    {
        cout << "Oh bummer, I do not know any quote at the moment...\n";
        return;
    }

    short quoteIndex;
    cout << "So you want to hear a quote eh?\nWell I've got " << learnedQuotes<< " of them, which one do you want to hear?\n" << endl;
    cin >> quoteIndex;

    Quote* quoteToHear = quotes.at(learnedQuotes - 1);
    cout << "Ok, here it is...\n" << quoteToHear->author << " says, \"" << quoteToHear->phrase << "\"\n";
}

void stayAWhileAndListen(const map<short, Quote*>& quotes, const short &learnedQuotes)
{
    if (learnedQuotes <= 0)
    {
        cout << "Well...I guess I got nothing more to tell you.\n";
        return;
    }

    cout << "Stay a while and listen\nI've got " << learnedQuotes  << " quotes to tell you!\n";
    for(short i = 0; i < learnedQuotes; i++)
    {
        Quote* quoteToHear = quotes.at(i);
        cout << quoteToHear->author << " says, \"" << quoteToHear->phrase << "\"\n\n";
    }
}

void clearMemory(const map<short, Quote*>& quotes, const short& learnedQuotes) 
{
    cout << "Cleaning before exiting." << endl;

    for (short i = 0; i < learnedQuotes; i++)
    {
        Quote* quoteToHear = quotes.at(i);
        delete quoteToHear;
    }
}

int main()
{
    map<short, Quote*> QuoteMap;
    auto going = true;
    short learnedQuotes = 0;

    while(going)
    {
        string choice;

	    cout << "Would you like to \"tell\" me a quote, or do you want to \"Hear\" one from me?\n";
        cout << "Maybe you'd like to hear them \"All\"?\n";
        cout << "If you want to stop just tell me to.\n";
        cin >> choice;

        for (auto& c : choice)
        {
            c = tolower(c);
        }
        options o = StringToEnum(choice);

        switch(o)
        {
			case 0:
                tellQuote(QuoteMap, learnedQuotes);
                break;
            case 1:
                hearQuote(QuoteMap, learnedQuotes);
                break;
            case 2:
                stayAWhileAndListen(QuoteMap, learnedQuotes);
                break;
            case 3:
                going = false;
                clearMemory(QuoteMap, learnedQuotes);
                break;
            default:
                clearMemory(QuoteMap, learnedQuotes);
                going = false;
                break;
        }
    }
}
