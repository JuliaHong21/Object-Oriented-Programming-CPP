/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#ifndef ama_UTILITIES_H_
#define ama_UTILITIES_H_

#include "Product.h"
#include "Perishable.h"
#include <iostream>

namespace ama {

	double& operator+=(double& total, const iProduct& prod);
	std::ostream& operator<<(std::ostream& out, const iProduct& prod);
	std::istream& operator>>(std::istream& in, iProduct& prod);

	iProduct* createInstance(char tag);
}

#endif