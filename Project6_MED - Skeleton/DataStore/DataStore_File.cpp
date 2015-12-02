#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../includes/DataStore_File.h"

/**
 * Constructor takes a filename to use as data store, populates myCrypto class
 * field with crypt object passed. If crypto object is not null, all data saved to
 * file will be encrypted using this object, and decrypted when loading from it.
 */
DataStore_File::DataStore_File(std::string fname, Crypto* myCrypt = 0):myFileName(fname), myCrypto(myCrypt) {}

DataStore_File::~DataStore_File(void){}

/**
 * @private
 * Opens a filestream from a reference. Mode defaults to write only.
 */
bool DataStore_File::openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode = std::ios_base::in) {
	
	myfile = std::fstream(myFileName);
	
	if(!myfile) {
		return false;
	}

	return true;
}

/**
* @private
* Closes filestream passed.
*/
void DataStore_File::closeFile(std::fstream& myfile) {
	myfile.close();
}

/**
* Load data stored in file myFileName to myVec.
* If cryptoObject is not null, each String_Data line is
* serialized and encrypted before being saved.
*/
bool DataStore_File::load(std::vector<String_Data> &myVec) {

	std::fstream file;
	this->openFile(file, myFileName);

	if(!file || !file.is_open()) {
		return false;
	}

	std::string line;
	while(std::getline(file, line)) {

		std::string parsedString("");

		int useCount = 0;

		DataStore::decrypt(line);
		String_Data::parseData(line, parsedString, useCount);
		String_Data stringData(parsedString, useCount);

		myVec.push_back(stringData);
	}

	this->closeFile(file);

	return true;
}

/**
 * Save data stored in vector of String_Data to filename passed at
 * class instantiation. If cryptoObject is not null, each String_Data line is
 * serialized and encrypted before being saved.
 */
bool DataStore_File::save(std::vector<String_Data> &myVec) {

	std::fstream destFile;
	this->openFile(destFile, this->myFileName);

	if(!destFile || !destFile.is_open()) {
		return false;
	}

	for(String_Data dataString : myVec) {

		std::string serializedData = dataString.serialize();
		DataStore::encrypt(serializedData);

		destFile << serializedData << std::endl;

	}

	this->closeFile(destFile);
	return true;

}