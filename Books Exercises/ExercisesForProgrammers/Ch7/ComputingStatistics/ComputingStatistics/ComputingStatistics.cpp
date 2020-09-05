#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

void getNumbersFromFile(vector<double>& number);
void print(const vector<double>& number);
double mean(const vector<double>& number);
void max(const vector<double>& number);
void min(const vector<double>& number);
void standardDeviation(const vector<double>& number, const double & mean);

int main()
{
	vector<double> number;
	double meanValue;

	getNumbersFromFile(number);
	print(number);
	meanValue = mean(number);
	max(number);
	min(number);
	standardDeviation(number, meanValue);
}

void print(const vector<double>& number) {
	for (auto i : number)
		cout << i << ", ";
	cout << endl;
}

double mean(const vector<double>& number) {
	double mean = std::accumulate(number.begin(), number.end(), 0) / number.size();
	cout << "The mean is:" << mean << endl;
	return mean;
}

void min(const vector<double>& number) {
	cout << "The minimum is:" << *min_element(number.begin(), number.end()) << endl;
}

void max(const vector<double>& number) {
	cout << "The maximum is:" << *max_element(number.begin(), number.end()) << endl;
}

void standardDeviation(const vector<double>& number, const double& mean) {
	vector<double> squaredMeans;

	for (auto i : number) {
		squaredMeans.push_back(pow(i - mean, 2));
	}

	cout << "The standard deviation is " << sqrt(std::accumulate(squaredMeans.begin(), squaredMeans.end(), 0) / squaredMeans.size()) << endl;

}

void getNumbersFromFile(std::vector<double>& number)
{
	ifstream numberSource;
	double input;

	numberSource.open("numbers.txt");

	if (!numberSource.is_open())
	{
		cout << "Could not open numbers.txt" << endl;
		exit(1);
	}
	cout << "Getting number from file." << endl;

	while (numberSource >> input) {
		cout << "Reading: " << input << endl;

		number.push_back(input);
	}
	cout << endl;
	numberSource.close();
}
