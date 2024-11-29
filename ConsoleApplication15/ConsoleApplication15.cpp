#include <iostream>
#include "registr.h"
#include "Password.h"
#include <windows.h>
#include "test.h"
#include "currentUser.h"
using namespace std;


void main()
{
	Registr registr;
	Password password;
	Test test;
	CurrentUser currentuser;
	int choice = 0;
	int choiceUA = 0;
	


	cout << "1 - User\n2 - Admin\n3 - Exit\n";
	cout << "Select:";
	cin >> choiceUA;
	cin.ignore();
	do
	{

	
	if (choiceUA == 1)
	{
		system("cls");
		cout << "1 - New User\n2 - Current user\n3 - Exit\n" << endl;
		cout << "Select:";
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			Sleep(1000);
			system("cls");

			registr.AppendToFile();
			password.AddPassword();
			password.ComparePassword(registr);

		}
		else if (choice == 2)
		{

			currentuser.FindUserName();
			test.ShowQuestions();
			test.AddScore("Password.txt",currentuser);
			cout << endl;
			cout << "Wait 10 second";
			Sleep(10000);

		}
		else if (choice == 3) {
			break;
		}

	}
	if (choiceUA == 2)
	{
		cout << "Coming soon!";
	}

	if (choiceUA == 3) {
		break;
	}

	} while (true);
}

