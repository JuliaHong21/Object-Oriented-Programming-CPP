/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-03-27
*/


#ifndef ama_IPRODUCT_H_
#define ama_IPRODUCT_H_

#include <iostream>

namespace ama {

    const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const double tax_rate = 0.13;

	class iProduct {

	public:

		//writes the content of the current instance in the stream received as the first parameter
        virtual std::ostream& write(std::ostream& os, int writeMode) const = 0;

		//reads data from the stream, and stores it in the attributes
        virtual std::istream& read(std::istream& is, bool interractive) = 0;
				
        virtual bool operator==(const char* sku) const = 0; //returns true if the string specified in the parameter is the same as the SKU of the current instance		
        virtual double total_cost() const = 0; //returns the total cost of all available units of product, including tax.
        virtual int qtyNeeded() const = 0;  //returns the how many units of product are needed
        virtual int qtyAvailable() const = 0; //returns the how many units of product are available
        virtual const char* name() const = 0;  //eturns the address of the string storing the name of the product
        virtual int operator+=(int qty) = 0;
        virtual bool operator>(const iProduct& other) const = 0;

        inline virtual ~iProduct() {}  //a virtual empty-body destructor

	};
}
	

#endif