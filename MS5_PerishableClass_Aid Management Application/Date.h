/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
*/

#ifndef ama_DATE_H_
#define ama_DATE_H_

#include <iomanip>

namespace ama {
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date {
		int year_, month_, day_, status_;		

		//private member function
		void status(int newStatus); // sets the status of the date object to the value of the parameter
		void status(int year, int month, int day); //check if the year, month and day are valid
		int mdays(int year, int mon) const;	 // find the number od days in a given month for a given year	

	public:
		Date(); //defalt constructor
		Date(int year, int month, int day); //constructor with three parameters
		
		int status() const; //returns an integer representing the status of the current object.
		void clearError(); //resets the status of an object to no_error
		bool isGood(); //return true if status_ == no_error and if the date is not in the safe empty state
		

		Date& operator+=(int days); //adds to the date stored by the object the number of days specified in the parameter
		Date& operator++(); //adds one day to the date stored by the object (prefix)
		Date operator++(int); //that adds one day to the date stored by the object (postfix)
		Date operator+(int days); //adds to the date stored by the object the number of days specified in the parameter
		
		bool operator==(const Date& rhs) const; //check if two date objects store the same date
		bool operator!=(const Date& rhs) const; //check if two date objects store different dates 
		bool operator<(const Date& rhs) const; //check if the current object stores a date that is before the date stored in rhs 
		bool operator>(const Date& rhs) const; //check if the current object stores a date that is after the date stored in rhs 
		bool operator<=(const Date& rhs) const; //check if the current object stores a date that is before or equal to the date stored in rhs 
		bool operator>=(const Date& rhs) const; //check if the current object stores a date that is after or equal to the date stored in rhs

		Date read(std::istream& is); //reads from an input stream a date in the following format: YYYY?MM?DD 
		std::ostream& write(std::ostream& os) const; //writes the date to an std::ostream object in the following format: YYYY/MM/DD
	};

	std::ostream& operator<<(std::ostream& os, const Date&);  //Prints the date to the first parameter
	std::istream& operator>>(std::istream& is, Date&);  //Reads the date from the first parameter 
}

#endif
