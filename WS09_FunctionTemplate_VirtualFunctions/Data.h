/// OOP244 Workshop 9: Function Templates
// File: ws9_home.cpp
// Version: 2.0
// Date: 2019/ 4/ 1
// Author: Youngeun Hong
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////

#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <sstream>
#include <cstring>

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH = 15;
	const int SMALLEST = 0;
	const int LARGEST = 1000000000;

	// max returns the largest item in data
	//
	template<class T>
	T max(const T* data, int n) {
		T max = LARGEST;
		for (int i = 0; i < n; i++) {
			if (i == 0 && data[i] >= SMALLEST && data[i] <= LARGEST) {
				max = data[i];
			}
			else {
				if (data[i] > max && data[i] >= SMALLEST && data[i] <= LARGEST) {
					max = data[i];
				}
			}
		}
		return max;
	}


	// min returns the smallest item in data
	//
	template<class T>
	T min(const T* data, int n) {
		T min = SMALLEST;
		for (int i = 0; i < n; i++) {
			if (i == 0 && data[i] >= SMALLEST && data[i] <= LARGEST) {
				min = data[i];
			}
			else {
				if (data[i] < min && data[i] >= SMALLEST && data[i] <= LARGEST) {
					min = data[i];
				}
			}
		}
		return min;
	}

	// sum returns the sum of n items in data
	//  
	template<typename T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}

		return sum;
	}

	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		double tmp;
		tmp = static_cast<double>(sum(data, n)) / n ;
		return tmp;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		bool tmp = true;
		
		for (int i = 0; i < n && !input.fail(); i++) {

			input.ignore();
			input >> data[i];
			if (input.fail() || data[i] > 1000000000 || data[i] < 0) {
				tmp = false;
			}
		}
		return tmp;
	}

	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout << std::right << name;

		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH);
			std::cout << std::right << data[i];
		}
		std::cout << std::endl;
	}

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


#endif
