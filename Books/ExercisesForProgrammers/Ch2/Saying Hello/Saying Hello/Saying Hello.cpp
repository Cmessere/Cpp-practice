#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void politeGreeting() {
    cout << "Hey, what's your name?" << endl;
    cout << "Hello " << *istream_iterator<string>(cin) << ", what's up?" << endl;
}

void rudeGreeting() {
    cout << "Who the hell are you!?" << endl;
    cout << "Get lost " << *istream_iterator<string>(cin) << ", you're not allowed here!" << endl;
}

void formalGreeting() {
    cout << "Excuse me, may I ask your name?" << endl;
    cout << *istream_iterator<string>(cin) << "? What a lovely name, I am very pleased to meet you." << endl;
}

void veryInformalGreeting() {
    cout << "Yo dude, what's your name-o?" << endl;
    cout << "DUUUUUUDE, "<< *istream_iterator<string>(cin) << "? that's such a cool name!" << endl;
}

void passiveAggressiveGreeting() {
    cout << "And you are?" << endl;
    cout << "Mh, ok, nice to meet you and all " << *istream_iterator<string>(cin) << ", now move along." << endl;
}

void thirdKindGreeting() {
    cout << "9R3371N9 H00M4N,73LL 1D3N71FY1N9 N0UN?" << endl;
    cout << *istream_iterator<string>(cin) << "? S7R4N93 W4Y T0 SP34K" << endl;
}

int main()
{
    default_random_engine generator;
    generator.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<unsigned short> distribution(1, 6);
    unsigned short randomPrompt = distribution(generator);

    switch (randomPrompt) {
        case 1:
            politeGreeting();
            break;
        case 2:
            rudeGreeting();
            break;
        case 3:
            formalGreeting();
            break;
        case 4:
            veryInformalGreeting();
            break;
        case 5:
            passiveAggressiveGreeting();
            break;
        case 6:
            thirdKindGreeting();
            break;
        default:
            break;
    }

    return 0;
}

