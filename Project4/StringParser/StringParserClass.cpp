
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(0), pEndTag(0), areTagsSet(false), lastError(UNINITIALIZED) {}

/*
	Function returns the value of lastError

	Input:
		None
	Output:
		int with a value of the error
*/
int StringParserClass::getLastError() {
	return StringParserClass::lastError;
}

/*
	Sets the tag, flags an error if the 2nd index of pEndTag is not /

	Input:
		2 Const char pointers holding the tags

	Output:
		Success boolean
*/
bool StringParserClass::setTags(const char *pStartTag, const char *pEndTag) {
	StringParserClass::pStartTag = (char *)pStartTag;
	StringParserClass::pEndTag = (char *)pEndTag;

	if(StringParserClass::pEndTag[1] != '/') {
		StringParserClass::lastError = ERROR_TAGS_NULL;
		return false;
	}
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
