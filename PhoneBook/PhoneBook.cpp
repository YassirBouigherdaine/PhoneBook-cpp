#include "PhoneBook.h"



void PhoneBook::menu()
{
	int ch;

	do
	{
		system("cls");

		cout << "\n\n\t\t*******************************************************\n";
		cout << "\t\t**                                                   **\n";
		cout << "\t\t*                       CONTACTS                      *\n";
		cout << "\t\t**                                                   **\n";
		cout << "\t\t*******************************************************\n\n";

		cout << "\n\t\t   [1] Create contact \t[2] Search \t [3] Exit\n\n";
		cout << "\t\t--------------------------------------------------------\n";

		contact.printContacts();

		cout << "\n\t\t\t>Your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1: creatContact();
			break;

		case 2: printRecord();
			break;

		case 3: exit(1);
			break;

		default: cout << "\n\t\t\t Invalid choice";
			     _getch();
			break;
		}

	} while (true);
	
}

void PhoneBook::creatContact()
{
	contact.addContact();
}

void PhoneBook::printRecord()
{
	contact.searchContact();
}

