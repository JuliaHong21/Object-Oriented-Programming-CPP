// Workshop 3 - CLASSES AND PRIVACY
// SBB
// Date: 02/Fab/2019
// Author: Youngeun Hong
// ID: 159100171
// Email: yhong38@myseneca.ca


#include <iostream>
#include "Book.h"
#include "Book.h"

using namespace std;
using namespace sict;

int main()
{
	cout << "Book Management App" << endl;
	cout << "===================" << endl << endl;

	cout << "Checking the constants:" << endl;
	cout << "-----------------------" << endl;
	cout << "max_title_size = " << sict::max_title_size << endl;
	cout << "max_name_size = " << sict::max_name_size << endl;
	cout << "min_isbn_value = " << sict::min_isbn_value << endl;
	cout << "max_isbn_value = " << sict::max_isbn_value << endl << endl;

	sict::Book books[10];
	books[0].set("Frank",  "Herbert", "Dune", 91780441172719LL); // invalid
	books[0].set(1990, 9.73);
	books[1].set("Frank",  "Herbert", "Dune", 980441172719LL);   // invalid
	books[1].set(1990, 9.73);
	books[2].set("Frank",  "Herbert", "Dune", 9780441172718LL);  // invalid
	books[2].set(1990, 9.73);
	books[3].set("Frank",  "Herbert", "Dune", 9780441172709LL);  // invalid
	books[3].set(1990, 9.73);
	books[4].set("Frank",  "Herbert", "Dune", 9780441172619LL);  // invalid
	books[4].set(1990, 9.73);
	books[5].set("Frank",  "Herbert", "Dune", 9780441172719LL);  // valid
	books[5].set(1990, 9.73);
	books[6].set("George", "Orwell",  "1984", 9780451524935LL);  // valid
	books[6].set(1950, 6);
	books[7].set("Jane",   "Austen",  "Pride and Prejudice", 9780199535569LL);  // valid
	books[7].set(2008, 6.1);
	books[8].set("J.R.R.", "Tolkien", "The Lord of the Rings", 9780544003415LL);  // valid
	books[8].set(2012, 12.8);
	books[9].set("Harper", "Lee",     "To Kill a Mockingbird", 9780446310789LL);  // valid
	books[9].set(1988, 10.99);

	cout << "Displaying the library as a list:" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < 10; ++i)
	{
		if (books[i].isEmpty() == false)
			cout << endl;
		books[i].display(false);
	}
	cout << endl << endl;

	cout << "Displaying the library as a table:" << endl;
	cout << "-----------------------------------------------"
	     << "-----------------------------------------------" << endl;
	for (int i = 0; i < 10; ++i)
	{
		books[i].display(true);
	}
	cout << "-----------------------------------------------"
	     << "-----------------------------------------------" << endl;

	return 0;
}