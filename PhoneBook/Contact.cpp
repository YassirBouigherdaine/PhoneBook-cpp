#include "Contact.h"




Contact::Contact() : Name(""), phoneNum("00"), email("Unknown"), address("Unknown")
{}


void Contact::addContact()
{
	system("cls");

	string tmpName, tmpPhoneNum;

	ofstream contactFile;
	contactFile.open("contacts.txt", ios::app | ios::binary);

	cout << "\n\t\t CONTACT DETAILS\n";
	cout << "\t\t*******************\n\n";
	cout << "\tFirst name : ";
	cin >> tmpName;

	if (isExist(tmpName))
	{
		cout << "\t Contact already exist with this name\n";
		_getch();
		return;
	}

	cout << "\n\tPhone number : ";
	cin >> tmpPhoneNum;

	if (!checkDigits(tmpPhoneNum))
	{
		cout << "\n\t Phone number must have 10 digits\n";
		_getch();
		return;
	}

	if (!checkNumbers(tmpPhoneNum))
	{
		cout << "\n\t Phone number must have digits only\n";
		_getch();
		return;
	}

	Name = tmpName;
	phoneNum = tmpPhoneNum;
	cout << "\n\tEmail : ";
	cin >> email;
	cout << "\n\tAddress : ";
	cin >> address;

	contactFile.write((char*)this, sizeof(Contact));
	
	system("cls");
	cout << "\n\n\t\t Contact saved successfully";
	_getch();
	
	contactFile.close();
}


void Contact::printContacts()
{
	ifstream contactFile;
	contactFile.open("contacts.txt", ios::in | ios::binary);

	contactFile.read((char*)this, sizeof(Contact));

	if (contactFile.good())
	{
		while (!contactFile.eof())
		{
			cout << "\t\t--------------------------------------------------------\n";
			cout << "\t\t\t\t\t" << Name << std::endl;
			cout << "\t\t--------------------------------------------------------\n";

			contactFile.read((char*)this, sizeof(Contact));
		}

		contactFile.close();
	}
	else if (Name == "")
	{
		cout << "\n\t\t\t\t  List is empty\n";
	}

	else
	{
		cout << "\n\t\t\tError occurred in opening the file\n";
	}

}

void Contact::contactOptions(string tmpName)
{
	int op;

	cout << "\n\t\t    [1] Edit contact \t [2] Delete contact \t [3] Exit\n";

	std::cout << "\n\t\t\t>Your choice: ";
	std::cin >> op;

	switch (op)
	{
	case 1: updateContact(tmpName);
		break;

	case 2: deleteContact(tmpName);
		break;

	case 3: break;
		break;

	default: cout << "\n\t\t\t Invalid choice";
		     _getch();
		break;
	}
}

void Contact::updateContact(string tmpName)
{
	string tmpPhoneNum;

	fstream contactFile;
	contactFile.open("contacts.txt", ios::in | ios::out | ios::binary);

	if (contactFile.good())
	{
		while (contactFile.read((char*)this, sizeof(Contact)))
		{
			if (Name == tmpName)
			{
				system("cls");

				cout << "\n\n\t\t Enter new contact details :\n";

				cout << "\n\tName : ";
				cin >> tmpName;

				if (isExist(tmpName))
				{
					cout << "\n\t Contact already exist with this name\n";
					_getch();
					return;
				}

				cout << "\n\tPhone number : ";
				cin >> tmpPhoneNum;

				if (!checkDigits(tmpPhoneNum))
				{
					cout << "\n\t Phone number must have 10 digits\n";
					_getch();
					return;
				}
				if (!checkNumbers(tmpPhoneNum))
				{
					cout << "\n\t Phone number must have digits only\n";
					_getch();
					return;
				}

				Name = tmpName;
				phoneNum = tmpPhoneNum;

				cout << "\tEmail : ";
				cin >> email;
				cout << "\tAddress : ";
				cin >> address;

				int pos = -1 * static_cast<int>(sizeof(Contact));
				contactFile.seekp(pos, ios::cur);
				contactFile.write((char*)this, sizeof(Contact));

				cout << "\n\t\t\t Contact modified successfully\n";
				_getch();
				break;
			}
		}
	}
	else
	{
		cout << "\n\t\tError occurred in opening the file\n";
		_getch();
	}

	contactFile.close();
	system("cls");
}


void Contact::deleteContact(string tmpName)
{
	fstream contactFile("contacts.txt", ios::in | ios::binary);
	fstream newFile("tempFile.txt", ios::app | ios::binary);

	while (contactFile.read((char*)this, sizeof(Contact)))
	{
		if (Name != tmpName)
		{
			newFile.write((char*)this, sizeof(Contact));
		}
	}

	contactFile.close();
	newFile.close();
	remove("contacts.txt");
	rename("tempFile.txt", "contacts.txt");

	system("cls");
	cout << "\n\t\t\t contact was deleted successfully\n";
	_getch();
	return;
}


void Contact::searchContact()
{
	system("cls");

	ifstream contactFile;
	contactFile.open("contacts.txt", ios::in | ios::binary);

	string tmpName;
	cout << "\n\n\t\t Enter name : ";
	cin >> tmpName;

	if (isExist(tmpName))
	{
		while (!contactFile.eof())
		{
			contactFile.read((char*)this, sizeof(Contact));

			if (Name == tmpName)
			{
				system("cls");
				cout << "\n----------------------------------CONTACT DETAILS-------------------------------------------------------\n\n";
				cout << "--------------------------------------------------------------------------------------------------------\n";
				cout << "\t\tNAME \t PHONE NUMBER\t  EMAIL ADDRESS\t\t  ADDRESS\n\n";
				cout << "--------------------------------------------------------------------------------------------------------\n";
				cout << "\t\t" << Name << " \t " << phoneNum << "\t  " << email << "\t  " << address << std::endl;
				cout << "--------------------------------------------------------------------------------------------------------\n";

				break;
			}

		}

		contactFile.close();

		contactOptions(tmpName);
	}

	else
	{
		system("cls");
		cout << "\n\t\tContact not found\n";
		_getch();
	}
}



bool Contact::isExist(string tmpName)
{
	ifstream contactFile;
	contactFile.open("contacts.txt", ios::in | ios::binary);

	while (!contactFile.eof())
	{
		contactFile.read((char*)this, sizeof(Contact));

		if (Name == tmpName)
		{
			return 1;
		}
	}

	contactFile.close();

	return 0;
}


bool Contact::checkDigits(string s)
{
	if (s.length() != 10)
	{
		return false;
	}

	return true;
}

bool Contact::checkNumbers(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if ( !(int(s[i]) >= 48 && int(s[i]) <= 57))
		{
			return false;
			break;
		}
	}

	return true;
}