/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#ifndef ama_PERISHABLE_H_
#define ama_PERISHABLE_H_

#include <iostream>
#include "Product.h"
#include "Date.h"

namespace ama {

	class Perishable : public Product {	 //derived from the Product class 
		Date perishableDate;  //to store the expiry date for a perishable produc

	public:
		Perishable();  // A default constructor

		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};
}

#endif
