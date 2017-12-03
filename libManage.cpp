#include <iostream>
#include <vector>
#include "student.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

void menu();
void login();
void reg();
vector<Book> getBooks();

int main() {
	srand(time(NULL));
	vector<Book> books = getBooks();
	int choice;
	do {
		menu();
again:		cin >> choice;
		switch(choice) {
			case 1:	
			{
				login();	
				break;
			}
			case 2:
			{
				int num;
				string nm;
				cin.ignore();
				cout << "Please Scan ID ";
				cin >> num;
				cin.ignore();
				cout << "Please enter name: ";
				getline(cin, nm);
				Student st1(nm, num);
				st1.acctInfo();
				st1.saveStudent();
				break;
			}
			case 3:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid option, please enter again" << endl;
				goto again;
		}
		cout << endl;
	} while(choice != 3);
	return 0;	
}
void menu() {
	cout << endl << "Welcome to the Library Manager" << endl;
	cout << "Please chooce an option" << endl;
	cout << "(1) Login" << endl;
	cout << "(2) Register" << endl;
	cout << "(3) Exit" << endl;
}
void login() {
	cout << "Please Scan ID: ";
	int num;
	Student st1;	//used to get student information and store it in a local variable
	string tmp;	//to pull information from file
	cin.ignore();
	cin >> num;
	ifstream sFile;
	sFile.open("students.txt");
	while(!sFile.eof()) {
		getline(sFile, tmp, '|');	//look at ID of student
		if(atoi(tmp.c_str()) == num) {	//if matched
			st1.setID(num);
			getline(sFile, tmp, '|');		//pull student information from file
			st1.setName(tmp);
			getline(sFile, tmp, '|');
			st1.setBalance(stoi(tmp));
		}
		getline(sFile, tmp);	
	}
	sFile.close();
}
vector<Book> getBooks(){
	vector<Book> catalog;
	ifstream catalog_file("catalog.txt");
	string line;
	string nm;
	string auth;
	int num;
	while(!catalog_file.eof())
	{
		getline(catalog_file, line, '|');
		nm = line;
		getline(catalog_file, line, '|');
		auth = line;
		getline(catalog_file, line);
		num = atoi(line.c_str());
		Book tmp(nm, auth, num);
		catalog.push_back(tmp);
	}
	catalog_file.close();
	return catalog;
}
