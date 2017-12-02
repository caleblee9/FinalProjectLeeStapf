#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include <fstream>


using namespace std;

/*
------------------------------------------------------------
--------------------------STUDENT CLASS---------------------
------------------------------------------------------------
*/

class Student {		
	protected:
		string name;
		int id;
		double balance;
		vector<Book> books;
	public:
		Student();
		Student(string, int);
		void checkIn(Book);
		void acctInfo();
		void checkOut(string);
		void checkOut(int);
		void saveStudent();
		string getName() const;
		int getID() const;
		void setName(string);
		void setID(int);
		void setBalance(double);
		double getBalance() const;
		vector<Book> getBooks() const;

		Student operator=(const Student&) const;
			
};

void Student::setName(string nm) {
	name = nm;
}
void Student::setID(int num) {
	id = num;
}
void Student::setBalance(double bal) {
	balance = bal;
}
vector<Book> Student::getBooks() const{
	return books;
}
int Student::getID() const{
	return id;
}
double Student::getBalance() const{ 
	return balance;
}
Student Student::operator=(const Student &st1) const {
	Student tmp;
	tmp.name = st1.getName();
	tmp.id = st1.getID();
	tmp.balance = st1.getBalance();
	tmp.books = st1.getBooks();
return tmp;
}
string Student::getName() const{
	return name;
}
Student::Student() {
	id = 0;
	name = " ";
	balance = 0;
}
Student::Student(string nm, int num) {
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
void Student::saveStudent() {
	ofstream sFile;
	sFile.open("students.txt", ios_base::app);
	sFile << id << '|' << name << '|' << balance << '|';
	for(auto &i : books) {
		sFile << i.getTitle() << ' ';
	}
	sFile << endl;
	sFile.close();
}
