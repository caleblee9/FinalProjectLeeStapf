#include <iostream>
#include <string>
#include <vector>
#include "book.h"

using namespace std;

/*
------------------------------------------------------------
--------------------------STUDENT CLASS---------------------
------------------------------------------------------------
*/

class Student {		
	protected:
		int id;
		string name;
		vector<Book> books;
		double balance;
		
	public:
		Student(int, string);
		void checkIn(Book);
		void acctInfo();
		void checkOut(string);
		void checkOut(int);
			
};
Student::Student(int num, string nm) {
	id = num;
	name = nm;
	balance = 0;
}
void Student::checkIn(Book b1) {
	books.push_back(b1);
}
void Student::acctInfo() {
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Books: ";
	if(books.empty()) {
		cout << "No checked out books" << endl;
	} else {
		for(auto &i : books) {
			cout << i.getTitle() << endl;
		}
	}
}
void Student::checkOut(string title) {
	int i;
	for(i = 0; i < books.size(); i++) {
		if(books[i].getTitle() == title) {
			books.erase(books.begin() + i - 1);
		}
	}
}
void Student::checkOut(int num) {
	int i;
	for(i = 0; i < books.size(); i++) {
		if(books[i].getNumber() == num) {
			books.erase(books.begin() + i - 1);
		}
	}
}
