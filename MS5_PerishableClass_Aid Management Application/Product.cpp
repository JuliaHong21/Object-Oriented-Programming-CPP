/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"
#include <cstring>
#include <string>
#include <iomanip>

namespace ama {

	//constructor with zero/one parameter
	Product::Product(char pType_) : pType(pType_) {

		// make it as the empty state		
		SKU[0] = '\0';
		unit[0] = '\0';
		nameOfPro = nullptr;
		quan_needed = 0;
		quan_OnHand = 0;
		price_btax = 0;
		taxable = true;
	}

	//constructor with 7 parameters
	Product::Product(const char SKU_[], const char *nameOfPro_, const char unit_[], double price_btax_,
		int quan_needed_, int quan_OnHand_, bool taxable_) : pType('N') {
		
		if (SKU_ == nullptr || nameOfPro_ == nullptr || unit_ == nullptr) {
			nameOfPro = nullptr;
			*this = Product();
		}
		else {
			set(SKU_, nameOfPro_, unit_, price_btax_, taxable_, quan_OnHand_, quan_needed_);
		}		
	}

	//The Copy Constructor
	Product::Product(const Product& other) : pType(other.pType) {

		if (!other.isEmpty()) {
			nameOfPro = nullptr;
			*this = other;
		}
	}

	void Product::set(const char SKU_[], const char *nameOfPro_, const char unit_[],
				double price_btax_, bool taxable_, int quan_OnHand_, int quan_needed_) {
		
		nameOfPro = new char[max_length_name + 1];  //the name of the product
		strncpy(nameOfPro, nameOfPro_, max_length_name);
		nameOfPro[max_length_name] = '\0';

		strncpy(SKU, SKU_, max_length_sku); //the SKU of the product
		SKU[max_length_sku] = '\0';
		strncpy(unit, unit_, max_length_unit); //unit
		unit[max_length_unit] = '\0';
		price_btax = price_btax_; //the product’s price before taxes 		
		taxable = taxable_;	//the product’s taxable status
		quan_OnHand = quan_OnHand_;  //the quantity of the product on hand
		quan_needed = quan_needed_;  //the quantity needed of the product
	}

	//The Copy Assignment Operator
	Product& Product::operator=(const Product& p) {

		if (this != &p) {  //if it is not the self-copy
			delete[] nameOfPro;
			set(p.SKU, p.nameOfPro, p.unit, p.price_btax, p.taxable, p.quan_OnHand, p.quan_needed);
		}
		return *this;
	}		

	//The Destructor
	Product::~Product() {
		delete[] nameOfPro;
		nameOfPro = nullptr;
	}

	int Product::operator+=(int cnt) {
		if (cnt > 0) {
			quan_OnHand += cnt;
		}
		return quan_OnHand;
	}

	bool Product::operator==(const char* sku) const {
		bool tmp = false;

		if (strcmp(SKU, sku) == 0) {
			tmp = true;
		}
		return tmp;
	}

	bool Product::operator> (const char* sku) const {
		bool tmp = false;

		if (strcmp(SKU, sku) > 0) {
			tmp = true;
		}
		return tmp;
	}

	bool Product::operator> (const iProduct& other) const {
		bool tmp = false;

		if (strcmp(nameOfPro, other.name()) > 0) {
			tmp = true;
		}
		return tmp;
	}

	//available quantity
	int Product::qtyAvailable() const {
		return quan_OnHand;
	}

	//needed quantity
	int Product::qtyNeeded() const {
		return quan_needed;
	}

	//totla cost after tax
	double Product::total_cost() const {
		return cost() * quan_OnHand;
	}

	//true if the object is in the empty state
	bool Product::isEmpty() const {
		return nameOfPro == nullptr;
	}

	//(private) price after tax per unit
	double Product::cost() const {
		double tmp;
		if (taxable) {
			tmp = price_btax + (price_btax * tax_rate);
		}
		else {
			tmp = price_btax;
		}
		return tmp;
	}

	const char* Product::name() const {
		return nameOfPro;
	}

	//(protected) receives and stores the error message 
	void Product::message(const char* pText) {
		errState.message(pText);
	}

	//(protected) true if the ErrorState attribute contains no error message
	bool Product::isClear() const {
		return errState.message() == nullptr;
	}

