#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>




using namespace std;


class Contact
{
protected:

	string Name;

	string phoneNum;

	string email;

	string address;

public:

	Contact();
	
	void contactOptions(string);

	void addContact();

	bool isExist(string);

	bool checkNumbers(string);

	bool checkDigits(string);

	void searchContact();

	void printContacts();

	void updateContact(string);

	void deleteContact(string);
	
};

