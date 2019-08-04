/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-03-24
*/

#include "Utilities.h"

namespace ama{

	//Adds the total cost of the product into the first parameter
	double& operator+=(double& total, const Product& prod) {		
		return total += prod.total_cost();
	}

	//Writes into the first parameter, in a human readable format
	std::ostream& operator<<(std::ostream& out, const Product& prod) {		
		prod.write(out, 2);
		return out;
	}

	//Reads from the first parameter a product in interactive mode
	std::istream& operator>>(std::istream& in, Product& prod) {
		prod.read(in, true);
		return in;
	}

}