	std::istream& Product::read(std::istream& in, bool interractive) {

		char i_sku[max_length_sku + 1];
		char i_name[max_length_name + 1];
		char i_unit[max_length_unit + 1];
		double i_price;
		int i_tax;
		bool i_taxable;
		char interact_tax;
		int i_qty_available, i_qty_needed;
		char c;
		int str_length;
		Product read;

		if (interractive == false) {  //non-interractive mode

			in.getline(i_sku, max_length_sku + 1, ',');
			in.getline(i_name, max_length_name, ',');

			delete[] nameOfPro;
			std::string str_name = i_name;
			str_length = str_name.length() + 1;
			nameOfPro = new char[str_length];
			strcpy(nameOfPro, i_name);

			in.getline(i_unit, max_length_unit + 1, ',');
			in >> i_price >> c >> i_tax >> c >> i_qty_available >> c >> i_qty_needed;

			if (i_tax == 0)
				i_taxable = false;
			else
				i_taxable = true;

			set(i_sku, i_name, i_unit, i_price, i_taxable, i_qty_available, i_qty_needed);	 //set the valuse		

		}

		else {   //interractive mode
			std::cout << std::right << std::setw(max_length_label) << "Sku: ";
			in >> i_sku;

			std::cout << std::right << std::setw(max_length_label) << "Name (no spaces): ";
			in >> i_name;

			std::cout << std::right << std::setw(max_length_label) << "Unit: ";
			in >> i_unit;	

			//taxable
			std::cout << std::right << std::setw(max_length_label) << "Taxed? (y/n): ";
			in >> interact_tax;

			if (interact_tax == 'y' || interact_tax == 'Y') {
				i_taxable = true;
			}
			else if (interact_tax == 'n' || interact_tax == 'N') {
				i_taxable = false;
			}
			else {
				message("Only (Y)es or (N)o are acceptable!"); 
				in.setstate(std::ios::failbit);	// sets the failure bit of the first parameter 	
			}

			//price
			if (isClear()) {
				std::cout << std::right << std::setw(max_length_label) << "Price: ";
				in >> i_price;

				if (in.fail()) {
					message("Invalid Price Entry!");
				}
			}

			//quantity on hand
			if (isClear()) {
				std::cout << std::right << std::setw(max_length_label) << "Quantity on hand: ";
				in >> i_qty_available;

				if (in.fail()) {
					message("Invalid Quantity Available Entry!");
				}
			}

			//quantity needed
			if (isClear()) {
				std::cout << std::right << std::setw(max_length_label) << "Quantity needed: ";
				in >> i_qty_needed;

				if (in.fail()) {
					message("Invalid Quantity Needed Entry!");
				}
			}			

			if (isClear()) {  //if there are no errorr, set the values
				delete[] nameOfPro;
				set(i_sku, i_name, i_unit, i_price, i_taxable, i_qty_available, i_qty_needed);	//set the valuse			
			}
		}

		return in;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const {

		if (!isClear()) {  //If the object contains an error message
			out << errState;  //prints the error message 
		}
		else if (isEmpty()) { //safe empty state
			//do nothing
		}
		else if (!isEmpty() && writeMode == write_condensed) {
			out << pType << ',' << SKU << ',' << nameOfPro << ',' << unit << ','
				<< price_btax << ',' << taxable << ',' << quan_OnHand << ',' << quan_needed;
		}

		else if (!isEmpty() && writeMode == write_table) {
			out << " " << std::right << std::setw(max_length_sku) << SKU << " | "; //SKU	

			if (strlen(nameOfPro) > 16) { //the name of the product

				for (int i = 0; i < 13; i++) {
					out << nameOfPro[i];
				}
				out << std::left << std::setw(3) << "..." << " | ";
			}
			else {
				out << std::left << std::setw(16) << nameOfPro << " | ";
			}
			out << std::left << std::setw(10) << unit << " | "; //unit					
			out << std::right << std::setw(7) << std::setprecision(2) << std::fixed << price_btax << " | ";  //price before tax					
			if (taxable == true) {  //taxable
				out << std::right << std::setw(3) << "yes" << " | ";
			}
			else {
				out << std::right << std::setw(3) << "no" << " | ";
			}
			out << std::right << std::setw(6) << quan_OnHand << " | "; //quantity available					 
			out << std::right << std::setw(6) << quan_needed << " |"; //quatity needed
		}

		else if (!isEmpty() && writeMode == write_human) {
			out << std::setw(max_length_label) << std::right << "Sku: " << SKU << std::endl;
			out << std::setw(max_length_label) << std::right << "Name: " << nameOfPro << std::endl;
			out << std::setw(max_length_label) << std::right << "Price: " << std::setprecision(2) << std::fixed << price_btax << std::endl;
			out << std::setw(max_length_label) << std::right << "Price after Tax: " << (taxable == true ? cost() : price_btax) << std::endl;
			out << std::setw(max_length_label) << std::right << "Quantity Available: " << quan_OnHand << " " << unit << std::endl;
			out << std::setw(max_length_label) << std::right << "Quantity Needed: " << quan_needed << " " << unit << std::endl;

		}
		return out;
	}
}