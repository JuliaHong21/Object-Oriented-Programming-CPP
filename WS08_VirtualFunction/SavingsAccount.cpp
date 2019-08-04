// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB


#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"


namespace sict {

	// constructor
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		if (interestRate > 0)
			intstRate_ = interestRate;
		else
			intstRate_ = 0;
	}

	// debits any applicable monthly fees for the account
	void SavingsAccount::monthEnd() { 
		m_balance += m_balance * (intstRate_ / 100);
	}

	// display
	void SavingsAccount::display(std::ostream& out) const {
		out << "Account type: Savings" << std::endl;
		out.setf(out.fixed, out.floatfield);
		out.precision(2);
		out << "Balance: $" << m_balance << std::endl;
		out << "Interest Rate (%): " << intstRate_ << std::endl;
	}
}