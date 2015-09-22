/*
	David Baker
	Last Revision : 09/22/2015

	Goal:
		* Create a program that will read a file of data 
			- Format of data
				-- Measurement Number,Measurement Value \n
		* From the given data Calculate the following
			- Mean
			- Standard Deviation
			- Total number of measurements
			- All data that is within one Standard deviation of the mean
			- All data that is not within one Standard deviation of the mean
		* Write the calculated data to a file
	
	Contraint(s):
		Must use iterators to access the elements of a container, not [] notation
		Must have a utilities.cpp/.h files
*/

#include "utilities.h"

int main() {
	std::vector<measurement> readings, withinOne, notWithinOne;
	stats out_stats;

	//Get information from file
	readFromFile("TestData.txt", readings);

	out_stats.mean = calculateMean(readings);
	out_stats.standard_dev = calculateStdDev(readings);
	out_stats.totalmeasurements = getTotalMeasurements(readings);

	isWithinOne(readings, withinOne, notWithinOne, out_stats.mean);

	out_stats.totalMeasurements_withinOneStdDev = withinOne.size();
	out_stats.totalMeasurements_outsideOneStdDev = notWithinOne.size();

	readings.clear(); //no longer need readings

	sort(withinOne);
	sort(notWithinOne);
	
	print_to_file(withinOne, notWithinOne, out_stats);

	withinOne.clear();
	notWithinOne.clear();

	return 0;
}