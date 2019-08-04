// Date: 2019/feb/25
// Author: Youngeun Hong(ID: 159100171)

#include<iostream>

// TODO: header file guard
#ifndef sict_Fraction_H
#define sict_Fraction_H
using namespace std;

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

		//at-home part
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);

	};
}

#endif