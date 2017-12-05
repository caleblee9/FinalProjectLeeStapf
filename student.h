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
		string name;	//student name
		int id;		//student ID number
		double balance;		//fees owed
		vector<int> books;
	public:
		Student();
		Student(string, int);	//constructors
		void checkIn(int);	//check in a book
		void acctInfo();	//display name, ID, balance, books
		void checkOut(int);	
		void saveStudent();	//save student to students.txt file
		string getName() const;
		int getID() const;
		void setName(string);
		void setID(int);
		void setBalance(double);
		double getBalance() const;
		vector<int> getBooks() const;

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
vector<int> Student::getBooks() const{
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
	name = " ";	//default constructor
	balance = 0;
}
Student::Student(string nm, int num) {
	id = num;
	name = nm;		
	balance = 0;
}
void Student::checkOut(int num) {
	books.push_back(num);
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
			cout << i << endl;
		}
	}
}
void Student::checkIn(int num) {
	int i;
	for(i = 0; i < books.size(); i++) {
		if(books[i] == num) {
			books.erase(books.begin() + i - 1);
		}
	}
}
void Student::saveStudent() {
	ofstream sFile;
	sFile.open("students.txt", ios_base::app);
	sFile << id << '|' << name << '|' << balance << '|';
	for(auto &i : books) {
		sFile << i << ' ';	//saves just book numbers to be compared with books vector in main
	}
	sFile << endl;
	sFile.close();
}
