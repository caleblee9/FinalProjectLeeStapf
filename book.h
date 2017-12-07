#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
----------------------------------------------------
------------------BOOK CLASS------------------------
----------------------------------------------------
*/
class Book {
private:
	string title;
	string author;
	int number;

public:
	bool checkedOut;	//if in a students book vector

	Book(string, string, int);
	string getTitle() const;
	string getAuthor() const;
	int getNumber() const;
	void display();
};
Book::Book(string name, string auth, int num) {
	title = name;
	author = auth;
	number = num;		//constructor
	checkedOut = false;	//initialize to not checked out
}
string Book::getTitle() const {
	return title;
}
string Book::getAuthor() const {	//getters
	return author;
}
int Book::getNumber() const {
	return number;
}


void Book::display() {
	
	if (!checkedOut)
	{
		cout << title << ",  " << author << ",  " << number << ",  Checked In" << endl;
	}
	else
	{
		cout << title << ",  " << author << ",  " << number << ",  Checked Out" << endl;
	}
}
