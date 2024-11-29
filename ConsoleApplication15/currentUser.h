#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "test.h"
using namespace std;

class CurrentUser {
private:
	string resultUsername;
	int changeCount;
public:
	string currentpassword;
	string resultPassword;
	CurrentUser() : changeCount(1) {};


	bool fetchCredentials(const string& filepath, const string& username, const string& password) {
		ifstream file(filepath);
		if (!file.is_open()) {
			cout << "Error: File could not be opened." << endl;
			return false;
		}

		string line;
		resultUsername.clear();
		resultPassword.clear();

		while (getline(file, line)) {

			if (line.find("Username:") != string::npos) {
				resultUsername = line.substr(line.find("Username:") + 9);
				resultUsername.erase(0, resultUsername.find_first_not_of(" "));

				if (getline(file, line)) {
					if (line.find("Password:") != string::npos) {
						resultPassword = line.substr(line.find("Password:") + 9); 
						resultPassword.erase(0, resultPassword.find_first_not_of(" ")); // Bunu keçməmişik müəllim bunu araşdırıp tapdım
						//ilk boşluğa qədər oxuyur(özümüz qeyd edə bilərik) substrdə qeyd olunan indekslər arasını bizə qaytarır.Find ilədə lazım olan sözü tapırıq.
					}
				}


				if (username == resultUsername && password == resultPassword) {
					return true;
				}
			}
		}

		return false;
	}


	void FindUserName() {
		string username;
		string password;
		currentpassword = password;
		while (true) {
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;

			if (fetchCredentials("Password.txt", username, password)) {
				cout << "Welcome, " << username << "!" << endl;
				currentpassword = password;
				break;
			}
			else {
				cout << "Invalid username or password. Please try again." << endl;
			}
		}

	}
	string GetPassword() {
		return  currentpassword;
	}

};

