// Workshop 6 - Class with a Resource
// w6_at_home.cpp
// Youngeun Hong (ID: 159100171)
// SBB
// 2019/03/11

#include <iostream>
#include "Contact.h"
#include "Contact.h" // intentional

using namespace std;
using namespace sict;

int main()
{
	cout << "Max name size: " << sict::max_name_size << endl;

    sict::Contact theContact("John Doe", nullptr, 0); // sict:: intentional
    theContact.display();

	cout << endl;
	theContact +=   14161234567LL; // valid
    theContact +=   14162345678LL; // valid
	theContact +=   10162345678LL;
	theContact +=   14163456789LL; // valid
	theContact +=    4163456789LL;
	theContact +=  114164567890LL; // valid
	theContact += 1104164567890LL;
	theContact.display();

    cout << endl << "Testing Copy Constructor and Copy Assignment Operator!"
		 << endl << "    Please wait:" << endl;

    for (int i = 1; i <= 5000000; ++i)
    {
        Contact temp = theContact;
        theContact = temp;
        theContact = theContact;
        if (!(i % 10000))
            cout << ".";
        if (!(i % 500000))
            cout << endl;
    }
    cout << endl;
    theContact.display();

	theContact = Contact("", nullptr, 0);
	theContact += 14161230002LL;
	theContact.display();

	cout << endl;
	auto aNumber = 14161234567LL; // valid phone number
	theContact = Contact("John Doe", &aNumber, 1);
	theContact.display();

	cout << endl;
	aNumber = 7104164567890LL; // invalid phone number
	theContact = Contact("John Doe", &aNumber, 1);
	theContact.display();

    return 0;
}
