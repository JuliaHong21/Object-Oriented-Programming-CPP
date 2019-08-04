// Date: 2019/Mar/11
// Author: Youngeun Hong(ID: 159100171)
//section: SBB

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict { 
	
	//defalt constructor
	Contact::Contact() {
		name[0] = '\0';
		phoneNumber = nullptr;
		numOfPhone = 0;
	}

	//constructor with three arguments
	Contact::Contact(const char* name_, const long long* phoneNumber_, int numOfPhone_) {		

		//if (name_ != nullptr && name_[0] != '\0') {
			
			long long * validNum = new long long[numOfPhone_];
			int numOf_validNum = 0;
			int ctrCode = 0;
			int areaCode = 0;
			int Numbers = 0;
		
			strncpy(name, name_, max_name_size);
			name[max_name_size - 1] = '\0'; //add null character
			
			for (int i = 0; i < numOfPhone_; i++) {	
				ctrCode = phoneNumber_[i] / 10000000000;  //country code of a n_phoneNum (1 or 2 digits)
				areaCode = (phoneNumber_[i] / 10000000) % 1000; // area code of a n_phoneNum (3 digits)
				Numbers = phoneNumber_[i] % 10000000;	// numbers of a n_phoneNum (7 digits)			
								
				if (ctrCode > 0 && ctrCode < 100 && areaCode > 100 && areaCode < 1000 && Numbers > 1000000 && Numbers < 10000000){
				
					validNum[numOf_validNum] = phoneNumber_[i];					
					numOf_validNum++;
				}				
			}			
			
			numOfPhone = numOf_validNum;
			phoneNumber = new long long[numOf_validNum];
			for (int i = 0; i < numOf_validNum; i++) {
				phoneNumber[i] = validNum[i];
			}
			delete[] validNum;

		//}
		/*else {			
			*this = Contact();
		}*/
	}
	
	//copy constructor
	Contact::Contact(const Contact &src) {

		// shallow copies
		strcpy(name, src.name);
		numOfPhone = src.numOfPhone;

		// allocate dynamic memory for phoneNumber
		if (src.phoneNumber != nullptr) {
			phoneNumber = new long long[numOfPhone];

			for (int i = 0; i < numOfPhone; i++) {
				phoneNumber[i] = src.phoneNumber[i];
			}
		}
		else {
			phoneNumber = nullptr;
		}	
		
	}
	
	//copy assignment operator
	Contact& Contact::operator=(const Contact& rhs) { 
		
		if (this != &rhs) {
			
			strcpy(name, rhs.name);
			numOfPhone = rhs.numOfPhone;

			//deallocate previously allocated dynamic memory
			delete[] phoneNumber;

			// allocate new dynamic memory
			if (rhs.phoneNumber != nullptr) {
				phoneNumber = new long long[numOfPhone];

				for (int i = 0; i < numOfPhone; i++) {
					phoneNumber[i] = rhs.phoneNumber[i];
				}
			}
			else {
				phoneNumber = nullptr;
			}
		}
		
		return *this;
	}

	// an overloaded += operator
	Contact& Contact::operator+=(long long n_phoneNum) {
	
		int ctrCode = n_phoneNum / 10000000000;  //country code of a n_phoneNum (1 or 2 digits)
		int areaCode = (n_phoneNum / 10000000) % 1000; // area code of a n_phoneNum (3 digits)
		int Numbers = n_phoneNum % 10000000; // numbers of a n_phoneNum (7 digits)

		if (ctrCode > 0 && ctrCode < 100 && areaCode > 100 && areaCode < 1000 && Numbers > 1000000 && Numbers < 10000000) {
			++numOfPhone;
			/*phoneNumber = new long long[numOfPhone];
			phoneNumber[numOfPhone] = n_phoneNum;
			delete[] phoneNumber;*/

			long long* temp = new long long[numOfPhone];

			for (int i = 0; i < numOfPhone - 1; i++) {
				temp[i] = phoneNumber[i];
			}
			temp[numOfPhone - 1] = n_phoneNum;

			delete [] phoneNumber;

			phoneNumber = temp;

		}
		
		return *this;
	}

	//destructor
	Contact::~Contact() {
		delete[] phoneNumber;
		phoneNumber = nullptr;
	}

	bool Contact::isEmpty() const {
		return(name[0] == '\0') ? true : false;
	}

	void Contact::display() const {
		if (!isEmpty()) {
			int country;
			int area;
			int num1;
			int num2;
			
			cout << name << endl;

			for (int i = 0; i < numOfPhone; i++) {
				country = phoneNumber[i] / 10000000000;
				area = (phoneNumber[i] / 10000000) % 1000;
				num1 = (phoneNumber[i] / 10000) % 1000;
				num2 = phoneNumber[i] % 10000;
				cout << "(+" << country << ") " << area << " " << num1 << "-" << setfill('0') << setw(4) << num2 << endl;
			}
		}
	
		else {
			cout << "Empty contact!" << endl;
		}
	}
}
