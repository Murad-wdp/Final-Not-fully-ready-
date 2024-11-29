#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Burada filedan passwordun deyerini  alib ASCII table ? ?sas?n int deyerini alýb onun üz?rin? 965(d?yiþ?n formada etm?yid? düþünürdüm)
// g?lib sonradan fileda h?m?n r?q?mi saxlamaq ist?yirdim.Password yoxlandýqda normal halýna çevirip müqais? etm?k fikrim var idi.
class Encryption {
private:
	int ASCII;
	int count;
	string result;
public:
	void Encryptions(const string password) {
		count = 0;
		for (size_t i = 0; i < password.length(); i++)
		{
			count += 965;
			fstream Infile("PasswordA.txt", ios::app);
			Infile << (int)password[i] + count << " ";

		}

	}
	void ReadPassword(const string& filename) {
		ifstream Infile(filename);
		string line;


		if (!Infile.is_open()) {
			cout << "Error: File could not be opened." << endl;
			return;
		}
		while (getline(Infile, line)) {
			size_t find = line.find("Password: ");
			if (find != string::npos) {
				string existingUsername = line.substr(find + 11);

			
			}
		}
		Infile.close();
	}

};
