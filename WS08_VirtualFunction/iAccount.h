// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

namespace sict {

	class iAccount{  

	public:
		virtual ~iAccount() {}  //destructor

		virtual bool credit(double amount) = 0; //adds a positive amount to the account balance
		virtual bool debit(double amount) = 0; //subtracts a positive amount from the account balance
		virtual void monthEnd() = 0; //debits any applicable monthly fees for the account
		virtual void display(std::ostream& out) const = 0; //inserts account information into the parameter						
	};

	iAccount* CreateAccount(const char* type, double balance);

}

#endif
