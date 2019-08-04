// Final Project Milestone 4 - ErrorState Class
// Version 3.4
// ms4_tester_prof.cpp
// Date	2019-03-27
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
// Cornel             2019-03-19           Winter term update
/////////////////////////////////////////////////////////////////
#include "iProduct.h"
#include "iProduct.h" // intentional
#include "Utilities.h"
// including standard headers after custom headers
//   is intentional in the tester
#include <iostream>
#include <iomanip>
#include <sstream>

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

void milestone4()
{
	// Test 1: Costants
	printTestHeader("M4-T1. Constants");
	cout << "| M4-T1. Checking that the constants are defined." << endl;
	::printBar();
	::printLabel("Label Length: ") << ama::max_length_label << endl;
	::printLabel("SKU Length: ") << ama::max_length_sku << endl;
	::printLabel("Unit Length: ") << ama::max_length_unit << endl;
	::printLabel("Name Length: ") << ama::max_length_name << endl;
	::printLabel("Tax Rate: ") << ama::tax_rate << endl;
	::printLabel("Write Condensed: ") << ama::write_condensed << endl;
	::printLabel("Write as Table: ") << ama::write_table << endl;
	::printLabel("Write Human Readable: ") << ama::write_human << endl;
	::printBar();

	// Test 2: Checking inheritance
	printTestHeader("M4-T2. Inheritance");
	{
		ama::iProduct* p = ama::createInstance('n');
		stringstream ss("8476,Disaster Relief Water Filter,package,1025.99,1,1,3");
		p->read(ss, false);
		::printBar();
		cout << *p; // print in human readable form
		::printBar();
		delete p;
	}

	// Test 3: check createInstance function and helpers
	printTestHeader("M4-T3. createInstance function");
	{
		iProduct* p1 = createInstance('n');
		iProduct* p2 = createInstance('N');
		stringstream ss("8476,Disaster Relief Water Filter,package,1000,0,2,3");
		p1->read(ss, false);
		ss.clear(); // remove the flag the EOF has been reached
		ss.seekg(ios::beg); // go to the begining of the stream
		ss.str("8477,Disaster Relief Water Filter,package,1000,1,2,3");
		p2->read(ss, false);
		::printBar();
		p1->write(cout, write_condensed);
		cout << endl;
		p2->write(cout, write_condensed);
		cout << endl;
		::printBar();

		double cost = 0;
		(cost += *p1) += *p2; // use the += helper
		::printLabel("total cost: ") << cost << endl;
		::printLabel("*p1 > *p2: ") << (*p1 > *p2 ? "true" : "false") << endl;
		::printBar();
		delete p1;
		delete p2;
	}
	printTestHeader("M4-T4. Create invalid instance");
	{
		iProduct* p = createInstance('a');
		::printBar();
		::printLabel("p == nullptr: ") << (p == nullptr ? "true" : "false") << endl;
		::printBar();
	}

}

int main()
{
	//	milestone1();
	//	milestone2();
	//	milestone3();
		milestone4();
	//	milestone5();
	return 0;
}
