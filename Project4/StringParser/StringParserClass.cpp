
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(0), pEndTag(0), areTagsSet(false), lastError(UNINITIALIZED) {}

/*

*/
int StringParserClass::getLastError() {
	
	return ERROR_NO_ERROR;
}

/*

*/
bool StringParserClass::setTags(const char *pStartTag, const char *pendTag) {

	return true;
}

/*
	

	Input:
		One C string, and one storage vector

	Output:
		Success bool
*/
bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myvector) {
	
	return true;
}

/*
	Sets the last error to the given error int

	Input : 
		reference to an Int

	Output :
		Nothing
*/
void StringParserClass::setError(int &err) {
	StringParserClass::lastError = err;
}

/*

*/
void cleanup() {
	//not sure....
}

/*


	Input:
		One C string, and two char's pointers passed by reference

	Output :
		success bool
*/
bool StringParserClass::findTag(char *tagToLookFor, char *&start, char *&end) {

	return true;
}
