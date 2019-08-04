/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-03-24
*/


#ifndef ama_UTILITIES_H_
#define ama_UTILITIES_H_

#include "Product.h"
#include <iostream>

namespace ama {

	double& operator+=(double& total, const Product& prod);
	std::ostream& operator<<(std::ostream& out, const Product& prod);
	std::istream& operator>>(std::istream& in, Product& prod);

}

#endif