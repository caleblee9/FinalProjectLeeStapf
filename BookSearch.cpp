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
	cin >> search;

	if (catalog.is_open())
	{
		while (!catalog.eof())
		{
			getline(catalog, line);

			if ((offset = line.find(search, 0)) != string::npos)
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
	system("PAUSE");

	return 0;

}
