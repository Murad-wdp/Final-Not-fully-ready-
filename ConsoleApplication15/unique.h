#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <windows.h>
#include "registr.h"
using namespace std;

class Unique {
private:
	int changeCount;
	string result;
public:
	Unique() : changeCount(2) {}
	void currentuser(const string& filepath) {
		fstream InUser(filepath, ios::in);
		if (!InUser.is_open()) {
			cout << "Error: File could not be opened." << endl;
			return;
		}

		string line;
		int line_count = 0;
		result.clear();

		while (getline(InUser, line)) {
			line_count++;
			if (line_count == changeCount) {
				size_t pos = line.find(':');
				if (pos != string::npos) {
					for (size_t i = pos + 1; i < line.length(); i++) {
						if (line[i] == ' ') {
							continue;
						}
						result += line[i];
					}
				}
				changeCount += 3;
				break;
			}
		}

		InUser.close();
	}
		string CompareUsername(Registr & registr) {
			string registeredUsername = registr.GetUserName();
			if (result == registeredUsername)
			{

			}
	
};
