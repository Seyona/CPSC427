#include <iostream>
#include <string>
#include <vector>

struct measurement {
	int index, value;
	void clear() { index, value; }
};

struct stats {
	double mean;
	double standard_dev;
	double totalmeasurements;
	int totalMeasurements_withinOneStdDev;
	int totalMeasurements_outsideOneStdDev;
	void clear() { mean, standard_dev, totalmeasurements, totalMeasurements_withinOneStdDev, totalMeasurements_outsideOneStdDev; }
};

void readFromFile(std::string fileName, std::vector<measurement> &readings);
double calculateMean(std::vector<measurement> readings);
double calculateStdDev(std::vector<measurement> readings);
int getTotalMeasurements(std::vector<measurement> readings);
void isWithinOne(std::vector<measurement> readings, std::vector<measurement> &withinOne, std::vector<measurement> &notWithinOne, double mean, double std_dev)
void sort(std::vector<measurement> &readings);
void print_to_file(std::vector<measurement> withinOne, std::vector<measurement> notWithinOne, stats stat);

