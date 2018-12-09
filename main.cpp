/*
** William Cary
** Lab 9: using map in stl
** Dev 10, 2018
** COMPSCI 2030 UWYO 
**
*/


#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main() {
	fstream file;
	string nameFile;
	map<string, int> tally;


	do {
		cout << "Please enter file name: ";
		cin >> nameFile;
		file.open(nameFile);
	} while (file.is_open());

	readFile(file, tally);
	file.close();

	writeFile(file, tally);

	return 0;
}

void writeFile(fstream & file, map<string, int> & tally) {
	
}

void readFile(fstream & file, map<string, int> & tally) {
	string input;
	while (file >> input) {
		++tally[input];
	}

}