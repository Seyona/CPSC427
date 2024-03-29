#include "..\includes\String_Database.h"
#include <algorithm>
#include <thread>
#include <iostream>

/** Private Variables
	std::mutex mutex;
	std::vector<String_Data> myStrings;
	std::vector<String_Data>::iterator  myStringsIter;
*/

/**
* Constructor for the String_Database class
*/
String_Database::String_Database(void)
{
}

/**
* Deconstructor for the String_Database class
*/
String_Database::~String_Database(void)
{
}

/**
* Adds the string data to the myStrings vector if it is not already in the vector.
* If the string data is already in the vector then that corrisponding element is incrimented
*/
void String_Database::add(std::string &myString)
{
	std::lock_guard<std::mutex> lock(mutex);

	bool stringExists = false;
	String_Data data_to_add (myString, 1);
	
	for(this->myStringsIter = this->myStrings.begin(); this->myStringsIter != this->myStrings.end(); this->myStringsIter++) {
		if ((*this->myStringsIter) == data_to_add) {
			stringExists = true;
			myStringsIter->increment();
			break;
		}
	}

	if(!stringExists) {
		myStrings.push_back(data_to_add);
	}
}


/**
* Returns the count of the corrisponding string_data object with the passed in string
*/
int String_Database::getCount(std::string &myString)
{
	std::lock_guard<std::mutex> lock(mutex);

	int strCount = 0;

	String_Data data_to_get_count (myString, 1);
	for (this->myStringsIter = myStrings.begin(); this->myStringsIter != myStrings.end(); this->myStringsIter++) {
		if ((*myStringsIter) == data_to_get_count) {
			strCount = myStringsIter -> getCount();
			break;
		}
	}

	return strCount;
}

/**
* clears the vector holding String_Data
*/
void String_Database::clear()
{
	std::lock_guard<std::mutex> lock(mutex);
	myStrings.clear();
}

/**
* Loads the data from the DataStore Object into the myStrings vector
* This method uses the DataStore load function to add the String_Data to the myStrings vector
*/
bool String_Database::load(DataStore  *myDataStore)
{
	std::lock_guard<std::mutex> lock(mutex);
	return myDataStore -> load(myStrings);
	
}

/**
* Saves the data from the myStrings vector into the DataStore object
* This uses the DataStore save function to save the strings to the DataStore object
*/
bool String_Database::save(DataStore *myDataStore)
{
	
	std::lock_guard<std::mutex> lock(mutex);
	return myDataStore -> save(myStrings);

}

