// header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

// sict namespace
namespace sict
{
	const int max_title_size = 32; //the maximum number of characters for the title of the book
	const int max_name_size = 16; //the maximum number of characters for the name of the book author
	
	const long long min_isbn_value = 1000000000000; //the smallest ISBN that can be accepted
	const long long max_isbn_value = 9999999999999; //the largest ISBN that can be accepted by the application

	class Book
	{
			char familyName[max_name_size + 1];
			char givenName[max_name_size + 1];
			long long ISBN;
			char titleBook[max_title_size + 1];
			int year_published = 0;
			double priceBook = 0;

			
		public:
			void set(const char*, const char*, const char*, const long long);			
			bool isEmpty() const;
			void set(int year, double price);
			void display(bool tf = false) const;
	};
};

#endif