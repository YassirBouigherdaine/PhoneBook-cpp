#pragma once
#include"Contact.h"


class PhoneBook : protected Contact
{
	Contact contact;

public:

	void menu();

	void creatContact();

	void printRecord();

	void removeAll();
};

