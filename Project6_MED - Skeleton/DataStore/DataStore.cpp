#include <string>
#include <thread> 
#include "DataStore.h"
#include "../includes/Crypto_AES.h"

/**
 * Constructor takes a myCrypt object and assigns it as class field
 * If no cyrpt object is passed, it is a assigned a null value
 */
DataStore::DataStore(Crypto* myCrypt):myCrypto(myCrypt) {}

DataStore::~DataStore(void){}

/**
 * @protected
 * Called by save method to encript data being stored.
 * Assumes myCrypto is not null, however will not throw error or return false otherwise.
 *
 * @return boolean true on completion of function scope.
 */
bool DataStore::encrypt(std::string &str) {

	bool complete = true;

	// encrypt string only if crypto object exists
	if(this->myCrypto != NULL) {
		(*myCrypto).encrypt(str);
		return complete;
	}

	return complete;
}

/**
* @protected
* Called by load method to decrypt data being retrieved.
* Assumes myCrypto is not null, however will not throw error or return false otherwise.
*
* @return boolean true on completion of function scope.
*/
bool DataStore::decrypt(std::string &str) {

	bool complete = true;

	// encrypt string only if crypto object exists
	if (this->myCrypto != NULL) {
		(*myCrypto).decrypt(str);
		return complete;
	}

	return complete;
}

/**
 * Iterates through vector of String_Data passed, decrypting each string
 */
bool DataStore::load(std::vector<String_Data>& myVector) {
	
	for(std::vector<String_Data>::iterator vectorData = myVector.begin(); vectorData != myVector.end(); vectorData++) {
		decrypt(vectorData->serialize());
	}

	return true;

}

/**
* Iterates through vector of String_Data passed, encrypting each string
*/
bool DataStore::save(std::vector<String_Data>& myVector) {

	for(std::vector<String_Data>::iterator vectorData = myVector.begin(); vectorData != myVector.end(); vectorData++) {
		encrypt(vectorData->serialize());
	}

	return true;

}