// Date: 2019/feb/25
// Author: Youngeun Hong(ID: 159100171)

// TODO: insert header files
#include<iostream>
#include"Fraction.h"

// TODO: continue the namespace
using namespace std;

namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int denom) {
		if (num >= 0 && denom > 0) {
			numerator = num;
			denominator = denom;
			reduce();
		}

		else {
			*this = Fraction();
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		int tmp;
		if (numerator > denominator) {
			tmp = numerator;
		}
		else {
			tmp = denominator;
		}
		return tmp;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		int tmp;
		if (numerator < denominator) {
			tmp = numerator;
		}
		else {
			tmp = denominator;
		}
		return tmp;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int a = gcd();
		numerator = numerator / a;
		denominator = denominator / a;
	}

	// TODO: implement the display query
	void Fraction::display() const {

		if (denominator != 1 && denominator > 0) {
			cout << numerator << "/" << denominator;
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << "no fraction stored";
		}
	}


	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		int tmp;
		if (numerator == 0 || denominator == 0) {
			tmp = true;
		}
		else {
			tmp = false;
		}

		return tmp;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) const {
		Fraction tmp;
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			tmp.numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
			tmp.denominator = this->denominator * rhs.denominator;
			tmp.reduce();
		}

		return tmp;
	}

	//at-home part
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction tmp;
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			tmp.numerator = this->numerator * rhs.numerator;
			tmp.denominator = this->denominator * rhs.denominator;
			tmp.reduce();
		}
		return tmp;
	}


	bool Fraction::operator==(const Fraction& rhs) const {
		bool tmp = this->isEmpty() && rhs.isEmpty();

		if (tmp || *this != rhs) {
			tmp = false;
		}

		else {
			tmp = true;
		}

		return tmp;
	}

	bool Fraction::operator!=(const Fraction& rhs) const {

		bool tmp = this->isEmpty() && rhs.isEmpty();

		if (tmp || *this == rhs) {
			tmp = false;
		}

		else {
			tmp = true;
		}

		return tmp;
	}

	Fraction Fraction::operator+=(const Fraction& rhs) {
		
		Fraction tmp;
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			
			*this = (*this + rhs);
			tmp = *this;

		} else{
			tmp = *this;
		}

		return tmp;
	
			 		
	}	
}
	