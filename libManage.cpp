#include <iostream>
#include <vector>
#include "student.h"
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void menu();


int main() {
	srand(time(NULL));
	int choice;
	menu();
	string nm;
again:	cin >> choice;
	switch(choice) {
		case 1:
			cout << "Please enter name";
			break;
		case 2:
			{
			cout << "Please enter name: ";
			cin >> nm;
			Student st1((int)(rand() % 500 + 1), nm);
			st1.acctInfo();
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
