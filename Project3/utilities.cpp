/*
	David Baker
	Last Revision : 09/22/2015

	This file holds all the utility functions for project 3, some functions can be used as a template for future functions
*/

#include "utilities.h"

#include <algorithm>
#include <fstream>
#include <math.h>
#include <sstream>

/*
	Reads measurements from the CSV file and puts them into a measurements vector

	Inputs :
		String file name
		Vector of measurements passed by reference
	
	Return Void
*/
void readFromFile(std::string fileName, std::vector<measurement> &readings) {
	std::ifstream file(fileName);

	if (file.is_open()) {

		std::string line;
		while (std::getline(file, line)) {
			measurement input;
			int delimLocation = line.find(',');
			input.index = std::stoi(line.substr(0, delimLocation));
			line.erase(0, delimLocation + 1);
			input.value = std::stoi(line);
			readings.push_back(input);
		}
	}
	else {
		std::cout << "File did not open" << std::endl;
	}
}

/*
	Calculates the mean of the given data set

	Inputs:
		Vector of measurements

	Returns a double
*/
double calculateMean(std::vector<measurement> readings) {
	int sum = 0;
	double mean;
	int total_inputs;
	/*
	for (measurement reading : readings) {
		sum += reading.value;
		total_inputs = reading.index; //last loop through should grab total number of measurements
	}*/

	std::vector<measurement>::iterator iter;
	for (iter = readings.begin(); iter != readings.end(); iter++) {
		sum += (*iter).value;
		total_inputs = (*iter).index;
	}
	
	mean = (double)sum / total_inputs;
	return mean;
}

/*
	Calculates the standard deviation of the given data set

	Inputs:
		Vector of measurments

	Returns a double
*/
double calculateStdDev(std::vector<measurement> readings) {
	double mean = calculateMean(readings);

	int summation = 0;
	int total_inputs;
	for (measurement reading : readings) {
		summation += pow((reading.value - mean), 2);
		total_inputs = reading.index;
	}

	double std_dev = pow(((double)summation / total_inputs), 0.5); //square root 

	return std_dev;
}

/*
	Retrives the total number of readings in the given data set
	Note: readings.size() would also work, but this is more fun

	Inputs:
		Vector of measurements
		
	Returns an int
*/
int getTotalMeasurements(std::vector<measurement> readings) {
	return (*(--readings.end())).index;
}

/*
	Sorts values into one of two vectors, within 1 Standard dev and not within 1 standard dev

	Inputs:
		Vector of measurements
		2 Vectors passed by reference (one for the within1 group and one for the other)

	Returns void
*/
void isWithinOne(std::vector<measurement> readings, std::vector<measurement> &withinOne, std::vector<measurement> &notWithinOne, double mean) {
	for (measurement reading : readings) {
		int val = reading.value;
		if (val == mean || val == mean - 1 || val == mean + 1) {
			withinOne.push_back(reading);
		} else {
			notWithinOne.push_back(reading);
		}
	}
}


/*
	Compares 2 readings returns true if read1 < read2

	Inputs:
		2 const measurements both passed by reference

	Returns True/false
*/
bool compareMeasurements(const measurement &read1, const measurement &read2) {
	return read1.value < read2.value;
}

/*
	Sorts the values in a given vector based on their value

	Inputs:
		Vector of readings passed by reference

	Returns void
*/
void sort(std::vector<measurement> &readings) {
	std::sort(readings.begin(), readings.end(), compareMeasurements);
}


/*
	Writes the given contents to a file

	Inputs:
		2 vectors of measurements passed by value
		1 stats struct 

	Returns void
*/
void print_to_file(std::vector<measurement> withinOne, std::vector<measurement> notWithinOne, stats stat) {
	std::ofstream outFile("OutPut.txt");


	outFile << "Total Measurements:" << stat.totalmeasurements << "\n"
		<< "Mean:              " << stat.mean << "\n"
		<< "Standard Deviation:" << stat.standard_dev << "\n"
		<< "Number within 1 standard deviation  :" << stat.totalMeasurements_withinOneStdDev << "\n";

	for (measurement x : withinOne) {
		std::stringstream ss;
		ss << x.index << " , " << x.value;
		std::string out = ss.str();
		outFile << out << "\n";
		ss.clear();
	}

	outFile << "Number outside 1 standard deviation :" << stat.totalMeasurements_outsideOneStdDev << "\n";

	for (measurement x : notWithinOne) {
		std::stringstream ss;
		ss << x.index << " , " << x.value;
		std::string out = ss.str();
		outFile << out << "\n";
		ss.clear();
	}
	outFile.close();
}