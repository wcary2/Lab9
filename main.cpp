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

void writeFile(ofstream & file, map<string, int> & tally);
void readFile(fstream & file, map<string, int> & tally);

int main() {
	fstream file;
	string nameFile;
	map<string, int> tally;


	do {
		cout << "Please enter file name: ";
		cin >> nameFile;
		file.open(nameFile);
	} while (!file.is_open());

	readFile(file, tally);
	file.close();
	ofstream outputFile("output.txt");
	writeFile(outputFile, tally);

	return 0;
}

void writeFile(ofstream & file, map<string, int> & tally) {
	for (map<string, int>::iterator it = tally.begin(); it != tally.end(); it++) {
		string s = it->first;
		int i = it->second;
		while (i > 0) {
			i--;
			file << s << " ";
		}
	}
}

void readFile(fstream & file, map<string, int> & tally) {
	string input;
	while (file >> input) {
		++tally[input];
	}
}