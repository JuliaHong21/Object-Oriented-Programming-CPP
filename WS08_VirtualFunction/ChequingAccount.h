// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account { //derives from the Account class
		
		double transFee_;
		double monthEndFee_;

	public:
		ChequingAccount(double balance, double transFee, double monthlyFee); //constructor
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd(); // debits the monthly fee from the balance
		void display(std::ostream& out) const;
	};

}

#endif


