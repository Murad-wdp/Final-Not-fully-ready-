#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "currentUser.h"
using namespace std;

class Test {
private:
	int correctCount;
	string resultPassword;
	string PasswordCheck; 


public:
	Test() : correctCount(0), PasswordCheck("") {}

	void loadQuestions(const string& filepath) {

		ifstream inFile(filepath);
		if (!inFile.is_open()) {
			cout << "The test file could not be opened!" << endl;
			return;
		}
		string line;
		int line_count = 0;
		int Sleeping = 5;
		while (getline(inFile, line)) {
			line_count++;
			cout << line << endl;
			if (line_count == Sleeping)
			{
				Sleep(1000);
				Sleeping += 5;
				cout << endl;
			}

		}
		inFile.close();


	}

	void ShowQuestions() {
		cout << "Choice category" << endl;
		cout << "1 - Riyaziyyat (bolme) -> Diskret riyaziyyat (konkret test)\n";
		cout << "2 - Riyaziyyat(bolme) -> Riyazi analiz (konkret test)\n";
		cout << "3 - Fizika(bolme) -> Kvant fizikası (konkret test)\n";
		cout << "4 - Fizika(bolme) -> Mexanika (konkret test)\n";
		cout << "--------------------------------------------------------";
		cout << endl;

		int choice = 0;
		cout << "Select (1 - 4):";
		cin >> choice;
		switch (choice)
		{
		case 1:
			loadQuestions("1-test.txt");
			loadAnswers("1-answer.txt");


			break;

		case 2:
			loadQuestions("2-test.txt");
			loadAnswers("2-answer.txt");
			break;
		case 3:
			loadQuestions("3-test.txt");
			loadAnswers("3-answer.txt");
			break;
		case 4:
			loadQuestions("4-test.txt");
			loadAnswers("4-answer.txt");
			break;
		default:
			cout << "Invalid choice. Exiting the program." << endl;
			break;
		}

	}

	void loadAnswers(const string& filepath) {



		ifstream inFile(filepath);
		if (!inFile.is_open()) {
			cout << "The answers file could not be opened!" << endl;
			return;
		}
		string line;
		int line_count = 0;
		int number = 0;
		while (getline(inFile, line)) {
			line_count += 1;
			line.erase(line.find_last_not_of(" ") + 1);

			string answer;
			number += 1;
			cout << number << " - ";
			cin >> answer;

			if (answer == line)
			{
				correctCount += 1;
			}


			if (number == 5)
			{
				break;
			}


		}

		cout << "You score - " << correctCount << "/5" << endl;
		cout << "The percentage of correct questions is " << correctCount * 20 << "%" << endl;
		cout << "Total points: " << correctCount * 2.4 << "/12" << endl;

		inFile.close();

	}


	void AddScore(const string& filename, CurrentUser& other) {
		string PasswordCheck = other.GetPassword();
		ifstream Infile(filename);
		ofstream Tempfile("temp.txt");
		string line;

		bool passwordFound = false;

		if (!Infile.is_open() || !Tempfile.is_open()) {
			cout << "Error: File could not be opened." << endl;
			return;
		}
		string result = "Password: ";
		result = result + PasswordCheck;

		while (getline(Infile, line)) {

			Tempfile << line << endl;
			if (line == result && !passwordFound) {

				Tempfile << "Score:" << correctCount << endl;
				passwordFound = true;
			}
		}
		Infile.close();
		Tempfile.close();

		remove(filename.c_str());
		rename("temp.txt", filename.c_str());

	}




};