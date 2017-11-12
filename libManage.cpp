#include <iostream>
#include <vector>
#include "student.h"
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
again:	cin >> choice;
	switch(choice) {
		case 1:{
			cout << "Please enter name: ";
			string nm;
			string tmpName;
			Student st1;
			string tmp;
			cin.ignore();
			getline(cin, nm);
			ifstream sFile;
			sFile.open("students.txt");
			while(!sFile.eof()) {
				getline(sFile, tmp, '|');
				if(tmp == nm) {
					st1.setName(nm);
					getline(sFile, tmp, '|');
					st1.setID(stoi(tmp));
					getline(sFile, tmp, '|');
					st1.setBalance(stoi(tmp));
				}
			}
			st1.acctInfo();
			break;
			}
		case 2:
			{
			string nm;
			cin.ignore();
			cout << "Please enter name: ";
			getline(cin, nm);
			Student st1(nm, (int)(rand() % 500 + 1));
			st1.acctInfo();
			st1.saveStudent();
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
	return 0;	
}
void menu() {
	cout << endl << "Welcome to the Library Manager" << endl;
	cout << "Please chooce an option" << endl;
	cout << "(1) Login" << endl;
	cout << "(2) Register" << endl;
	cout << "(0) Exit" << endl;
}
