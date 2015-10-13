//============================================================================
// Name        : Proj4_Test.cpp
// Author      : David Baker, Jake Hayhurst
// Version     : 1.0.0
// Copyright   : Don't copy this. 10/11/2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "..\Include\FileReader.h"	//relative path, from PWD, go up one, then down into Include to find FileReader.h
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
#include "..\Include\stringparserclass.h"

void outputvectorrow(std::string i){
	std::cout<<i<<std::endl;
}
void foreach(std::vector<std::string> myVector){
	std::for_each(myVector.begin(), myVector.end(), outputvectorrow);
}

int main(){
	//TODO open file, if not there ask for a different file or exit
	bool exit = false;
	std::string fname ("");
	std::cout << "Enter a file name to open, or X to exit the program" ;
	std::cin >> fname;

	KP_FileReaderClass::FileReader reader = KP_FileReaderClass::FileReader::FileReader();
	std::string contents("");

	int success = reader.getFileContents(fname, contents);

	while(success != SUCCEEDED && fname != "X" && success != USER_CHOSE_TO_EXIT) { //fname != "X" should be a redundent statement, but will be used for now.
		std::cout << "There is no file named " << fname << ". Enter a new file name or X to exit the program";
		std::cin >> fname;
		success = reader.getFileContents(fname, contents);
	}
	if (success == USER_CHOSE_TO_EXIT) return USER_CHOSE_TO_EXIT;

	if (success != 0) return success; // only error could be a could not open file error,that should not happened
	//got file data, this is a bogus time and memory wasting step
	
	//whose sole purpose is to provide a way to pass
	//in a non const pointer to getDataBetweenTags(..) without casting
	/*vector<char> myLine;
	std::copy(filecontents.begin(), filecontents.end(), back_inserter(myLine));*/

	//TODO  create an instance of the stringparser

	//TODO set the tags

	//TODO pull out the data

	//TODO  write to file and to screen

}



