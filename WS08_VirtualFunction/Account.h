// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include <iostream>
#include "iAccount.h"

namespace sict {

	class Account : public iAccount {  //derives from the iAccount interface
	public:
		Account(double balance_);  //constructor
		bool credit(double amount); //overrides the function from the interface
		bool debit(double amount); //overrides the function from the interface

	protected:
		double m_balance;
		double balance() const; // returns the current balance of the account		

	};
}

#endif

