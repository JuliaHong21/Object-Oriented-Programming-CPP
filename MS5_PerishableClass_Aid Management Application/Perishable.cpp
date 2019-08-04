/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Perishable.h"
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

namespace ama {

	Perishable::Perishable() : Product('p') {  //
		//should call the one-parameter constructor from the base, 
		//and pass 'P' for the record tag
	}

	ostream& Perishable::write(ostream& out, int writeMode) const {
		Product::write(out, writeMode);

		if (isEmpty() || !isClear()) {  //error and not in safe empty state
			// do nothing
		}
		else {
			if (writeMode == write_human) {
				out << setw(max_length_label) << right << "Expiry Date: " << perishableDate << endl;
			}
			else if (writeMode == write_table) {
				out << " " << perishableDate << " |";
			}
			else if (writeMode == write_condensed) {
				out << "," << perishableDate;
			}			
		}
		return out;
	}

	istream& Perishable::read(istream& in, bool interractive) {
		Product::read(in, interractive);		
		Date tmpDate;

		if (interractive) {  //interactive mode 
			cout << right << setw(max_length_label) << "Expiry date (YYYY/MM/DD): ";
			in >> tmpDate;

			if (tmpDate.isGood()) {  //no error
				perishableDate = tmpDate;  // store the date
			}
			else {  //error
				in.setstate(ios::failbit);  //
				switch (tmpDate.status()) {
				case 1:
					message("Invalid Year in Date Entry"); // error message for the year
					break;
				case 2:
					message("Invalid Month in Date Entry");  //error message for the month
					break;
				case 3:
					message("Invalid Day in Date Entry");  //error message for the day
					break;
				case 5:
					message("Invalid Date Entry");  //error message for the input
					break;
				}			
						
			}
		}
		
		else { //non-interactive mode
			if (in.get() == ',') {
				in >> perishableDate;
			}
			else {
				in.ignore(1, '\n'); 
			}
		}
		return in;	
	}	
}