//============================================================================
// Name        : RenameFiles.cpp
// Author      : MaskedSylveon
// Version     : 1.0
// Description : Rename files based of two txt files
//============================================================================

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

int main() {

	cout << "Please enter the .txt file has the files that you want to rename:" << endl;
	string originalnames;
	cin >> originalnames;

	cout << "Please enter the .txt file that has the name of the files that you want to rename to:" << endl;
	string newnames;
	cin >> newnames;

	ifstream originalfile; //original file names
	ifstream newfile; //what we want to convert the files to
	originalfile.open(originalnames.c_str());
	newfile.open(newnames.c_str());

	// Check if we successfully opened file.
	if (!originalfile || !newfile) {
		cout << "Error:  Unable to open files for reading." << endl;
		cout << "Exiting program. Good bye!";
		return 1;
	}

	int result = 0;

	//rename the files by line
	while(!originalfile.eof() && !newfile.eof()){
		string oldline; //what the old file names were
		string newline; //what we want to convert the files to
		getline(originalfile,oldline);
		getline(newfile,newline);
		result = rename(oldline.c_str(), newline.c_str());
		if(result == 0) {
			cout << oldline << " has been converted to " << newline << endl;
		}
		else{
			cout << "ERROR! " << oldline << " was not converted to " << newline << endl;
		}
	}

	cout << "Program complete!" << endl;
	return result;
}
