/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ErrorState.h"
#include <cstring>

using namespace std;

namespace ama {

	//constructor
	ErrorState::ErrorState(const char* errorMessage) {
		
		if (errorMessage != nullptr && errorMessage[0] != '\0') {
			size_t len = strlen(errorMessage) + 1;
			msg = new char[len];
			strncpy(msg, errorMessage, len);
			msg[len] = '\0';
		}

		else {
			msg = nullptr;
		}
	
	}

	//destructor
	ErrorState:: ~ErrorState() {
		delete[] msg;
		msg = nullptr;
	}


	ErrorState:: operator bool() const {
		bool tmp = true;

		if (msg == nullptr || msg[0] == '\0')
			tmp = false;		

		return tmp; //true if the current instance is storing a valid message
	}

	ErrorState& ErrorState::operator=(const char* pText) { //stores a copy the text received in the parameter
		delete[]msg;

		if (pText == nullptr || pText[0] == '\0')
			msg = nullptr;
		else {
			string str = pText;
			msg = new char[str.length() + 1];
			strcpy(msg, pText);			
		}

		return *this;
	}

	void ErrorState::message(const char* pText) { //stores a copy the text received in the parameter
		*this = pText; //copy the string to *this
		
		/*if (pText == nullptr || pText[0] == '\0')
			msg = nullptr;
		else {
			string str = pText;
			msg = new char[str.length + 1];
			strcpy(msg, pText);
		}*/
	}

	const char* ErrorState::message() const {
		return *this ? msg : nullptr; //returns the address of the message stored in the current object.
	}

	// helper function
	//Prints the text stored in an ErrorState object to a stream
	ostream& operator<<(ostream& os, const ErrorState& err) {
		if (err.message() != nullptr && err.message()[0] != '\0') {
			os << err.message();
		}

		return os;
	}
}
