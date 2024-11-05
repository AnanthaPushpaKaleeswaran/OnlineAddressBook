// OnlineAddressBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "user.h"
#include "contact.h"
using namespace std;

void getInput(string* email, string* password);
void getContact(string* name, string* phoneNo, string* address);

class onlineAddressBook : public user,public contact{
public:
	void setUser(string email, string password) {
		this->email = email;
		this->password = password;
	}
	void setContact(string name, string phoneNo, string address) {
		this->name = name;
		this->phoneNo = phoneNo;
		this->address = address;
	}
};

int main()
{
	onlineAddressBook bookObj;
	while (1) {
		cout << "1.Login" << endl << "2.Signup" << endl << "3.Exit" << endl;
		cout << "Enter your choice : ";

		int type;
		string email;
		string password;
		bool ok = false;
		cin >> type;
		switch (type) {

		case 1:
			getInput(&email,&password);
			bookObj.setUser(email, password);
			ok=bookObj.validateUser();
			break;
		
		case 2:
			getInput(&email,&password);
			bookObj.setUser(email, password);
			ok=bookObj.addUser();
			break;
		
		default:
			cout << "Thank you :)";
			return 0;
		}
		cout << "-------------------------------------------------------------------!"<<endl<<endl;
		if (ok) {
			break;
		}
	}

	while (1) {
		cout << "1.Add Contact" << endl << "2.Search Contact" << endl << "3.Delete Contact" << endl;
		cout<<"4.Edit Contact"<<endl<<"5.See the contacts"<<endl<<"6.Exit"<<endl;
		cout << "Enter your choice : ";
		int choice;
		cin >> choice;
		bool ok = false;
		string name;
		string phoneNo;
		string address;
		switch (choice) {
		
		case 1:
			getContact(&name, &phoneNo, &address);
			bookObj.setContact(name, phoneNo, address);
			bookObj.addContact();
			break;

		case 2:
			bookObj.search();
			break;

		case 3:
			bookObj.deleteContact();
			break;

		case 4:
			bookObj.editContact();
			break;

		case 5:
			bookObj.viewContacts();
			break;

		default:
			cout << "Thank you :)";
			return 0;
		}
		cout << "-------------------------------------------------------------------!" << endl << endl;
	}
	return 0;
}

void getInput(string* email,string* password) {
	cout << "Enter your name : ";
	cin >> *email;

	cout << "Enter your password : ";
	cin >> *password;
}

void getContact(string* name, string* phoneNo,string* address) {
	cout << "Enter the name : ";
	cin >> *name;

	cout << "Enter the phone number : ";
	cin >> *phoneNo;

	cout << "Enter the address : ";
	cin >> *address;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
