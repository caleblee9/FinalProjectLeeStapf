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
	vector<Book> books;	//checked out books
public:
	Student();		//constructors
	Student(string, int);
	void checkIn(string);	//check in with title
	void acctInfo();	//display acct info
	void checkOut(Book);	//check out Book
	void checkIn(int);	//check in with book number
	void saveStudent();	//save student when register
	void updateStudent();	//updated students information to file
	string getName() const;
	int getID() const;
	void setName(string);
	void setID(int);
};

void Student::setName(string nm) {
	name = nm;
}
void Student::setID(int num) {
	id = num;
}
int Student::getID() const {
	return id;
}
string Student::getName() const {
	return name;
}
Student::Student() {
	id = 0;
	name = " ";
}						///constructors
Student::Student(string nm, int num) {
	id = num;
	name = nm;
}
void Student::checkOut(Book b1) {
	books.push_back(b1);	//push to book vector
	
}
void Student::acctInfo() {
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Books: ";
	if (books.empty()) {
		cout << "No checked out books" << endl;	//account information, checks for no books
	}
	else {
		for (auto &i : books) {
			cout << i.getTitle() << ' ';
		}
	}
}
void Student::checkIn(string title) {
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {	//removes book from list
			books.erase(books.begin() + i);
		}
	}
}
void Student::checkIn(int num) {
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == num) {	//removes book from list
			books.erase(books.begin() + i);
		}
	}
}
void Student::saveStudent() {
	ofstream sFile;
	sFile.open("students.txt", ios_base::app);	//just saves id and name to be updated later
	sFile << id << '|' << name << '|';
	sFile.close();
}
void Student::updateStudent() {
	ifstream inFile;
	inFile.open("students.txt");
	string line;
	ofstream sFile;
	sFile.open("tmp.txt");	//tmp file to write to and then read from

	while(getline(inFile, line, '|')) {
			if(atoi(line.c_str()) == id) {	//on line which has ID
			sFile << id << '|' << name << '|';	//print id and name to tmp file
			for (auto &i : books) {
				sFile << i.getNumber() << ' ';	//print book numbers seperated by commas
			}
			sFile << endl;
			getline(inFile, line);	//get rest of line in order to start new
			continue;
		}
		sFile << line;	//if not found just print whatever the line contained to tmp
		getline(inFile, line);
		sFile << '|' << line;
		sFile << endl;
			
	}
	inFile.close();
	sFile.close();
	inFile.open("tmp.txt");
	sFile.open("students.txt");
	while(getline(inFile, line)) {	//pull from the tmp file and rewrite students.txt
		sFile << line;
		sFile << endl;
	}
	inFile.close();
	sFile.close();
	remove("tmp.txt");	//remove tmp file
}

