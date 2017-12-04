//============================================================================
// Name        : BookSearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<string>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

int main()
{
	string search;
	int offset;
	string line;
	int count = 0;

	ifstream catalog;
	catalog.open("catalog.txt");

	cout << "What book would you like to search for?" << endl;
	getline(cin, search);

	if (catalog.is_open())
	{
		while (!catalog.eof())
		{
			getline(catalog, line, '|');

			if (search == line)
			{
				count = 1;
				if(count == 1)
				{
					cout << "The book is in the catalog" << endl;
					break;
				}
			}

		}
		catalog.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}
	return 0;

}
