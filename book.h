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
		string getTitle() const;
		string getAuthor() const;
		int getNumber() const;
};
string Book::getTitle() const{
	return title;
}
string Book::getAuthor() const{
	return author;
}
int Book::getNumber() const {
	return number;
}
