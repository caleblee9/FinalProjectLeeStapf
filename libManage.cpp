#include <iostream>
#include <vector>
#include "std.h"
#include "catalog.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void mainMenu();				//display menu
void studentOptions(Student, Catalog);	//student menu
void login(Catalog);			//login student
void reg(Catalog);					//register student
void updateCatalog(Catalog);


int main() {
	Catalog books("catalog.txt");	
	int choice;
	do {
		mainMenu();
again:		if(!(cin >> choice)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//checks for non-integer input
			cout << "Invalid option, please enter again: ";
			goto again;
		}
		switch(choice) {
			case 1:	
			{
			
				system("clear");
				try {
					login(books);	
					break;
				} catch (string feo) {
					cout << "Can't open students.txt, please make sure you have it and try again" << endl; //if students cant be opened, exit program since it would break
					return 0;
				}
			}
			case 2:
			{
				
				system("clear");
				try {
					reg(books);
					break;
				} catch(string feo) {
					cout << "Can't open students.txt, please make sure you have it and try again" << endl;
					return 0;
				}
			}
			case 3:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid option, please enter again: ";
				goto again;
		}
		cout << endl;
	} while(choice != 3);
	return 0;	
}
void mainMenu() {
	cout << endl << "Welcome to the Library Manager" << endl;
	cout << "Please chooce an option" << endl;
	cout << "(1) Login" << endl;
	cout << "(2) Register" << endl;
	cout << "(3) Exit" << endl;
}
void login(Catalog c1) {
	ifstream sFile;
	sFile.open("students.txt");
	if(!(sFile.is_open())) {
		throw "Can't open file";
		return;
	}
	system("clear");
	cout << "Please Scan ID: ";
	int num;
	Student st1;	//used to get student information and store it in a local variable
	string tmp;	//to pull information from file
	string tmp2;
	cin.ignore();
	cin >> num;
	system("clear");
	while(getline(sFile, tmp, '|')) {
		tmp2 = tmp;
		if(atoi(tmp2.c_str()) == num) {	//if matched
			cout << endl;
			st1.setID(num);
			getline(sFile, tmp, '|');		//pull student information from file
			st1.setName(tmp);
			while(getline(sFile, tmp, ' ')) {
				if(tmp == "\n") {
					break;
				}
				for(auto &i : c1.getBooks()) {	//loop through file and pull book numbers and search for them in catalog
					if(i.getNumber() == atoi(tmp.c_str())){
						st1.checkOut(c1.checkOut(atoi(tmp.c_str())));	//append books to students checked out books
						break;
					}
				}
			}
			studentOptions(st1, c1);
			sFile.close();
			return;	
		}
		getline(sFile, tmp);	
	}	
	cout << "Student Number not found" << endl;	//if reach eof, student not found
	sFile.close();
}
void studentOptions(Student std, Catalog c1) {
	int choice;
	do {
		cout << "Please choose an option" << endl;
		cout << "1. View Account Information" << endl;
		cout << "2. View Catalog" << endl;
		cout << "3. Search Catalog" << endl;
		cout << "4. Check in book by title" << endl;
		cout << "5. Check in book by number" << endl;
		cout << "6. Check out book by title" << endl;
		cout << "7. Check out book by number" << endl;
		cout << "8. Logout" << endl;
inv:		if(!(cin >> choice)) {
			cout << "Invalid input, please enter a valid option: ";	//if user enters a non-integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto inv;
		}
		switch(choice) {
			case 1:
				
				system("clear");
				cout << endl;
				cout << "******ACCOUNT INFORMATION******" << endl;	//display account info
				std.acctInfo();
				cout << endl << endl << endl;
				break;
			case 2:
				system("clear");

				c1.display();
				cout << endl << endl;
				break;
			case 3:
			{
				system("clear");

				string search;
				string line;
				int found = 0;
				ifstream catalog;
				catalog.open("catalog.txt");

				cout << "What book would you like to search for?: ";
				cin.ignore();
				getline(cin, search);

				if (catalog.is_open())
				{
					while (!catalog.eof())		///loop until end of file
					{			
						getline(catalog, line, '|');	//check title

						if (search == line)	//if book is found
						{
							cout << search << " is in the catalog\n" << endl << endl;
							found = 1;
							break;
						}
						getline(catalog, line);
					}
					if(found == 0) {
						cout << search << " is not in the catalog" << endl << endl;
					}
					catalog.close();
				} else {
					throw "Can't open file";
				}

				break;
			}
			case 4:
				system("clear");

				{
					string booktitle;
					cout << "What is the book title you want to check in?  ";
					cin.ignore();
					getline(cin,booktitle);
					if (c1.bookExists(booktitle))	//check book exists
					{
						std.checkIn(booktitle);
						c1.checkIn(booktitle);
						std.updateStudent();	//update to rewrite
					}
					else
					{
						cout << "This book is not contained within our catalog";	//book not found
					}
					break;
				}
			
			case 5:
				system("clear");

				{
					int booknumber;
					cout << "What is the book number you want to check in?  ";
					cin >> booknumber;
					if (c1.bookExists(booknumber))
					{
						std.checkIn(booknumber);
						c1.checkIn(booknumber);		//same as before but with number
						std.updateStudent();
					}
					else
					{
						cout << "This book is not contained within our catalog";
					}
					break;
				}

				break;
			case 6:
				system("clear");

				{
					string booktitle;
					cout << "What is the book title you want to check out?  ";
					cin.ignore();
					getline(cin,booktitle);
	
					if (c1.bookExists(booktitle))	//check book exists
					{
						std.checkOut(c1.checkOut(booktitle));	//checkout and update student	
						std.updateStudent();
					}
					else
					{
						cout << "Sorry that book doesn't exist in the catalog." << endl;
					}

					break;
				}

				break;
			case 7:
			{
				system("clear");

				int booknumber;
				cout << "What is the book number you want to check out?  ";
				cin >> booknumber;
				if (c1.bookExists(booknumber))
				{
					std.checkOut(c1.checkOut(booknumber));	//same as above but with number
				}
				else
				{
					cout << "Sorry that book doesn't exist in the catalog." << endl;
				}
				break;
			}

				break;
			case 8:
				break;	//break the loop, exit the menu
			default:
				cout << "Invalid input, please enter a valid option: ";	//numerical invalid input
				goto inv;
			
		}
	}while(choice != 8);
}
void reg(Catalog c1){
	ifstream sFile;
	sFile.open("students.txt");
	if(!sFile.is_open()) {
		throw "Can't open File";
		return;
	}
	system("clear");
	int num;
	string nm;	//name of registering student
	cin.ignore();
	cout << "Please Scan ID ";
	cin >> num;
	string tmp;
	while(!sFile.eof()) {
		getline(sFile, tmp, '|');	//look at ID of students
		if(atoi(tmp.c_str()) == num) {	//if matched, student already has an account
			cout << "Account already registered" << endl;
			sFile.close();
			return;
			
		}
		getline(sFile, tmp);	
	}
	sFile.close();
	cin.ignore();
	cout << "Please enter name: ";
	getline(cin, nm);
	while(nm == "") {
		cout << "No name entered, please enter again: ";
		getline(cin, nm);
	}
	Student st1(nm, num);
	st1.saveStudent();
	cout << endl << endl;
	studentOptions(st1, c1);
}
