// Workshop 4 - Constructors - Test Main
// w4_in_home.cpp
// SBB
// 08/Feb/2019
// name: Youngeun Hong
// ID: 159100171


#include <iostream>
#include "Traveler.h"

using namespace std;
using namespace sict;

int main()
{
	Traveler travelers[] = {
		Traveler(nullptr, "Smith", "Toronto", 2020,  4, 20),
		Traveler("",      "Smith", "Toronto", 2020,  4, 20),
		Traveler("John",  "",      "Toronto", 2020,  4, 20),
		Traveler("John",  "Smith", nullptr,   2020,  4, 20),
		Traveler("John",  "Smith", "",        2020,  4, 20),
		Traveler("John",  "Smith", "Toronto", 2020,  4, 20), // valid
		Traveler("John",  "Smith", "Toronto", 2028,  4, 20),
		Traveler("John",  "Smith", "Toronto", 2014,  4, 20),
		Traveler("John",  "Smith", "Toronto", 2022, 12, 31), // valid
		Traveler("John",  "Smith", "Toronto", 2020, 40, 20),
		Traveler("John",  "Smith", "Toronto", 2020,  0, 20),
		Traveler("John",  "Smith", "Toronto", 2019,  1,  1), // valid
		Traveler("John",  "Smith", "Toronto", 2020,  4,  0),
		Traveler("John",  "Smith", "Toronto", 2020,  4, 32),
		Traveler(nullptr, nullptr, nullptr,      0,  0,  0),
		Traveler("John",  "Smith", "Toronto"),               // valid
		Traveler()
	}; 
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only travelers 6, 9, 12 and 16 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 17; ++i)
	{
		cout << "Traveler " << i + 1 << ": " 
            << (travelers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;
	
	Traveler david("David", "Davis", "Toronto", 2019, 6, 20);
	Traveler friends[] = {
		Traveler("Vanessa",  "Miller",  "Toronto", 2019,  6, 20),
		Traveler("John",     "Miller",  "Toronto", 2019,  6,  6),
		Traveler("Alice",    "Turner",  "Toronto", 2019, 10, 20),
		Traveler("Bob",      "Moore",   "Paris",   2019,  6, 20),
		Traveler("Jennifer", "Hill",    "Toronto", 2020,  6, 20),
		Traveler("Mike",     "Flores",  "Toronto", 2019,  6, 20),
		Traveler("Sarah",    "Stewart", "Toronto", 2019,  6, 20),
		Traveler("Mark",     "Simmons", "Toronto")
	};

	cout << "----------------------------------------" << endl;
	cout << "Testing Traveler::display(...)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 8; ++i)
		friends[i].display();
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "Testing Traveler::canTravelWith(...)" << endl;
	cout << "----------------------------------------" << endl;
	cout << david.name() << " can travel with: " << endl;
	for (int i = 0; i < 8; ++i)
	{
		if (david.canTravelWith(friends[i]))
			cout << "  - " << friends[i].name() << endl;
    }
	cout << "----------------------------------------" << endl << endl; 

	return 0; 
}
