// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB


#include <iostream>
#include "Account.h"

namespace sict {

	//constructor
	Account::Account(double balance_){
		if (balance_ > 0) {
			m_balance = balance_;
		}
		else {
			m_balance = 0;
		}
	}

	//overrides the function from the interface
	bool Account::credit(double amount) {
		bool tmp = false;

		if (amount > 0) {
			m_balance += amount;
			tmp =  true;
		}
		return tmp;
	}

	//overrides the function from the interface
	bool Account::debit(double amount) {
		bool tmp = false;

		if (amount > 0 && amount < m_balance) {
			m_balance -= amount;
			tmp = true;
		}
		return tmp;
	}

	// returns the current balance of the account
	double Account::balance() const {
		return m_balance;
	}
}