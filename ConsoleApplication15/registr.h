#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
using namespace std;

class Registr {
private:
    string result;
    int changeCount;
    vector<string> usernames;

public:
    Registr() : changeCount(2) {}

    string Name, LastName, UserName, FatherName, Address, Number, Password;

    void AppendToFile() {
        cout << "Registration" << endl;

        cout << "Name: ";
        getline(cin, Name);

        cout << "Last Name: ";
        getline(cin, LastName);

       
        do {
            cout << "Username: ";
            getline(cin, UserName);

         
            LoadUserNamesFromFile("user_data.txt");
            if (!IsUsernameUnique(UserName)) {
                cout << "This username is taken. Please enter a new username." << endl;
            }
        } while (!IsUsernameUnique(UserName));

      

        cout << "Father's Name: ";
        getline(cin, FatherName);

        cout << "Address: ";
        getline(cin, Address);

        do {
            cout << "Number (+994): ";
            getline(cin, Number);
            if (Number.length() != 9) {
                cout << "Error: The phone number must have exactly 9 digits." << endl;
            }
        } while (Number.length() != 9);

        cout << "Registration ";

     
        ofstream outFile("user_data.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Name: " << Name << endl;
            outFile << "Last Name: " << LastName << endl;
            outFile << "User Name: " << UserName << endl;
            outFile << "Father's Name: " << FatherName << endl;
            outFile << "Address: " << Address << endl;
            outFile << "Number: +994" << Number << endl;
            outFile << "-----------------------" << endl;

            outFile.close();
            cout << "Data saved successfully!" << endl;
            Sleep(1000);
            system("cls");
        }
        else {
            cout << "Error: Could not open the file." << endl;
        }
    }

    string GetUserName() {
        return UserName;
    }

    void LoadUserNamesFromFile(const string& filepath) {
        ifstream inFile(filepath);
        if (!inFile.is_open()) {
            cout << "Error: File could not be opened." << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find("User Name: ");
            if (pos != string::npos) {
               
                string username = line.substr(pos + 11);
                usernames.push_back(username);
            }
        }

        inFile.close();
    }

    bool IsUsernameUnique(const string& username) {
        for (const string& existingUsername : usernames) {
            if (existingUsername == username) {
                return false;
            }
        }
        return true;
    }
};


