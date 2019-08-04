/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date	2019-03-16
*/

#include <iostream>
#include "ErrorState.h"
#include <cstring>

using namespace std;

namespace ama {

	//constructor
	ErrorState::ErrorState(const char* errorMessage) {
		
		if (errorMessage != nullptr && errorMessage[0] != '\0') {
			size_t len = std::strlen(errorMessage) + 1;
			msg = new char[len];
			std::strncpy(msg, errorMessage, len);
			msg[len] = '\0';
		}

		else {
			msg = nullptr;
		}
	
	}

	//destructor
	ErrorState:: ~ErrorState() {

	}


	ErrorState:: operator bool() const {
		bool tmp;

		if (msg == nullptr || msg[0] == '\0')
			tmp = false;
		else
			tmp = true;

		return tmp; //true if the current instance is storing a valid message
	}

	ErrorState& ErrorState::operator=(const char* pText) { //stores a copy the text received in the parameter
		if (pText == nullptr || pText[0] == '\0')
			msg = nullptr;
		else {
			size_t len = std::strlen(pText) + 1;
			msg = new char[len];
			std::strncpy(msg, pText, len);
			msg[len] = '\0';
		}

		return *this;
	}

	void ErrorState::message(const char* pText) { //stores a copy the text received in the parameter
		if (pText == nullptr || pText[0] == '\0')
			msg = nullptr;
		else {
			size_t len = std::strlen(pText) + 1;
			msg = new char[len];
			std::strncpy(msg, pText, len);
			msg[len] = '\0';
		}
	}

	const char* ErrorState::message() const {
		return msg; //returns the address of the message stored in the current object.
	}

	// helper function
	//Prints the text stored in an ErrorState object to a stream
	std::ostream& operator<<(std::ostream& os, const ErrorState& err) {
		if (err.message() != nullptr && err.message()[0] != '\0') {
			os << err.message();
		}

		return os;
	}
}
