#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


class Catalog {
	protected:
		vector<Book> books;	//list of all books from catalog
public:
	Catalog();
	Catalog(string);	//constructors
	Book checkOut(string);
	Book checkOut(int);
	void checkIn(int);
	void checkIn(string);
	void display(void);	//display all books in catalog
	bool bookExists(int);	//check that books are in the catalog
	bool bookExists(string);
	vector<Book> getBooks() const;
};
vector<Book> Catalog::getBooks() const {
	return books;
}
Catalog::Catalog()
{
	Catalog("catalog.txt");	//default
}

Catalog::Catalog(string booklist)
{
	string line;
	string nm;	//title of book
	string auth;	//author
	int num;	//book number

	ifstream catalog_file(booklist);
	while (getline(catalog_file, line, '|'))	
	{
		nm = line;
		getline(catalog_file, line, '|');
		auth = line;
		getline(catalog_file, line);
		num = atoi(line.c_str());
		Book tmp(nm, auth, num);	//make a tmp book
		books.push_back(tmp);		//push tmp book to catalog
	}	
	catalog_file.close();
}
Book Catalog::checkOut(int num) {
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == num) {	//loop through book vector
			if (books[i].checkedOut)
			{
				return Book("NotAvailable","None", 0);	//if checked out
			}
			else
			{
				books[i].checkedOut = true;
				return books[i];
			}
		}
	}
}
Book Catalog::checkOut(string title) {
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			if (books[i].checkedOut)
			{
				return Book("NotAvailable", "None", 0);
			}
			else
			{
				books[i].checkedOut = true;
				return books[i];
			}
		}
	}
}


void Catalog::checkIn(int numberID)
{
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == numberID) {
			books[i].checkedOut = false;
		}
	}
}

void Catalog::checkIn(string title)
{
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == title) {
			books[i].checkedOut = false;
		}
	}
}

void Catalog::display()
{
	int i;
	for (i = 0; i < books.size(); i++)
	{
		books[i].display();	//loop through calling display on all
	}
}

bool Catalog::bookExists(int idNumber)
{
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == idNumber) { 	//loop through and seach for book title
			return true;	//found
		}
	}
	return false;		//doesn't exist
}
bool Catalog::bookExists(string titlecheck)
{
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getTitle() == titlecheck) {
			return true;
		}
	}
	return false;
}
