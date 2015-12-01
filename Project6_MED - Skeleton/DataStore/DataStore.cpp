#include <string>
#include <thread> 
#include "DataStore.h"
#include "../includes/Crypto_AES.h"

//this is a comment
DataStore::DataStore(Crypto* myCrypt):myCrypto(myCrypt){}
DataStore::~DataStore(void){}

bool DataStore::encrypt(std::string &str) {
	bool complete = false;

	if (this->myCrypto != NULL) {
		//do stuff
		(*myCrypto).encrypt(str);// string now encrypted
		complete = true;
	} else {
		// do nothing 
		complete = true;
	}

	return complete;
}

bool DataStore::decrypt(std::string &str){
	bool complete = false;

	if (this->myCrypto != NULL) {
		(*myCrypto).decrypt(str); //string decrypted
		complete = true;
	} else {
		//do nothing
		complete = true;
	}
	return complete;
}