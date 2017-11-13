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
using namespace std;

int main() {

	vector<string>catalog;
	ifstream catalog_file("catalog.txt");
	string line;

	while(getline(catalog_file, line))
	{
		string new_line;
		new_line = line + "\n";
		catalog.push_back(new_line);
	}

	int i;

	for(i=0;i<catalog.size();i++)
	{
		cout << catalog[i] << endl;
	}

	return 0;

}
