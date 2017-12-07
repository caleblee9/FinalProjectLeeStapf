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
	bool checkedOut;

	Book(string, string, int);
	string getTitle() const;
	string getAuthor() const;
	int getNumber() const;
	void display();
};
Book::Book(string name, string auth, int num) {
	title = name;
	author = auth;
	number = num;
	checkedOut = false;
}
string Book::getTitle() const {
	return title;
}
string Book::getAuthor() const {
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
