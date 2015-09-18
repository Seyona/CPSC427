/*
	David Baker
	Last Revision : 9/10/2015

	Project 2
	Goals
		- Open and read text file
		- Read ALL words from file counting the number of times each word occurs. Base file name is "TestData.txt"
			-- Special characters are not stripped so Here. and Here are two different words
			-- Also lower case words are not differentiated from their upper case words so again Here and here are two different words
			-- An alphababetized list will be written to a file named "OutPutArray.txt"

	Problem Contraint(s)
		Information must be stored in either a string or array no use of Vector is allowed
*/

#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#define ARRAYSIZE 500

struct entry {
	std::string word;
	int number_occurences;
};

void extractTokensFromLine(std::string &myString, entry arr[ARRAYSIZE]);
void writeToFile(std::string fileName, entry list[ARRAYSIZE]);
void bubbleSort(entry arr[]);

int main() {
	std::string fileName = "TestData.txt";
	std::ifstream myfile (fileName); //attempts to open file  

	bool x_as_input = false;
	bool written = false;

	while (!x_as_input && !written) {
		if (myfile.is_open()) {

			entry list[ARRAYSIZE]; // Probably won't need more than 500 entries

			entry base;
			base.word = " ";
			base.number_occurences = -1;
			// give all array values a base so it is know when a empty entry is found
			for (int i = 0; i < ARRAYSIZE; i++) list[i] = base;
			
			std::string line;
			while (std::getline(myfile, line)) {
				extractTokensFromLine(line, list);
			}

			/* Sort then Write to file */
			bubbleSort(list);
			std::string outFile = "OutputArray.txt";
			writeToFile(outFile, list);
			written = true;
		} else {
			std::cout << "There is no file named " + fileName + '\n' <<
				"please enter a new file name or enter X to exit" << std::endl; 
			std::cin >> fileName;
		
			if (fileName == "X") x_as_input = true;
		}
	}
	
	myfile.close();
	return 0;
}



/*
	Writes the inputed list to a file with the given name
	Return value : Void
*/
void writeToFile(std::string fileName, entry list[ARRAYSIZE]) {
	std::ofstream outFile(fileName);

	for (int i = 0; i < ARRAYSIZE; i++) {
		if (list[i].word.compare(" ") == 0) break;

		std::stringstream ss;
		ss << list[i].word << ": " << list[i].number_occurences;
		std::string out = ss.str();
		outFile << out << '\n';
		ss.clear();
	}

	outFile.close();
}

/*
	Function will look for the token in the list of entries
	if found it will increment list[i].num_occurances
	else it will add it to the next empty spot it finds
	Return value : Void
*/
void processToken(std::string token, entry list[ARRAYSIZE]) {
	int index = 0;
	bool added = false;
	while (index != ARRAYSIZE - 1 && !added) {
		if (list[index].word.compare(token) == 0) { //same word
			list[index].number_occurences++;
			added = true;
		} else if (list[index].word.compare(" ") == 0) { // exausted all words currently in list, token is new word
			list[index].word = token;
			list[index].number_occurences = 1;
			added = true;
		} else {
			index++;
		}
	}
}

/*
	Gets the word from the given line
	Return value : Void
*/
void extractTokensFromLine(std::string &myString, entry arr[ARRAYSIZE]) {
	const char CHAR_TO_SEARCH_FOR = ' ';
	std::stringstream ss(myString);
	std::string tempToken;
	while (std::getline(ss, tempToken, CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken, arr);
	}
}

/*
	Swaps two elements in an array
	Return value : void
*/
void swap(entry arr[ARRAYSIZE], int index) {
	entry temp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = temp;
}

/*
	Takes two strings and returns and integer
	Returns 0 if both strings are equal
	Returns -1 if Str1 < Str2
	Returns 1 if Str1 > Str2
*/
int compare(std::string str1, std::string str2) {
	int size_of_str1 = str1.size();
	int size_of_str2 = str2.size();

	int loop_size = (size_of_str1 >= size_of_str2) ? size_of_str2 : size_of_str1;

	std::locale loc;

	for (int i = 0; i < loop_size; i++) {
		int char1 = std::tolower(str1[i], loc);
		int char2 = std::tolower(str2[i], loc);

		//May need special case when str1 == str2

		if (char1 > char2) {
			return 1; //str 1 has a character later in the alphabet than str2
		}
		if (char1 < char2) {
			return -1; //str 1 has a character sooner in the alphabet than str2
		}
	}
	return 0; //strings are equal
}

/*
	Bubble sorts the list into alphabetical order
	Return value : void
*/
void bubbleSort(entry arr[ARRAYSIZE]) {
	int iter, index;

	for (iter = 0; iter < ARRAYSIZE; iter++) {
		for (index = 0; index < (ARRAYSIZE - iter) - 1; index++) {
			std::string ind1 = arr[index].word;
			std::string ind2 = arr[index + 1].word;
			int comp = compare(ind1, ind2);
			if (comp > 0) {
				if (arr[index + 1].word.compare(" ") != 0) { 
					swap(arr, index);
				}
			}

		}
		
	}
}