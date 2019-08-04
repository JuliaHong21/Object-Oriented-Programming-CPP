// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

namespace sict {

	// constructor
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance) {
		
		//stores the fee if the transaction fee received is positive
		if (transFee > 0) {  
			transFee_ = transFee; 
		}
		else transFee_ = 0.0;

		// stores the fee if the monthly fee received is positive 
		if (monthlyFee > 0) {
			monthEndFee_ = monthlyFee;
		}
		else monthEndFee_ = 0.0;
	}

	// modifier credits the balance by the amount received 
	// and if successful debits the transaction fee from the balance
	bool ChequingAccount::credit(double amount) {
		bool tmp = false;
		if (m_balance += amount) {
			m_balance -= transFee_;
			tmp = true;
		}
		return tmp;
	}

	// debits the balance by the amount received 
	// and if successful debits the transaction fee from the balance
	bool ChequingAccount::debit(double amount) {
		bool tmp = false;
		if (m_balance -= amount) {
			m_balance -= transFee_;
			tmp = true;
		}
		return tmp;
	}

	// debits the monthly fee from the balance
	void ChequingAccount::monthEnd() {
		m_balance -= monthEndFee_;
	}

	// display
	void ChequingAccount::display(std::ostream& out) const {
		out << "Account type: Chequing" << std::endl;
		out.setf(out.fixed, out.floatfield);
		out.precision(2);
		out << "Balance: $" << m_balance << std::endl;
		out << "Per Transaction Fee: " << transFee_ << std::endl;
		out << "Monthly Fee: " << monthEndFee_ << std::endl;
	}
	
}