//Critter Caretaker
//Simulates caring for a virtual pet

#include <iostream>
#include <vector>
using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Cheat();

private:
    int m_Hunger;
    int m_Boredom;

    vector<int> GetMood() const;
    void PassTime(int time = 1);

};

Critter::Critter(int hunger, int boredom) :
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

inline vector<int> Critter::GetMood() const
{
    vector<int> mood = { m_Hunger , m_Boredom };
    return mood;
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";

    vector<int> stats = GetMood();
    short hunger = stats[0], boredom = stats[1];
    short mood = hunger + boredom;

    if (mood > 15)
    {
        
        cout << "mad.\n";
        if (hunger > 7)
            cout << "I am  VERY hungry!\n";
        if (boredom > 7)
            cout << "I am  VERY bored!\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
        if (hunger > 5)
            cout << "I am hungry!\n";
        if (boredom > 5)
            cout << "I am bored!\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
        if (hunger > 2)
            cout << "I am slightly hungry!\n";
        if (boredom > 2)
            cout << "I am slightly bored!\n";
    }
    else
    {
        cout << "happy.\n";
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brruppp.\n";

    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}

void Critter::Cheat()
{
    cout << "Critter stats:\n";

    cout << "Hunger " << m_Hunger << endl;
    cout << "Boredom " << m_Boredom << endl;

}

int main()
{
    Critter crit;

    int choice = 1;  //start the critter off talking
    while (choice != 0)
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Good-bye.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 99:
            crit.Cheat();
            break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    }

    return 0;
}

