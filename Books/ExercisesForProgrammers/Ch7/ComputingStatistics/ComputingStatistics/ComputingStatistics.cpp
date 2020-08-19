#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

void promptForNumbers(string& input, vector<double>& number);
void print(const vector<double>& number);
double mean(const vector<double>& number);
void max(const vector<double>& number);
void min(const vector<double>& number);
void standardDeviation(const vector<double>& number, const double & mean);

int main()
{
	vector<double> number;
	double meanValue;
	string input;

	promptForNumbers(input, number);
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

void promptForNumbers(std::string& input, std::vector<double>& number)
{
	while (true)
	{
		cout << "Enter a number: ";
		cin >> input;

		if (input == "done")
			break;

		number.push_back(stoi(input));
	}
}
