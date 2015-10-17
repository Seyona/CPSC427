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

void printToScreen(std::vector<std::string> &data);
int printToFile(std::vector<std::string> &data, std::string fname);

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

	// create an instance of the stringparser
	KP_StringParserClass::StringParserClass parser = KP_StringParserClass::StringParserClass::StringParserClass();
	
	// set the tags
	std::string tag1(""), tag2("");
	std::cout << "What tags do you want to search between";
	std::cin >> tag1;
	std::cin >> tag2;

	const char * ctag1(tag1.c_str());
	const char * ctag2(tag2.c_str());

	std::cout << " Will pull data between " << ctag1 << " and " << ctag2 << std::endl;
	bool tagsSet = parser.setTags(ctag1, ctag2);  // tags set

	if (!tagsSet) return parser.getLastError(); // if tags failed, terminate program and return error type



	//TODO pull out the data
	std::vector<std::string> data;
	char * c_contents = (char *)contents.c_str();

	bool dataRetrieved = parser.getDataBetweenTags(c_contents, data);
	//TODO  write to file and to screen
	if (dataRetrieved) {
		if (printToFile(data, OUTPUTFILENAME) != SUCCEEDED) {
			printToScreen(data);
		} else {
			std::cout << "Could not print to file" << std::endl;
		}
	} else {
		std::cout << "Data could not be retrieved" << std::endl;
	}
}


void printToScreen(std::vector<std::string> &data) {
	for (std::string str : data) {
		std::cout << str << " " ;
	}
	std::cout << std::endl;
}

int printToFile(std::vector<std::string> &data, std::string fname) {
	std::ofstream file(fname);

	if (file.is_open()) {
		// Will fix format for printing later
		for (std::string str : data) {
			file <<  str << " ";
		}
	} else {
		return COULD_NOT_OPEN_FILE;
	}

	return SUCCEEDED;
}


