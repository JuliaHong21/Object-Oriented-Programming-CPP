// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {   //derives from the Account class 

		double intstRate_;

	public:
		SavingsAccount(double balance, double interestRate); //constructor
		void monthEnd(); //– debits any applicable monthly fees for the account
		void display(std::ostream& out) const;
	};

}

#endif

