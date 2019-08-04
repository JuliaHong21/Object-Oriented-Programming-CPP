// Final Project Milestone 3 - ErrorState Class
// Version 3.4
// ms2_tester_prof.cpp
// Date	2019-03-24
// Author	Youngeun Hong
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// CS                 2017-10-11           Fall semester upgrade
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           Message -> State
// Cornel             2019-03-15           Winter term update
/////////////////////////////////////////////////////////////////
#include "Product.h"
#include "Product.h" // intentional
#include "ErrorState.h"
#include "ErrorState.h" // intentional
// including standard headers after custom headers
//   is intentional in the tester
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Utilities.h"

using namespace std;
using namespace ama;


void printTestHeader(const char* pName, int size = 34, std::ostream& out = cout)
{
	out << endl;
	out << setfill('=') << setw(size) << "" << endl;
	// -4 to account for the bars at the begining and end of the line
	out << "| " << setfill(' ') << left << setw(size - 4) << pName << " |" << endl;
	out << setfill('=') << setw(size) << "" << setfill(' ') << endl;
}
void printBar(int size = 64, std::ostream& out = cout)
{
	out << setfill('-') << setw(size) << "" << setfill(' ') << endl;
}
std::ostream& printLabel(const char* pLabel, int size = 24, std::ostream& out = cout)
{
	out.setf(ios::right);
	out << setw(size) << pLabel;
	out.unsetf(ios::right);
	return out;
}

void printProductObject(const Product& prod, const char* pOperation = nullptr)
{
	::printBar();
	if (pOperation != nullptr)
		::printLabel(pOperation, 0) << endl;
	::printLabel("isEmpty(): ") << (prod.isEmpty() ? "true" : "false") << endl;
	::printLabel("content -->") << endl << prod;
	::printBar();
}



