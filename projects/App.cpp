#include "bits/stdc++.h"
using namespace std;

vector<vector<string>> database;
// vector<string> userName;
bool alreadyTaken(string username)
{
    int n = database.size();
    for (int i = 0; i < n; i++)
    {
        if (username == database[i][2])
        {
            return true;
        }
    }
    return false;
}
void register_(string email, string name, string username, string password)
{
    if (alreadyTaken(username))
    {
        cout << "Username already taken " << endl;
        return;
    }
    else
    {
        vector<string> temp(4, "");
        temp.push_back(email);
        temp.push_back(name);
        temp.push_back(username);
        temp.push_back(password);
        database.push_back(temp);
        cout << "Register Sucessfully" << endl;
    }
}

void Login(string username, string password)
{
    int n = database.size();
    for (int i = 0; i < n; i++)
    {
        if (username == database[i][2] && password == database[i][3])
        {
            cout << "Login successful" << endl;
            return;
        }
    }
    cout << "Wrong username or Password" << endl;
}

int main()
{
    cout << "You want to Register or login ? " << endl;
    string output;
    getline(cin, output);

    if (output == "Register")
    {
        // regester process
        cout << "Enter your Email : ";
        string email;
        getline(cin, email);

        cout << "Enter your Name : ";
        string name;
        getline(cin, name);

        cout << "Enter your username : ";
        string username;
        getline(cin, username);

        cout << "Enter your password : ";
        string password;
        getline(cin, password);

        register_(email, name, username, password);
    }
    else if (output == "Login")
    {
        // login process
        cout << "Enter your username : ";
        string username;
        getline(cin, username);

        cout << "Enter your password : ";
        string password;
        getline(cin, password);

        Login(username, password);
    }
    else
    {
        // invalid output
        cout << "invalid output" << endl;
    }

    return 0;
}