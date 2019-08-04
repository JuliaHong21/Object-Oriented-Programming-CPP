/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-03-24
*/

#ifndef ama_PRODUCT_H_
#define ama_PRODUCT_H_

#include <iostream>
#include "ErrorState.h"

namespace ama {

	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const double tax_rate = 0.13;

	class Product {

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

	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		Product(char pType_ = 'N');
		Product(const char SKU_[], const char *nameOfPro_, const char unit_[], double price_btax_ = 0,
			int quan_needed_ = 0, int quan_OnHand_ = 0, bool taxable_ = true) ;
		Product(const Product&);  //The Copy Constructor
		~Product();  //The Destructor
		Product& operator=(const Product&);  //The Copy Assignment Operator

		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const Product&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;

		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};
}
	

#endif
