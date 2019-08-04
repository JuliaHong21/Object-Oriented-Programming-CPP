// Final Project Milestone 2 - ErrorState Class
// Version 3.4
// ms2_tester_prof.cpp
// Date	2019-03-09
// Author	Cornel, Chris Szalwinski, Fardad Soleimanloo
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
// Cornel             2019-03-09           Winter term update
/////////////////////////////////////////////////////////////////
#include "ErrorState.h"
#include "ErrorState.h" // intentional
// including standard headers after custom headers
//   is intentional in the tester
#include <iostream>
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

void printMessageObject(const ErrorState& msg, const char* pOperation = nullptr)
{
	::printBar();
	if (pOperation != nullptr)
		::printLabel(pOperation, 0) << endl;
	::printLabel("msg.operator<<(...): ") << "[" << msg << "]" << endl;
	::printLabel("(bool)msg: ")           << (msg ? "true" : "false") << endl;
	::printLabel("msg.message(): ")       << (msg.message() == nullptr ? "null" : msg.message()) << endl;
	::printBar();
}



void milestone2()
{
	// M2 Test 1: Default Constructor
	printTestHeader("M2-T1. Default Constructor");
	{
		ErrorState msg;
		cout << "| M2-T1.1. Checking displaying an empty object." << endl;
		::printMessageObject(msg, "ErrorState msg; -->");
	}
	cout << endl;

	// M2 Test 2: Custom Constructor
	printTestHeader("M2-T2. Custom Constructor");
	{
		ErrorState msg(nullptr);
		cout << "| M2-T2.1. Constructor receives null pointer." << endl;
		::printMessageObject(msg, "ErrorState msg(nullptr); -->");
	}
	{
		ErrorState msg("");
		cout << "| M2-T2.2. Constructor receives empty string." << endl;
		::printMessageObject(msg, "ErrorState msg(\"\"); -->");
	}
	{
		ErrorState msg("Hello World!");
		cout << "| M2-T2.3. Constructor receives valid string." << endl;
		::printMessageObject(msg, "ErrorState msg(...); -->");
	}
	cout << endl;

	// M2 Test 3: The message(...) modifier
	printTestHeader("M2-T3. The message() modifier");
	{
		ErrorState msg;
		msg.message("Hello!");
		cout << "| M2-T3.1. Set a valid string." << endl;
		::printMessageObject(msg, "msg.message(\"Hello!\"); -->");
	}
	{
		ErrorState msg("Hello!");
		msg.message("");
		cout << "| M2-T3.2. Set an empty string." << endl;
		::printMessageObject(msg, "msg.message(\"\"); -->");
	}
	{
		ErrorState msg("Hello!");
		msg.message(nullptr);
		cout << "| M2-T3.3. Set a null pointer." << endl;
		::printMessageObject(msg, "msg.message(\"\"); -->");
	}
	cout << endl;

	// M2 Test 4: The assignment operator
	printTestHeader("M2-T4. The assignment operator");
	{
		ErrorState msg;
		msg = "Hello!";
		cout << "| M2-T4.1. Set a valid string." << endl;
		::printMessageObject(msg, "msg = \"Hello!\"; -->");
	}
	{
		ErrorState msg("Hello!");
		msg = "";
		cout << "| M2-T4.2. Set an empty string." << endl;
		::printMessageObject(msg, "msg = \"\"; -->");
	}
	{
		ErrorState msg("Hello!");
		msg = nullptr;
		cout << "| M2-T4.3. Set a null pointer." << endl;
		::printMessageObject(msg, "msg = nullptr; -->");
	}
	cout << endl;
}
int main()
{
//	milestone1();
	milestone2();
//	milestone3();
//	milestone4();
//	milestone5();
	return 0;
}
