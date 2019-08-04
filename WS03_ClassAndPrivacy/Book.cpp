#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sict {

	//To check if ISBN is a valid one
	void Book::set(const char * given_name, const char * family_name, const char * title_book, const long long isbn)
	{
		long long tmpISBN = isbn;

		if (isbn >= min_isbn_value && isbn <= max_isbn_value) {			

			//The home part(new)
			int checkDigit = tmpISBN % 10;
			int position = 2; //Positions of ISBN numbers except the checkDigit		
			int evenSum = 0, oddSum = 0;
			int totalSum;
			int nextMultiple;
			int diff;

			while (position <= 13) 
			{
				if (position % 2 == 0) {
					evenSum += (tmpISBN / 10) % 10; //The sum of digits on even positions
					tmpISBN /= 10;
				}
				else {
					oddSum += (tmpISBN / 10) % 10; //The sum of digits on odd positions
					tmpISBN /= 10;
				}

				position++;
			}

			totalSum = (evenSum * 3) + oddSum; //Total sum(The sum of digits on even positions is multiplied by three)
			nextMultiple = totalSum - (totalSum % 10) + 10; // To fint next highest integer multiple of 10.
			diff = nextMultiple - totalSum; //Difference

			if (diff == checkDigit) { //To check if the difference matches the check digit
				ISBN = isbn;

				//To prevent overflow the space allocated for the title 
				strncpy(givenName, given_name, max_name_size +1);
				strncpy(familyName, family_name, max_name_size +1);
				strncpy(titleBook, title_book, max_title_size +1);
			}

			else {
				ISBN = 0; //empty state
			}			
		}

		else {
			ISBN = 0; //empty state
		}
	}

	bool Book::isEmpty() const
	{
		int TF;
		if (ISBN == 0) {
			TF = 1;
		} //true if the object is in a safe empty state

		else {
			TF = 0;
		} //false if the object is not in a safe empty state

		return TF;

	}

	// The home part(new)
	void Book::set(int year, double price) {
		if (isEmpty() == 0) {
			year_published = year;
			priceBook = price;
		}
	}

	// The home part(modify and add)
	void Book::display(bool tf) const
	{
		if (isEmpty()) {
			if (tf == true) {  
				cout << "|"; 
				cout.width(92); cout << left << "The book object is empty!"; 
				cout << "|" << endl;
			}
			else {  
				cout << "The book object is empty!" << endl;
			}
		}

		else {
			if (tf == true) {  
				cout << "|";
				cout.width(max_name_size); cout << right << familyName;
				cout << "|";
				cout.width(max_name_size); cout << right << givenName;
				cout << "|";
				cout.width(max_title_size); cout << left << titleBook;
				cout << "|";
				cout.width(13); cout << right << ISBN;
				cout << "|";
				cout.width(4); cout << right << year_published;
				cout << "|";
				cout.width(6); cout.setf(ios::fixed); cout.precision(2); cout << right << priceBook;
				cout << "|" << endl;
			}

			else {  
				cout << "Author: " << familyName << ", " << givenName << endl;
				cout << "Title: " << titleBook << endl;
				cout << "ISBN-13: " << ISBN << endl;
				cout << "Publication Year: " << year_published << endl;
				cout << "Price: " << priceBook << endl;				
			}

		}
	}
}

