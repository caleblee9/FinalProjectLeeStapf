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
		int number;		//book ID number, used for determining what books students have
	public:
		Book(string, string, int);	//constructor
		string getTitle() const;	//getters
		string getAuthor() const;
		int getNumber() const;
		void display();			//display the book information
};
Book::Book(string name, string auth, int num) {
	title = name;
	author = auth;
	number = num;
}
string Book::getTitle() const{
	return title;
}
string Book::getAuthor() const{		//getters
	return author;
}
int Book::getNumber() const {
	return number;
}
void Book::display() {
	cout << title << " " << author << " " << number << endl;
}
