// Final Project - Milestone 5
// Version 3.4
// Date	2019/03/10
// Authors:	Youngeun Hong(159100171)
// SBB
//
// For your final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Chris              2017/12/16           name changes for Fall
// Chris              2018/01/25           Product name changes
// Chris              2018/02/07           I/O Alignments
// Chris              2018-03-03           Message -> State
// Chris              2018-03-11           align with specs
// Cornel             2019.02              Modified the Date Class
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include "Date.h" // intentional
// including standard headers after custom headers
//   is intentional in the tester
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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

bool milestone1()
{
	// Test 1: Costants
	printTestHeader("T1. Constants");
	cout << "| T1.1. Checking that the constants are defined." << endl;
	::printBar();
	::printLabel("Min Year: ")          << ama::min_year << endl;
	::printLabel("Min Year: ")          << ama::min_year << endl;
	::printLabel("Max Year: ")          << ama::max_year << endl;
	::printLabel("No Error: ")          << ama::no_error << endl;
	::printLabel("Year Error: ")        << ama::error_year << endl;
	::printLabel("Month Error: ")       << ama::error_mon << endl;
	::printLabel("Day Error: ")         << ama::error_day << endl;
	::printLabel("Invalid Operation: ") << ama::error_invalid_operation << endl;
	::printLabel("Input Error: ")       << ama::error_input << endl;
	::printBar();

	// Test 2: Default Constructor
	printTestHeader("T2. Default Constructor");
	{
		Date aDate, anotherDate;

		cout << "| T2.1. Checking displaying an empty object." << endl;
		::printBar();
		::printLabel("Date::display(...): ");
		aDate.write(cout);
		cout << endl;

		::printLabel("operator<<(...): ") << aDate << endl;
		::printBar();

		cout << "| T2.2. Checking the state of an empty object." << endl;
		::printBar();
		::printLabel("Date::isGood(...): ") << aDate.isGood() << endl;
		::printLabel("Date::status(...): ") << aDate.status() << endl;
		::printBar();

		cout << "| T2.3. Checking relational operators on an empty object." << endl;
		::printBar();
		::printLabel("Date::operator==(...): ") << (aDate == anotherDate) << endl;
		::printLabel("Date::operator!=(...): ") << (aDate != anotherDate) << endl;
		::printLabel("Date::operator<(...): ")  << (aDate >  anotherDate) << endl;
		::printLabel("Date::operator>(...): ")  << (aDate <  anotherDate) << endl;
		::printLabel("Date::operator<=(...): ") << (aDate <= anotherDate) << endl;
		::printLabel("Date::operator>=(...): ") << (aDate >= anotherDate) << endl;
		::printBar();

		cout << "| T2.4. Checking += on an empty object." << endl;
		::printBar();
		{
			::printLabel("returned reference: ")
				<< (&aDate == &(aDate += 10)) << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
			aDate.clearError();
			::printLabel("aDate.clearError() -->", 0) << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		cout << "| T2.5 Checking + on an empty object." << endl;
		::printBar();
		{
			Date tmp = aDate + 10;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
		}
		::printBar();

		cout << "| T2.6. Checking postfix++ on an empty object." << endl;
		::printBar();
		{
			Date tmp = aDate++;
			::printLabel("tmp = aDate++ -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		cout << "| T2.7. Checking prefix++ on an empty object." << endl;
		::printBar();
		{
			Date& tmp = ++aDate;
			::printLabel("tmp = ++aDate -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
			aDate.clearError();
			::printLabel("aDate.clearError() -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp - Date::isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp - Date::status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();
	}

	// Test 3: Custom Constructor
	printTestHeader("T3. Custom Constructor");
	{
		cout << "| T3.1. Checking for invalid dates." << endl;
		::printBar();
		::printLabel("1020.10.15: ") << Date(1020, 10, 15) << endl;
		::printLabel("status - > 1020.10.15: ") << Date(1020, 10, 15).status() << endl;
		::printLabel("3020.10.15: ") << Date(3020, 10, 15) << endl;
		::printLabel("status - > 3020.10.15: ") << Date(3020, 10, 15).status() << endl;

		::printLabel("2020.13.15: ") << Date(2020, 13, 15) << endl;
		::printLabel("status - > 2020.13.15: ") << Date(2020, 13, 15).status() << endl;
		::printLabel("2020.00.15: ") << Date(2020, 00, 15) << endl;
		::printLabel("status - > 2020.00.15: ") << Date(2020, 00, 15).status() << endl;

		::printLabel("2020.10.32: ") << Date(2020, 10, 32) << endl;
		::printLabel("status - > 2020.10.32: ") << Date(2020, 10, 32).status() << endl;
		::printLabel("2020.10.00: ") << Date(2020, 10, 0) << endl;
		::printLabel("status - > 2020.10.00: ") << Date(2020, 10, 0).status() << endl;
		::printLabel("2021.02.29: ") << Date(2021, 02, 29) << endl;
		::printLabel("status - > 2021.02.29: ") << Date(2021, 02, 29).status() << endl;
		::printLabel("2021.04.31: ") << Date(2021, 04, 31) << endl;
		::printLabel("status - > 2021.04.31: ") << Date(2021, 04, 31).status() << endl;
		::printBar();

		cout << "| T3.2. Checking for valid dates." << endl;
		::printBar();
		::printLabel("2020.10.15: ") << Date(2020, 10, 15) << endl;
		::printLabel("status - > 2020.10.15: ") << Date(2020, 10, 15).status() << endl;

		::printLabel("2020.10.31: ") << Date(2020, 10, 31) << endl;
		::printLabel("status - > 2020.10.31: ") << Date(2020, 10, 31).status() << endl;

		::printLabel("2020.10.01: ") << Date(2020, 10, 01) << endl;
		::printLabel("status - > 2020.10.01: ") << Date(2020, 10, 01).status() << endl;

		::printLabel("2020.02.29: ") << Date(2020, 02, 29) << endl;
		::printLabel("status - > 2020.02.29: ") << Date(2020, 02, 29).status() << endl;
		::printBar();
	}

	// Test 4: Operations
	printTestHeader("T4. Operations");
	{
		Date aDate(2022, 10, 15), anotherDate(2022, 10, 25);

		cout << "| T4.1. Checking relational operators on a valid object." << endl;
		::printBar();
		{
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("anotherDate: ") << anotherDate << endl;
			::printLabel("aDate == anotherDate: ") << (aDate == anotherDate) << endl;
			::printLabel("anotherDate == aDate: ") << (anotherDate == aDate) << endl;
			::printLabel("aDate != anotherDate: ") << (aDate != anotherDate) << endl;
			::printLabel("anotherDate != aDate: ") << (anotherDate != aDate) << endl;
			::printLabel("aDate > anotherDate: ") << (aDate > anotherDate) << endl;
			::printLabel("anotherDate > aDate: ") << (anotherDate > aDate) << endl;
			::printLabel("aDate < anotherDate: ") << (aDate < anotherDate) << endl;
			::printLabel("anotherDate < aDate: ") << (anotherDate < aDate) << endl;
			::printLabel("aDate <= anotherDate: ") << (aDate <= anotherDate) << endl;
			::printLabel("anotherDate <= aDate: ") << (anotherDate <= aDate) << endl;
			::printLabel("aDate >= anotherDate: ") << (aDate >= anotherDate) << endl;
			::printLabel("anotherDate >= aDate: ") << (anotherDate >= aDate) << endl;

			::printLabel("aDate == 2022.10.15: ") << (aDate == Date(2022, 10, 15)) << endl;
			::printLabel("aDate != 2022.10.15: ") << (aDate != Date(2022, 10, 15)) << endl;
			::printLabel("aDate > 2022.10.15: ") << (aDate > Date(2022, 10, 15)) << endl;
			::printLabel("aDate < 2022.10.15: ") << (aDate < Date(2022, 10, 15)) << endl;
			::printLabel("aDate <= 2022.10.15: ") << (aDate <= Date(2022, 10, 15)) << endl;
			::printLabel("aDate >= 2022.10.15: ") << (aDate >= Date(2022, 10, 15)) << endl;
		}
		::printBar();

		cout << "| T4.2. Checking += on a valid object." << endl;
		::printBar();
		{
			::printLabel("aDate: ") << aDate << endl;
			aDate += 3;
			::printLabel("aDate += 3: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		cout << "| T4.3. Checking + on a valid object." << endl;
		::printBar();
		{
			::printLabel("aDate: ") << aDate << endl;
			Date tmp = aDate + 3;
			::printLabel("tmp = aDate + 3: -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		cout << "| T4.4. Checking postfix++ on a valid object." << endl;
		::printBar();
		{
			Date tmp = aDate++;
			::printLabel("tmp = aDate++ -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		cout << "| T4.5. Checking prefix++ on a valid object." << endl;
		::printBar();
		{
			Date& tmp = ++aDate;
			::printLabel("tmp = ++aDate -->", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
		}
		::printBar();

		aDate = Date(2022, 10, 15);
		anotherDate = Date(2022, 10, 22);

		cout << "| T4.6. Checking overflow for + on a valid object." << endl;
		::printBar();
		{
			Date tmp = aDate + 17;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.isGood(...): ") << aDate.isGood() << endl;
			::printLabel("aDate.status(...): ") << aDate.status() << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;

			tmp += 5;
			::printLabel("tmp += 5: ", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;

			tmp.clearError();
			::printLabel("tmp.clearError(): ", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("tmp == anotherDate: ") << (tmp == anotherDate) << endl;

			tmp += 7;
			::printLabel("tmp += 7: ", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("tmp == anotherDate: ") << (tmp == anotherDate) << endl;

			tmp += -25;
			::printLabel("tmp += -25: ", 0) << endl;
			::printLabel("tmp: ") << tmp << endl;
			::printLabel("tmp.isGood(...): ") << tmp.isGood() << endl;
			::printLabel("tmp.status(...): ") << tmp.status() << endl;
			::printLabel("tmp == anotherDate: ") << (tmp == anotherDate) << endl;
		}
		::printBar();
	}

	// Test 5: Extraction Operator
	printTestHeader("T5. Extraction Operator");
	::printBar();
	{
		Date aDate;

		char buffer[32] = {};
		std::ifstream inRaw;
		inRaw.open("dates.txt"); // so the user doesn't have to type

		int idx = 0;
		do
		{
			inRaw >> buffer;
			if (inRaw.eof())
				break;

			stringstream ss(buffer);
			ss >> aDate;
			cout << "Attempt " << ++idx << endl;
			::printLabel("text: ") << buffer << endl;
			::printLabel("aDate: ") << aDate << endl;
			::printLabel("aDate.status(): ") << aDate.status() << endl;
			::printLabel("aDate.isGood(): ") << aDate.isGood() << endl;
			::printLabel("istream.fail(): ") << ss.fail() << endl;
		} while (true); // we exit from the loop with break.

		inRaw.close();
	}
	::printBar();

	return true;
}

int main()
{
	milestone1();
//	milestone2();
//	milestone3();
//	milestone4();
//	milestone5();
	return 0;
}
