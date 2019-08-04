// Workshop 4 - Constructors - Test Main
// w4_in_home.cpp
// SBB
// 08/Feb/2019
// name: Youngeun Hong
// ID: 159100171

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
#include "Traveler.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// TODO: continue your namespace here
namespace sict {	

	// TODO: implement the default constructor here
	Traveler::Traveler() {
		firstName[0] = '\0'; //a safe empty state
		lastName[0] = '\0';
		destination[0] = '\0';
		yearDpt = '\0';
		monthDpt = '\0';
		dayDpt = '\0';
	}

	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* F_Name, const char* L_Name, const char* Destination) {

		if (F_Name == nullptr || F_Name[0] == '\0' || L_Name == nullptr 
			|| L_Name[0] == '\0' || Destination == nullptr || Destination[0] == '\0' ) {

		firstName[0] = '\0';
		lastName[0] = '\0';
		destination[0] = '\0';
		}

		else {
			strcpy(firstName, F_Name);
			strcpy(lastName, L_Name);
			strcpy(destination, Destination);

			yearDpt = 2019;
			monthDpt = 7;
			dayDpt = 1;
		}
	}
	// the constructor with 6 parameters
	Traveler::Traveler(const char* F_Name, const char* L_Name, const char* Destination, 
		const int y_dpt, const int m_dpt, const int d_dpt) {

		//To check if all of the data received is valid
		if (F_Name != nullptr && F_Name[0] != '\0' && L_Name != nullptr && L_Name[0] != '\0'
			&& Destination != nullptr && Destination[0] != '\0' &&
			y_dpt >= 2019 && y_dpt <= 2022 && m_dpt >= 1 && m_dpt <= 12 && d_dpt >= 1 && d_dpt <=31){

			strcpy(firstName, F_Name); // stores the data in the object's instance variables
			strcpy(lastName, L_Name);
			strcpy(destination, Destination);
			yearDpt = y_dpt;
			monthDpt = m_dpt;
			dayDpt = d_dpt;			
			
		}		

		else { 

			firstName[0] = '\0';  //a safe empty state
			lastName[0] = '\0';
			destination[0] = '\0';
			yearDpt = '\0';
			monthDpt = '\0';
			dayDpt = '\0';
		}

	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {

		bool safeEmpty = false;	
		if (firstName[0] == '\0'){  //It is true if the Traveler object is in a safe empty state.
			safeEmpty = true;
		}

		else {
			safeEmpty = false;  //It is false if the Traveler object is not in a safe empty state.
		}

		return safeEmpty;
	}

	
	const char* Traveler::name() const {		
		
		if (isEmpty()) { 			
			return nullptr; 			
		}

		else{
			return firstName;
		}
	}

	// add the TravelWtih(...) function
	bool Traveler::canTravelWith(const Traveler& t) const {		

		bool y = this->yearDpt == t.yearDpt;
		bool m = this->monthDpt == t.monthDpt;
		bool d = this->dayDpt == t.dayDpt;
		bool where = false; //to check both strings of destination are equal
			if (strcmp(this->destination, t.destination) == 0) {
				where = true;
			}
			
		bool check = y && m && d && where;

		return check;
	}


	// TODO: implement display query here
	void Traveler::display() const {

		if (isEmpty()) { //If the object is in a safe empty state, print error message.
			cout << "--> Not a valid traveler! <--" << endl;
		}

		else { //If the object is not in a safe empty state, print the following message.
			cout << lastName << ", " << firstName << " goes to " << destination <<
				" on " << yearDpt << "/" << setfill('0') << setw(2) << monthDpt
				<<"/" << setfill('0') << setw(2) << dayDpt <<endl;
		}

	}
}

