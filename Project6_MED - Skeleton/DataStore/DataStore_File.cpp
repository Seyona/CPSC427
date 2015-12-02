#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../includes/DataStore_File.h"

DataStore_File::DataStore_File(std::string fname, Crypto* myCrypt):myFileName(fname), myCrypto(myCrypt){}
DataStore_File::~DataStore_File(void){}

bool DataStore_File::load(std::vector<String_Data> &myVec) {
	std::fstream file;
	this->openFile(file, myFileName);

	if (file.is_open()) {
		std::string line;
		 while (std::getline(file,line) ) {
			std::string data("");
			int useCount = 0;
			DataStore::decrypt(line); //decrypt the line
			String_Data::parseData(line, data, useCount);
			String_Data toVec(data,useCount);

			myVec.push_back(toVec);
		 }
		 this->closeFile(file);
	} else {
		return false;
	}
	return true;
}

bool DataStore_File::save(std::vector<String_Data> &myVec) {
	std::fstream file;
	this->openFile(file, myFileName);

	if (file.is_open()) {
		for (String_Data data : myVec) {
			std::string serializedData = data.serialize();
			DataStore::encrypt(serializedData);
			file >> serializedData;
		}
		this->closeFile(file);
	} else {
		return false;
	}
	return true;
}

bool DataStore_File::openFile(std::fstream& myfile,const std::string& myFileName, std::ios_base::openmode mode=std::ios_base::in) {
	if (this->myFileName != "") {
		myfile(myFileName); //open the file, currently throws an error
	} else {
		return false;
	}
}

void DataStore_File::closeFile(std::fstream& myfile) {
	myfile.close(); //this is throwing an error >.>
}