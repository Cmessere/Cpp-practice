#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getChore(const string& question, vector<string>& todos);
void printTodos(const vector<string>& todos);
void removeChore(vector<string>& todos);
void addOtherTasks(std::vector<std::string>& todos, std::string& task);

int main()
{
    vector<string> todos;
    getChore("Insert a chore/activity (blank to stop): ", todos);
    removeChore(todos);
}

void getChore(const string& question, vector<string>& todos) {
    string task="-1";

    while (true) {
        cout << question;
        getline(cin, task);

        if (task == "")
            break;

        todos.push_back(task);
    }
    printTodos(todos);
}

void printTodos(const vector<string>& todos) {
    for (auto t : todos) {
        cout << t << endl;
    }
}

void removeChore(vector<string>& todos) {
    string task;

    while (todos.size() > 0) {
        cout << "Enter task to remove (type 'add' resume adding tasks): ";
        getline(cin,task);

        if(task == "add"){
            addOtherTasks(todos, task);
        }

        auto it = std::find(todos.begin(), todos.end(), task);

        if (it != todos.end())
        {
            todos.erase(it);
        }
        else {
            cout << "There is no task with that name!" << endl;
        }
        printTodos(todos);
    }
    
    cout << "You've completed your todo list!";
}

void addOtherTasks(std::vector<std::string>& todos, std::string& task)
{
    getChore("Insert a chore/activity (blank to stop): ", todos);
    cin.clear();
    cout << "Enter task to remove (type 'add' resume adding tasks): ";
    getline(cin, task);
}