
#include <string>
#include "..\Include\StringParserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(NULL), pEndTag(NULL), areTagsSet(false), lastError((int)UNINITIALIZED) {}
StringParserClass::~StringParserClass() {}

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
	this -> pStartTag = (char *)pStartTag;
	this -> pEndTag = (char *)pEndTag;

	if(this -> pEndTag[1] != '/') {
		this -> lastError = ERROR_TAGS_NULL;
		this -> areTagsSet = false;
	} else {
		this -> areTagsSet = true;
	}
	
	return this -> areTagsSet;
}

/*
	

	Input:
		One C string, and one storage vector

	Output:
		Success bool
*/
bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myvector) {
	char * openingTagStart(NULL), openingTagEnd(NULL), closingTagStart(NULL), closingTagEnd(NULL);
	// see if you can cast it as a string

	/*
			These are just notes we can talk about it later...

			when iterating over the data to find the start and end points of a tag let
				Start = CurrentPointerPos
				End = CurrentPointerPos + sizeOfTag-1

				then when start is a '<' and end is a '>' we can check the inside of the tag to see if it is what we want
				and then we search for the ending tag position the difference new start is the end of the last tag. then we collect data until we reach another 
				scenario where start is a '<' and end is a '>' and if it is the tag we are looking for exit out we have our data. else keep going.
	*/

	if (areTagsSet){	


		for (char* it = pDataToSearchThru; *it; ++it)
		{
			//fucking john madden
		}
	}
	else
	{
		StringParserClass::lastError = ERROR_TAGS_NULL;
		return false;
	}
	return true;
}

/*

*/
void StringParserClass::cleanup() {
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
	//This method seems like a helper class to find tags in the data returning their starting and ending position
	
	if (areTagsSet)
	{
		//fucking john madden
	}
	else
	{
		this -> lastError = ERROR_TAGS_NULL;
		return false;
	}

	return true;
}
