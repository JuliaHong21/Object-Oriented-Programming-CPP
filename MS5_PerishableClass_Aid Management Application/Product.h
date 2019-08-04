/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/


#ifndef ama_PRODUCT_H_
#define ama_PRODUCT_H_

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"

namespace ama {	

	class Product : public iProduct {

		const char pType;
		char SKU[max_length_sku + 1];
		char unit[max_length_unit + 1];
		char * nameOfPro;
		int quan_OnHand;
		int quan_needed;
		double price_btax; //price before tax
		bool taxable;
		ErrorState errState;
		double cost() const;  //price after tax	
		void set(const char[], const char*, const char[], double, bool, int, int);  //set the valuse

	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		Product(char pType_ = 'N');
		Product(const char[], const char *, const char[], double = 0.0, int = 0, int = 0, bool = true);
		Product(const Product&);  //The Copy Constructor
		~Product();  //The Destructor
		Product& operator=(const Product&);  //The Copy Assignment Operator

		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const iProduct&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		const char* name() const;
		double total_cost() const;
		bool isEmpty() const;

		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};
}
	

#endif
