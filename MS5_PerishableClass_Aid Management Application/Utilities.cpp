/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#include "Utilities.h"

namespace ama {

	//Adds the total cost of the product into the first parameter
	double& operator+=(double& total, const iProduct& prod) {
		return total += prod.total_cost();
	}

	//Writes into the first parameter, in a human readable format
	std::ostream& operator<<(std::ostream& out, const iProduct& prod) {
		prod.write(out, 2);
		return out;
	}

	//Reads from the first parameter a product in interactive mode
	std::istream& operator>>(std::istream& in, iProduct& prod) {
		prod.read(in, true);
		return in;
	}

	iProduct* createInstance(char tag) {
		Product* temp = nullptr;

		if (tag == 'N' || tag == 'n') {
			temp = new Product();  //dynamically create an object of type Product
		}
		else if (tag == 'P' || tag == 'p') {
			temp = new Perishable();  //dynamically create an object of type Perishable 
		}
		return temp;
	}

}

