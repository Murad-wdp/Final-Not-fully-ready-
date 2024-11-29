#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "registr.h"

using namespace std;

class Password {
private:
    string Name, password, resultPassword;
public:

    void AddPassword() {
        cout << "Sign in" << endl;

     
        while (true) {
            cout << "Username: ";
            getline(cin, Name);

            if (IsUsernameValid(Name)) {
                break; 
            }
            else {
                cout << "Username is not found! Please try again.\n";
            }
        }

        Sleep(500);
        system("cls");

        
        cout << "Password: ";
        getline(cin, password);

        cout << "Confirm - Password: ";
        getline(cin, resultPassword);

        while (resultPassword != password) {
            cout << "Passwords do not match! Please try again.\n";
            cout << "Confirm - Password: ";
            getline(cin, resultPassword);
        }

        Sleep(500);
        system("cls");

      
        ofstream outFile("Password.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Username: " << Name << endl;
            outFile << "Password: " << password << endl;
            outFile << "-----------------" << endl;
            outFile.close();
            cout << "Account successfully created!\n";
        }
        else {
            cout << "Error: Could not open the file.\n";
        }
    }
    
    string ComparePassword(Registr& registr) {
        string registeredUsername = registr.GetUserName();

       
        while (registeredUsername != Name) {
            cout << "Username is not found! Please try again.\n";
            cout << "Username: ";
            getline(cin, Name);
        }

      
     
        return Name;
    }

private:
    bool IsUsernameValid(const string& username) {
        ifstream inFile("user_data.txt");
        if (!inFile.is_open()) {
            cout << "Error: Could not open the user data file.\n";
            return false;
        }

        string line;
        while (getline(inFile, line)) {
            size_t find = line.find("User Name: ");
            if (find != string::npos) {
                string existingUsername = line.substr(find + 11);
                if (existingUsername == username) {
                    inFile.close();
                    return true;
                }
            }
        }

        inFile.close();
        return false;
    }
};
