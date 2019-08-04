/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
*/

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

namespace ama {
		
	// private functions

	// sets the status of the date object to the value of the parameter
	void Date::status(int newStatus) {
		status_ = newStatus;
	}

	//check if the year, month and day are valid
	void Date::status(int y_date, int m_date, int d_date) { 

		if (y_date < min_year || y_date > max_year || y_date == 0) {
			*this = Date();
			status(error_year);			
		}

		else if (m_date < 1 || m_date > 12 || m_date == 0) {
			*this = Date();
			status(error_mon);			
		}

		else if (d_date > mdays(y_date, m_date) || d_date == 0) {  //m_date should be valid
			*this = Date();
			status(error_day);			
		}

		else {
			status(no_error); 
		}
	}

	// find the number od days in a given month for a given year
	int Date::mdays(int year, int mon) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;

		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

			
	// constructors

	//defualt constructor
	Date::Date() {  
		year_ = 0;
		month_ = 0;
		day_ = 0;
		status_ = no_error;
	}

	//constructor with 3 parameters
	Date::Date(int year, int month, int day) {

		status(year, month, day); //check if the year, month and day are valid

		if (status() == no_error) {
			year_ = year;
			month_ = month;
			day_ = day;
			status_ = no_error;
		}
		
	}
	
	// public members	
	
	int Date::status() const {		
		return status_; //returns an integer representing the status of the current object.
	}

	void Date::clearError() {
		status_ = no_error; //resets the status of an object to no_error
	}

	bool Date::isGood() {	//return true if status_ == no_error and if the date is not in the safe empty state			
		return year_ != 0 && month_ != 0 && day_ != 0 && status_ == no_error ? true : false;
	}

	//adds to the date stored by the object the number of days specified in the parameter
	Date& Date::operator+=(int days) {
		if (!isGood()) // true if in error mode or in safe empty state
		{
			status(error_invalid_operation);
		}
		else if (day_ + days > mdays(year_, month_) || day_ + days < 1) // check the date valid or not
		{
			status(error_invalid_operation);
		}
		else
		{
			day_ += days;
		}
		return *this;
	}

	//adds one day to the date stored by the object (prefix)
	Date& Date::operator++() {
		if (!isGood() || day_ + 1 > mdays(year_, month_)) {
			status(error_invalid_operation);
		}
		else {
			day_ = day_ + 1;
		}
		return *this;
	}
	
	//that adds one day to the date stored by the object (postfix)
	Date Date::operator++(int) {
		Date d = *this;

		if (!isGood() || day_ + 1 > mdays(year_, month_)) {
			status(error_invalid_operation);
		}
		else {
			++(*this);
		}
		return d;
	}

	//adds to the date stored by the object the number of days specified in the parameter
	Date Date::operator+(int days) {
		Date res;
		
		//If the current object is in error mode or in a safe empty state
		if (!isGood() || day_ + days > mdays(year_, month_)) {
			
			res.status(error_invalid_operation); // returns the status set to error_invalid_operation
			
			//returns a copy of the current object
			res.year_ = year_;
			res.month_ = month_;
			res.day_ = day_;
		}
		else {
			res.year_ = year_;
			res.month_ = month_;
			res.day_ = day_ + days;
		}
		return res;
	}

	//true if two date objects store the same date
	bool Date::operator==(const Date& rhs) const {	
	
		return(year_ == rhs.year_ && month_ == rhs.month_ && day_ == rhs.day_);
	}

	//true if two date objects store different dates
	bool Date::operator!=(const Date& rhs) const {
	
		return(year_ != rhs.year_ || month_ != rhs.month_ || day_ != rhs.day_);
	}
		
	//true if the current object stores a date that is before the date stored in rhs 
	bool Date::operator<(const Date& rhs) const {
		bool ls = false;

		if (year_ == rhs.year_) {

			if (month_ == rhs.month_) {

				if (day_ < rhs.day_) {
					ls = true; 
				}				
			}
			else if (month_ < rhs.month_){
				ls = true; 
			}

		}
		else if (year_ < rhs.year_) {
			ls = true;
		}		

		return ls; 
	}

	//true if the current object stores a date that is after the date stored in rhs 
	bool Date::operator>(const Date& rhs) const {
		bool gt = false;

		if (year_ == rhs.year_) {

			if (month_ == rhs.month_) {

				if (day_ > rhs.day_) {
					gt = true;
				}
			}
			else if (month_ > rhs.month_) {
				gt = true;
			}

		}
		else if (year_ > rhs.year_) {
			gt = true;
		}

		return gt;
	}

	//true if the current object stores a date that is before or equal to the date stored in rhs 
	bool Date::operator<=(const Date& rhs) const {
		bool lseq = false;

		if (year_ == rhs.year_) {

			if (month_ == rhs.month_) {

				if (day_ <= rhs.day_) {
					lseq = true;
				}
			}
			else if (month_ < rhs.month_) {
				lseq = true;
			}

		}
		else if (year_ < rhs.year_) {
			lseq = true;
		}

		return lseq;  
	}

	//true if the current object stores a date that is after or equal to the date stored in rhs
	bool Date::operator>=(const Date& rhs) const {
		bool gteq = false;

		if (year_ == rhs.year_) {

			if (month_ == rhs.month_) {

				if (day_ >= rhs.day_) {
					gteq = true;
				}
			}
			else if (month_ > rhs.month_) {
				gteq = true;
			}

		}
		else if (year_ > rhs.year_) {
			gteq = true;
		}

		return gteq;  
	}

	//reads from an input stream a date in the following format: YYYY?MM?DD 
	 Date Date::read(std::istream& is) { 
		char ch1, ch2;
		int y, m, d;		
		Date res;

		is >> y >> ch1 >> m >> ch2 >> d;

		if (is.fail() || (ch1 != '/' && ch1 != '.' && ch1 != '-') || (ch2 != '/' && ch2 != '.' && ch2 != '-')) {
			res = Date();
			res.status(error_input);
		}
		
		else {
			res = Date(y, m, d);
		}

		return res;
	}

	//writes the date to an std::ostream object in the following format: YYYY/MM/DD
	std::ostream& Date::write(std::ostream& os) const {		

		os << setw(4) << setfill('0') << year_ << "/" << setw(2) << month_ << "/"
			<< setw(2) << right << day_ << setfill(' ');		
		return os;
	}

	//Prints the date to the first parameter
	std::ostream& operator<<(std::ostream& os, const Date& d) {
		d.write(os);
		return os;
	}

	//Reads the date from the first parameter 
	std::istream& operator>>(std::istream& is, Date& d) {
		d = d.read(is);
		return is;
	}


}
