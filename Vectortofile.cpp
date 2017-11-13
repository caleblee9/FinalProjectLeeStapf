//============================================================================
// Name        : Vectortofile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include "book.h"
#include <stdlib.h>


using namespace std;

int main() {

	vector<Book>catalog;
	ifstream catalog_file("catalog.txt");
	string line;
	string nm;
	string auth;
	int num;
	while(!catalog_file.eof())
	{
		getline(catalog_file, line, '|');
		nm = line;
		getline(catalog_file, line, '|');
		auth = line;
		getline(catalog_file, line);
		num = atoi(line.c_str());
		Book tmp(nm, auth, num);
		catalog.push_back(tmp);
	}

	int i;

	for(i=0;i<catalog.size();i++)
	{
		catalog[i].display();
	}

	return 0;

}
