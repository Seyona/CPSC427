
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
	char * pOpeningTagStart(NULL), * pOpeningTagEnd(NULL), * pClosingTagStart(NULL), * pClosingTagEnd(NULL);
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



	while (this -> getLastError != ERROR_DATA_NULL || this -> getLastError != ERROR_TAGS_NULL) {
		if (pDataToSearchThru != NULL) {
			pOpeningTagStart = pDataToSearchThru; //start of pDataTosearchThru
		} else {
			this -> lastError = ERROR_DATA_NULL;
			return false;
		}

		int tagSize = 0;

		const char* startTag = this -> pStartTag;

		while ( *(startTag) != '\0') { //null char 
			tagSize++;
			startTag++;
		}

		pOpeningTagEnd = pOpeningTagStart + (tagSize - 1); // the end of the tag will be tagSize - 1 away from the start tag <to>'s start is 3 away from '<' 

		// might need check if pOpeningTagEnd is getting set to a valid character... Throw datanull error if not? 

		bool good = this -> findTag( this->pStartTag, pOpeningTagStart, pOpeningTagEnd);

		if (!good) break;

		pClosingTagStart = pOpeningTagEnd;
	
		const char * endTag = this -> pEndTag;
		tagSize = 0;

		while ( *(endTag) != '\0') {
			tagSize++;
			endTag++;
		}

		pClosingTagEnd = pClosingTagStart + (tagSize - 1);

		good = this -> findTag( this -> pEndTag, pOpeningTagStart, pOpeningTagEnd);
	
		if (!good) break;

		std::string data("");

		char * pc;

		for (pc = pOpeningTagStart; pc != pOpeningTagEnd; pc++) {
			data += *(pc);
		}
		data += *(pc); //doesn't get the '>' of the tag since that is the cutoff point
	}
	//okay so this is a good start, but what if there are multiple opening and closing tag pairs, probably should 
	// refactor lines 74 to 117 into a while loop that says something like
			// while (findTags) since find tags will work until an invalid tag is found, but we can talk about that


	/*if (areTagsSet){	
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
	*/
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
	
	bool tagFound = false;//a tag is found when start == '<' and end == '>' and the data between matches

	if (this -> areTagsSet)
	{
		while (	!tagFound ) {
			if ( *(start) == '<' && *(end) == '>') {
				//don't need the < at the start of the tag
				char * pStartOfTag = start;
				char * pEndOftag = end;

				while (pStartOfTag != pEndOftag) { // might need to deref these here, but i don't think so?
					if (*(pStartOfTag) != *(tagToLookFor)) {
						tagFound = false;
						break; //time to look again
					}
					pStartOfTag++;
					tagToLookFor++;
					tagFound = true;
				}
			} else {
				start++;
				end++;
			}

			if (*start == '\0' || *end == '\0') { // in this case start should never == '0', but it is a just in case8
				this -> lastError = ERROR_DATA_NULL; //hit null term character no more data
				return false;
			}
		}
	}
	else
	{
		this -> lastError = ERROR_TAGS_NULL;
		return false;
	}

	if(!tagFound) {
		this -> lastError = ERROR_TAGS_NULL; //tags were not found
		return false;
	}

	return true;
}
