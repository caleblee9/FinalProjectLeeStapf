#include <iostream>
#include <vector>
#include "student.h"
#include "catalog.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>


using namespace std;

void menu();


int main() {
	srand(time(NULL));
	int choice;
	menu();
	Catalog bookCatalog("catalog.txt");
	Student activeStudent = Student("None",0);

again:	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Please enter name: ";
		string nm;
		string tmpName;
		string tmp;
		cin.ignore();
		getline(cin, nm);
		ifstream sFile;
		sFile.open("students.txt");
		while (!sFile.eof()) {
			getline(sFile, tmp, '|');
			if (tmp == nm) {
				activeStudent.setName(nm);
				getline(sFile, tmp, '|');
				activeStudent.setID(stoi(tmp));
				getline(sFile, tmp, '|');
				activeStudent.setBalance(stoi(tmp));
			}
			getline(sFile, tmp);
		}
		activeStudent.acctInfo();
		break;
	}
	case 2:
	{
		string nm;
		cin.ignore();
		cout << "Please enter name: ";
		getline(cin, nm);
		activeStudent = Student(nm, (int)(rand() % 500 + 1));
		activeStudent.acctInfo();
		activeStudent.saveStudent();
		break;
	}
	case 3:
		cout << "Exiting..." << endl;
		break;
	case 4:
		cout << "Invalid option, please enter again" << endl;
		goto again;
	}
	cout << endl;


	if (activeStudent.getID() != 0)
	{
		int menuchoice;
		do
		{
			cout << "\nWhat would you like to do?" << endl;
			cout << "1. Check out a book by title" << endl << "2. Check out a book by number" << endl;
			cout << "3. Check in a book by title" << endl << "4. Check in a book by number" << endl;
			cout << "5. Display the catalog" << endl << "6. Exit" << endl;
			cin >> menuchoice;

			switch (menuchoice)
			{
				case 1:
				{
					string booktitle;
					cout << "What is the book title you want to check out?  ";
					cin.ignore();
					getline(cin,booktitle);

					if (bookCatalog.bookExists(booktitle))
					{
						activeStudent.checkIn(bookCatalog.checkOut(booktitle));
					}
					else
					{
						cout << "Sorry that book doesn't exist in the catalog." << endl;
					}
					break;
				}
				case 2:
				{
					int booknumber;
					cout << "What is the book number you want to check out?  ";
					cin >> booknumber;
					if (bookCatalog.bookExists(booknumber))
					{
						activeStudent.checkIn(bookCatalog.checkOut(booknumber));
					}
					else
					{
						cout << "Sorry that book doesn't exist in the catalog." << endl;
					}
					break;
				}
				case 3:
				{
					string booktitle;
					cout << "What is the book title you want to check in?  ";
					cin.ignore();
					getline(cin,booktitle);
					if (bookCatalog.bookExists(booktitle))
					{
						activeStudent.checkOut(booktitle);
						bookCatalog.checkIn(booktitle);
					}
					else
					{
						cout << "This book is not contained within our catalog";
					}
					break;
				}
				case 4:
				{
					int booknumber;
					cout << "What is the book number you want to check in?  ";
					cin >> booknumber;
					if (bookCatalog.bookExists(booknumber))
					{
						activeStudent.checkOut(booknumber);
						bookCatalog.checkIn(booknumber);
					}
					else
					{
						cout << "This book is not contained within our catalog";
					}
					break;
				}
				case 5:
				{
					bookCatalog.display();
					break;
				}
			}
		} while (menuchoice < 6);
	}


	return 0;
}
void menu() {
	cout << endl << "Welcome to the Library Manager" << endl;
	cout << "Please chooce an option" << endl;
	cout << "(1) Login" << endl;
	cout << "(2) Register" << endl;
	cout << "(0) Exit" << endl;
}
