
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(NULL), pEndTag(NULL), areTagsSet(false), lastError(UNINITIALIZED) {}

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
		StringParserClass::areTagsSet = false;
	} else {
		StringParserClass::areTagsSet = true;
	}
	
	return StringParserClass::areTagsSet;
}

/*
	

	Input:
		One C string, and one storage vector

	Output:
		Success bool
*/
bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myvector) {
	char * openingTagStart(NULL), openingTagEnd(NULL), closingTagStart(NULL), closingTagEnd(NULL);


	return true;
}

/*

*/
void cleanup() {
	//not sure....
}

/*
	

	Input:
		Three C strings, 1 passed by value, 2 passed by reference
		tagToLookFor : the tag the find in the data, will either be the start or end tag
		start : the position of the '<' char
		end : the position of the '>' char

	Output :
		success bool
*/
bool StringParserClass::findTag(char *tagToLookFor, char *&start, char *&end) {

	return true;
}
