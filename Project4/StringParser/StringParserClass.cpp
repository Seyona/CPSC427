
#include <string>
#include "..\Include\StringParserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(NULL), pEndTag(NULL), areTagsSet(false), lastError(ERROR_NO_ERROR) {}
StringParserClass::~StringParserClass() {}

/*
	Function returns the value of lastError

	Input:
		None
	Output:
		int with a value of the error
*/
int StringParserClass::getLastError() {
	int temp = this -> lastError;
	this -> lastError = ERROR_NO_ERROR;
	return temp;
}

/*
	Sets the tag, flags an error if the 2nd index of pEndTag is not /

	Input:
		2 Const char pointers holding the tags

	Output:
		Success boolean
*/
bool StringParserClass::setTags(const char *pStartTag, const char *pEndTag) {
	if (pStartTag != NULL && pEndTag != NULL) { // maybe add a condition that checks for the '\0' char
		this -> pStartTag = (char *)pStartTag;
		this -> pEndTag = (char *)pEndTag;
		this -> areTagsSet = true;
	} else {
		this -> lastError = ERROR_TAGS_NULL;
		this -> areTagsSet = false;
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

	if (!areTagsSet) {
		lastError = ERROR_TAGS_NULL;
		return false;
	}

	while (this -> getLastError() !=  END_OF_DATA || this -> getLastError() != NO_TAG_FOUND) {
		if ((pDataToSearchThru != NULL) | (*(pDataToSearchThru) != '\0')) {
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

		good = this -> findTag( this -> pEndTag, pClosingTagStart, pClosingTagEnd);
	
		if (!good) break;

		

		std::string data("");

		char * pc;

		for (pc = (++pOpeningTagEnd); pc != pClosingTagStart; pc++) { //just want the data between the end of the starting tag and the start of the closing tag
			data += *(pc);
		}
		myvector.push_back(data);
		
		//maybe delete the defined pointers? No issue assigning pDataToSearchThru to a new pointer bc it was passed by value 

		pDataToSearchThru = pClosingTagEnd; //we have already searched through all the other data before pClosingTagEnd might as well be the new starting point
	}
	//okay so this is a good start, but what if there are multiple opening and closing tag pairs, probably should 
	// refactor lines 74 to 117 into a while loop that says something like
			// while (findTags) since find tags will work until an invalid tag is found, but we can talk about that

	return myvector.empty();
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
		start : the data's current pointer location
		end : the data's current pointer location + (the size of the tag - 1)

	Output :
		success bool

	After the function:
		Start will be the starting character of the tag
		End will be the last character of the tag
*/
bool StringParserClass::findTag(char *tagToLookFor, char *&start, char *&end) {
	//This method seems like a helper class to find tags in the data returning their starting and ending position
	
	bool tagFound = false;//a tag is found when start == '<' and end == '>' and the data between matches
	char * temp = tagToLookFor;

	while (*(temp) != '\0') temp++;
	
	char startChar = *(tagToLookFor);
	char endChar = *(--temp);

	if (this -> areTagsSet) //shouldn't happen anymore since there is a check before calling thsi function
	{
		temp = tagToLookFor;
		while (	!tagFound ) {
			if ( *(start) == startChar && *(end) == endChar) {
				//don't need the < at the start of the tag
				char * pStartOfTag = start;
				char * pEndOftag = end;

				while (pStartOfTag != pEndOftag) { // might need to deref these here, but i don't think so?
					if (*(pStartOfTag) != *(temp)) {
						tagFound = false;
						break; //time to look again
					}
					pStartOfTag++;
					temp++;
					tagFound = true;
				}
			} else {
				temp = tagToLookFor;
				start++;
				end++;
			}

			if (*start == '\0' || *end == '\0') { // in this case start should never == '0', but it is a just in case8
				this -> lastError = END_OF_DATA; //hit null term character no more data never found last tag
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
		this -> lastError = NO_TAG_FOUND; //tags were not found
		return false;
	}

	return true;
}
