#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


class Catalog {
	protected:
		vector<Book> books;
public:
	Catalog();
	Catalog(string);
	Book checkOut(string);
	Book checkOut(int);
	void checkIn(int);
	void checkIn(string);
	void display(void);
	bool bookExists(int);
	bool bookExists(string);

};
Catalog::Catalog()
{
	Catalog("catalog.txt");
}

Catalog::Catalog(string booklist)
{
	string line;
	string nm;
	string auth;
	int num;

	ifstream catalog_file(booklist);
	while (!catalog_file.eof())
	{
		getline(catalog_file, line, '|');
		nm = line;
		getline(catalog_file, line, '|');
		auth = line;
		getline(catalog_file, line);
		num = atoi(line.c_str());
		Book tmp(nm, auth, num);
		books.push_back(tmp);
	}
}
Book Catalog::checkOut(int num) {
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == num) {
			if (books[i].checkedOut)
			{
				return Book("NotAvailable","None", 0);
			}
			else
			{
				books[i].checkedOut = true;
				return Book(books[i].getTitle(), books[i].getAuthor(), books[i].getNumber());
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
				return Book(books[i].getTitle(), books[i].getAuthor(), books[i].getNumber());
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
		books[i].display();
	}
}

bool Catalog::bookExists(int idNumber)
{
	int i;
	for (i = 0; i < books.size(); i++) {
		if (books[i].getNumber() == idNumber) {
			return true;
		}
	}
	return false;
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
