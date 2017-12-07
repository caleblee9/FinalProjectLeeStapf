#include <iostream>
#include <vector>
#include "student.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void mainMenu();				//display menu
void studentOptions(Student, vector<Book>);	//student menu
void login(vector<Book>);			//login student
void reg(vector<Book>);					//register student
vector<Book> getBooks();			//list of available books
void updateCatalog(vector<Book>);


int main() {
	srand(time(NULL));
	try {
		vector<Book> books = getBooks();	//list of Books
	} catch (const char* feo){
		cout << "Can't open catalog.txt, make sure you have it and try again" << endl;
		return 0;
	}
	/*
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
				try {
					login(books);	
					break;
				} catch (string feo) {
					cout << "Can't open students.txt, please make sure you have it and try again" << endl;
					return 0;
				}
			}
			case 2:
			{
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
*/
	return 0;	
}
void mainMenu() {
	cout << endl << "Welcome to the Library Manager" << endl;
	cout << "Please chooce an option" << endl;
	cout << "(1) Login" << endl;
	cout << "(2) Register" << endl;
	cout << "(3) Exit" << endl;
}
void login(vector<Book> catalog) {
	ifstream sFile;
	sFile.open("students.txt");
	if(!(sFile.is_open())) {
		throw "Can't open file";
		return;
	}
	cout << "Please Scan ID: ";
	int num;
	Student st1;	//used to get student information and store it in a local variable
	string tmp;	//to pull information from file
	cin.ignore();
	cin >> num;
	while(!sFile.eof()) {
		getline(sFile, tmp, '|');	//look at ID of student
		if(atoi(tmp.c_str()) == num) {	//if matched
			cout << endl;
			st1.setID(num);
			getline(sFile, tmp, '|');		//pull student information from file
			st1.setName(tmp);
			getline(sFile, tmp, '|');
			st1.setBalance(stoi(tmp));
			studentOptions(st1, catalog);
			sFile.close();
			return;
			
		}
		getline(sFile, tmp);	
	}
	cout << "Student Number not found" << endl;
	sFile.close();
}
vector<Book> getBooks(){
	ifstream catalog_file("catalog.txt");
	if(!(catalog_file.is_open())) {
		throw "Can't open file";
	} 
	vector<Book> catalog;		//list of books
	
	string line;
	string nm;	//book number
	string auth;	//author
	int num;
	while(!catalog_file.eof())
	{
		getline(catalog_file, line, '|');
		nm = line;
		getline(catalog_file, line, '|');
		auth = line;				//reads in information from file about book and stores it in a Book object
		getline(catalog_file, line);
		num = atoi(line.c_str());
		Book tmp(nm, auth, num);
		catalog.push_back(tmp);	//add book to list
	}
	catalog.pop_back();
	catalog_file.close();
	return catalog;
}
void studentOptions(Student std, vector<Book> catalog) {
	int choice;
	do {
		cout << "Please choose an option" << endl;
		cout << "1. View Account Information" << endl;
		cout << "2. View Catalog" << endl;
		cout << "3. Search Catalog" << endl;
		cout << "3. Check In Book" << endl;
		cout << "4. Check Out Book" << endl;
		cout << "5. Exit" << endl;
inv:		if(!(cin >> choice)) {
			cout << "Invalid input, please enter a valid option: ";	//if user enters a non-integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto inv;
		}
		switch(choice) {
			case 1:
				cout << endl;
				cout << "******ACCOUNT INFORMATION******" << endl;	//display account info
				std.acctInfo();
				cout << endl;
				break;
			case 2:
				for(auto &c : catalog) {	//range for to loop through cataglog and display the book info
					c.display();
				}
				cout << endl;
				break;
			case 3:
			{
				string search;
				string line;

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
							cout << search << " is in the catalog\n" << endl;
							break;
						}
						getline(catalog, line);
					}
					catalog.close();
				} else {
					throw "Can't open file";
				}

				break;
			}
			case 4:
				break;
			case 5:
				break;	//break the loop, exit the menu
			default:
				cout << "Invalid input, please enter a valid option: ";	//numerical invalid input
				goto inv;
			
		}
	}while(choice != 5);
}
void updateCatalog(vector<Book> books) {
	ofstream cf;
	cf.open("catalog.txt");
	if(cf.is_open()){
		for(auto &c : books) {
			cf << c.getTitle() << '|' << c.getAuthor() << '|' << c.getNumber() << endl; //rewrite the catalog file	
		}
		cf.close();
	} else {
		throw "Can't open file";
	}
	
}
void reg(vector<Book> catalog) {
	ifstream sFile;
	sFile.open("students.txt");
	if(!sFile.is_open()) {
		throw "Can't open File";
		return;
	}
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
	Student st1(nm, num);
	st1.acctInfo();
	st1.saveStudent();	//save student to file
	studentOptions(st1, catalog);

}