void milestone3()
{
	// Test 1: Costants 
	printTestHeader("M3-T1. Constants");
	cout << "| M3-T1. Checking that the constants are defined." << endl;
	::printBar();
	::printLabel("Label Length: ") << ama::max_length_label << endl;
	::printLabel("SKU Length: ")  << ama::max_length_sku << endl;
	::printLabel("Unit Length: ") << ama::max_length_unit << endl;
	::printLabel("Name Length: ") << ama::max_length_name << endl;
	::printLabel("Tax Rate: ")    << ama::tax_rate << endl;
	::printLabel("Write Condensed: ") << ama::write_condensed << endl;
	::printLabel("Write as Table: ") << ama::write_table << endl;
	::printLabel("Write Human Readable: ") << ama::write_human << endl;
	::printBar();
	
	printTestHeader("M3-T2. Default Constructor");
	{
		Product theProduct;
		printProductObject(theProduct);
	}

	printTestHeader("M3-T3. Custom Constructor");
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package",
			123.80, 5, 3, true);
		cout << "| M2-T3.1. Constructor receives valid parameters." << endl;
		printProductObject(theProduct);
	}
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package");
		cout << "| M2-T3.2. Constructor receives default parameters." << endl;
		printProductObject(theProduct);
	}
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package",
			123.80, 5, 3, false);
		cout << "| M2-T3.3. Non-taxable product." << endl;
		printProductObject(theProduct);
	}

	printTestHeader("M3-T3. Copy Constructor");
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package",
			123.80, 5, 3, true);
		Product copy(theProduct);
		printProductObject(copy);
	}

	printTestHeader("M3-T4. Copy Assignment Operator");
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package",
			123.80, 5, 3, true);
		Product copy;
		copy = theProduct;
		printProductObject(copy);
	}

	printTestHeader("M3-T5. Testing Operators");
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package",
			123.80, 5, 3, true);
		Product copy = theProduct;
		cout << "| M3-T5.1. Comparing on SKU." << endl;
		::printBar();
		::printLabel("copy = Product('1234', 'Disas...', ...) -->") << endl;
		::printLabel("operator=='1234': ") << (copy == "1234" ? "true" : "false") << endl;
		::printLabel("operator=='1111': ") << (copy == "1111" ? "true" : "false") << endl;
		::printLabel("operator>'1234': ") << (copy > "1234" ? "true" : "false") << endl;
		::printLabel("operator>'1233': ") << (copy > "1233" ? "true" : "false") << endl;
		::printLabel("operator>'233': ") << (copy > "233" ? "true" : "false") << endl;
		::printBar();

		cout << "| M3-T5.2. Comparing on name." << endl;
		::printBar();
		::printLabel("copy = Product('1234', 'A Disas...', ...) -->") << endl;
		copy = Product("1234", "A Disaster Relief Water Filter", "package", 123.80, 5, 3, true);
		::printLabel("copy > prod: ") << (copy > theProduct ? "true" : "false") << endl;
		::printLabel("prod > copy: ") << (theProduct > copy ? "true" : "false") << endl;
		::printBar();

		cout << "| M3-T5.3. Comparing on name." << endl;
		::printBar();
		::printLabel("copy = Product('1234', 'The Disas...', ...) -->") << endl;
		copy = Product("1234", "The Disaster Relief Water Filter", "package", 123.80, 5, 3, true);
		::printLabel("copy > prod: ") << (copy > theProduct ? "true" : "false") << endl;
		::printLabel("prod > copy: ") << (theProduct > copy ? "true" : "false") << endl;
		::printBar();

		cout << "| M3-T5.4. Testing += operator." << endl;
		::printBar();
		copy = Product("1234", "The Disaster Relief Water Filter", "package", 100, 5, 3, false);
		double cost = 0;
		cost += theProduct;
		cost += copy;
		::printLabel("total cost: ") << cost << endl;
		::printBar();
	}

	printTestHeader("M3-T6. Testing the write() function.");
	{
		Product theProduct("1234", "Disaster Relief Water Filter", "package", 123.80, 5, 3, true);
		cout << "| M3-T6.1. Human readable content." << endl;
		::printBar();
		theProduct.write(cout, write_human);
		::printBar();

		cout << "| M3-T6.2. Content as a table." << endl;
		::printBar();
		theProduct.write(cout, write_table);
		cout << endl;
		::printBar();

		cout << "| M3-T6.3. Content in condensed format." << endl;
		::printBar();
		theProduct.write(cout, write_condensed);
		cout << endl;
		::printBar();
	}

	printTestHeader("M3-T7. Testing write() again.");
	{
		Product theProduct('Z');
		cout << "| M3-T7.1. Human readable empty content." << endl;
		::printBar();
		cout << "[";
		theProduct.write(cout, write_human);
		cout << "]" << endl;
		::printBar();

		cout << "| M3-T7.2. Empty content as a table." << endl;
		::printBar();
		cout << "[";
		theProduct.write(cout, write_table);
		cout << "]" << endl;
		::printBar();

		cout << "| M3-T7.3. Empty content in condensed format." << endl;
		::printBar();
		cout << "[";
		theProduct.write(cout, write_condensed);
		cout << "]" << endl;
		::printBar();
	}

	printTestHeader("M3-T8. Testing read() from stream.");
	{
		cout << "| M3-T8.1. Default product tag." << endl;
		Product theProduct;
		stringstream ss("8476,Disaster Relief Water Filter,package,3.99,0,1,3");
		theProduct.read(ss, false);
		::printBar();
		theProduct.write(cout, write_human);
		theProduct.write(cout, write_condensed);
		cout << endl;
		::printBar();
	}
	{
		cout << "| M3-T8.2. Custom product tag." << endl;
		Product theProduct('Z');
		stringstream ss("8476,Disaster Relief Water Filter,package,3.99,0,1,3");
		theProduct.read(ss, false);
		::printBar();
		theProduct.write(cout, write_condensed);
		cout << endl;
		::printBar();
	}

	printTestHeader("M3-T9. Testing read() from user.");
	{
		cout << "| M3-T9.1. Testing valid product." << endl;
		cout << "|    Type the following data:" << endl;
		cout << "|         sku: [" << "1111" << "]" << endl;
		cout << "|        name: [" << "Blanket" << "]" << endl;
		cout << "|        unit: [" << "units" << "]" << endl;
		cout << "|       taxed: [" << "y" << "]" << endl;
		cout << "|       price: [" << "1.1" << "]" << endl;
		cout << "|  quantity a: [" << "1" << "]" << endl;
		cout << "|  quantity n: [" << "1" << "]" << endl;
		::printBar();

		Product theProduct;
		cin >> theProduct;
		::printBar();
		cout << theProduct;
		::printLabel("cin.fail(): ") << (cin.fail() ? "true" : "false") << endl;
		::printBar();
	}
	{
		cout << "| M3-T9.2. Testing invalid taxed input." << endl;
		cout << "|    Type the following data:" << endl;
		cout << "|         sku: [" << "1111" << "]" << endl;
		cout << "|        name: [" << "Blanket" << "]" << endl;
		cout << "|        unit: [" << "units" << "]" << endl;
		cout << "|       taxed: [" << "a" << "]" << endl;
		::printBar();

		Product theProduct;
		cin >> theProduct;
		::printBar();
		::printLabel("object content: ") << "[" << theProduct << "]" << endl;
		::printLabel("cin.fail(): ") << (cin.fail() ? "true" : "false") << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		::printBar();
	}
	{
		cout << "| M3-T9.3. Testing invalid price input." << endl;
		cout << "|    Type the following data:" << endl;
		cout << "|         sku: [" << "1111" << "]" << endl;
		cout << "|        name: [" << "Blanket" << "]" << endl;
		cout << "|        unit: [" << "units" << "]" << endl;
		cout << "|       taxed: [" << "y" << "]" << endl;
		cout << "|       price: [" << "a" << "]" << endl;
		::printBar();

		Product theProduct;
		cin >> theProduct;
		::printBar();
		::printLabel("object content: ") << "[" << theProduct << "]" << endl;
		::printLabel("cin.fail(): ") << (cin.fail() ? "true" : "false") << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		::printBar();
	}
	{
		cout << "| M3-T9.4. Testing invalid available quantity input." << endl;
		cout << "|    Type the following data:" << endl;
		cout << "|         sku: [" << "1111" << "]" << endl;
		cout << "|        name: [" << "Blanket" << "]" << endl;
		cout << "|        unit: [" << "units" << "]" << endl;
		cout << "|       taxed: [" << "y" << "]" << endl;
		cout << "|       price: [" << "1.1" << "]" << endl;
		cout << "|  quantity a: [" << "a" << "]" << endl;
		::printBar();

		Product theProduct;
		cin >> theProduct;
		::printBar();
		::printLabel("object content: ") << "[" << theProduct << "]" << endl;
		::printLabel("cin.fail(): ") << (cin.fail() ? "true" : "false") << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		::printBar();
	}
	{
		cout << "| M3-T9.5. Testing invalid needed quantity input." << endl;
		cout << "|    Type the following data:" << endl;
		cout << "|         sku: [" << "1111" << "]" << endl;
		cout << "|        name: [" << "Blanket" << "]" << endl;
		cout << "|        unit: [" << "units" << "]" << endl;
		cout << "|       taxed: [" << "y" << "]" << endl;
		cout << "|       price: [" << "1.1" << "]" << endl;
		cout << "|  quantity a: [" << "1" << "]" << endl;
		cout << "|  quantity n: [" << "a" << "]" << endl;
		::printBar();

		Product theProduct;
		cin >> theProduct;
		::printBar();
		::printLabel("object content: ") << "[" << theProduct << "]" << endl;
		::printLabel("cin.fail(): ") << (cin.fail() ? "true" : "false") << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		::printBar();

		
	} 
}

int main()
{
	//	milestone1();
	//	milestone2();
	milestone3();
	//	milestone4();
	//	milestone5();
	return 0;
}
