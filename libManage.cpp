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

int main() {
	srand(time(NULL));
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
	Student st1;
	string tmp;
	cin.ignore();
	cin >> num;
	ifstream sFile;
	sFile.open("students.txt");
	while(!sFile.eof()) {
		getline(sFile, tmp, '|');
		if(atoi(tmp.c_str()) == num) {
			st1.setID(num);
			getline(sFile, tmp, '|');
			st1.setName(tmp);
			getline(sFile, tmp, '|');
			st1.setBalance(stoi(tmp));
		}
		getline(sFile, tmp);
		
	}
	
}
