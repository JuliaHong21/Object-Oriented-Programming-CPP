/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-03-27
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

		nameOfPro = new char[max_length_name + 1];  //the name of the product
		strncpy(nameOfPro, nameOfPro_, max_length_name + 1);
		nameOfPro[max_length_name] = '\0';

		strncpy(SKU, SKU_, max_length_sku + 1); //the SKU of the product
		strncpy(unit, unit_, max_length_unit + 1); //unit
		price_btax = price_btax_; //the product’s price before taxes 
		quan_needed = quan_needed_;  //the quantity needed of the product
		quan_OnHand = quan_OnHand_;  //the quantity of the product on hand 
		taxable = taxable_;	//the product’s taxable status

	}

	//The Copy Constructor
	Product::Product(const Product& other) : pType(other.pType) {

		if (!other.isEmpty()) {
			nameOfPro = nullptr;
			*this = other;
		}
	}

	//The Copy Assignment Operator
	Product& Product::operator=(const Product& p) {
		delete[] nameOfPro;
		nameOfPro = new char[strlen(p.nameOfPro) + 1];
		strncpy(nameOfPro, p.nameOfPro, strlen(p.nameOfPro) + 1);
		nameOfPro[max_length_name] = '\0';

		strncpy(SKU, p.SKU, max_length_sku + 1);
		strncpy(unit, p.unit, max_length_unit + 1);
		price_btax = p.price_btax;
		quan_needed = p.quan_needed;
		quan_OnHand = p.quan_OnHand;
		taxable = p.taxable;  //the product’s taxable status 

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

	//totla cost
	double Product::total_cost() const {
		return cost() * quan_OnHand;
	}

	//true if the object is in the empty state
	bool Product::isEmpty() const {
		return nameOfPro == nullptr;
	}

	//(private) price after tax
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

		if (interractive == false) {

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

			read = Product(i_sku, i_name, i_unit, i_price, i_qty_needed, i_qty_available, i_taxable);
			*this = read;

		}

		else {
			std::cout << std::right << std::setw(max_length_label) << "Sku: ";
			in >> i_sku;

			std::cout << std::right << std::setw(max_length_label) << "Name (no spaces): ";
			in >> i_name;

			std::cout << std::right << std::setw(max_length_label) << "Unit: ";
			in >> i_unit;

			std::cout << std::right << std::setw(max_length_label) << "Taxed? (y/n): ";
			in >> interact_tax;

			//taxable
			if (interact_tax == 'y' || interact_tax == 'Y') {
				i_taxable = true;
			}
			else if (interact_tax == 'n' || interact_tax == 'N') {
				i_taxable = false;
			}
			else {
				errState = "Only (Y)es or (N)o are acceptable!";
				in.setstate(std::ios::failbit);	// sets the failure bit of the first parameter 	
			}

			//price
			if (!in.fail()) {
				std::cout << std::right << std::setw(max_length_label) << "Price: ";
				in >> i_price;

				if (in.fail()) {
					errState = "Invalid Price Entry!";
				}
			}

			//quantity on hand
			if (!in.fail()) {
				std::cout << std::right << std::setw(max_length_label) << "Quantity on hand: ";
				in >> i_qty_available;

				if (in.fail()) {
					errState = "Invalid Quantity Available Entry!";
				}
			}

			//quantity needed
			if (!in.fail()) {
				std::cout << std::right << std::setw(max_length_label) << "Quantity needed: ";
				in >> i_qty_needed;

				if (in.fail()) {
					errState = "Invalid Quantity Needed Entry!";
				}
			}

			if (!in.fail()) {

				read = Product(i_sku, i_name, i_unit, i_price, i_taxable, i_qty_needed, i_qty_available);
				*this = read;
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
		else if (writeMode == write_condensed) {
			out << pType << ',' << SKU << ',' << nameOfPro << ',' << unit << ','
				<< price_btax << ',' << taxable << ',' << quan_OnHand << ',' << quan_needed;
		}

		else if (writeMode == write_table) {
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
			out << std::right << std::setw(7) << price_btax << " | ";  //price before tax					
			if (taxable == true) {  //taxable
				out << std::right << std::setw(3) << "yes" << " | ";
			}
			else {
				out << std::right << std::setw(3) << "no" << " | ";
			}
			out << std::right << std::setw(6) << quan_OnHand << " | "; //quantity available					 
			out << std::right << std::setw(6) << quan_needed << " |"; //quatity needed
		}

		else if (writeMode == write_human) {
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