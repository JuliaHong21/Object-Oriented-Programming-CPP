// Date: 2018/03/22
// Author: Youngeun Hong(ID: 159100171)
// SBB


#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	const double interest_rate = 5;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* tmp = nullptr;

		if (type[0] == 'S') {

			// Create a SavingAccount instance
			tmp = new SavingsAccount(balance, interest_rate);
		}

		else if (type[0] == 'C') {

			// Create a ChequingAccount instance
			tmp = new ChequingAccount(balance, transaction_fee, monthly_fee);
		}

		return tmp;
	}
}