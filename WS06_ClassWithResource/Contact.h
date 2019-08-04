// Date: 2019/Mar/11
// Author: Youngeun Hong(ID: 159100171)
//section: SBB

//header file guard
#ifndef sict_CONTACT_H
#define sict_CONTACT_H

namespace sict {
	const int max_name_size = 16; //the maximum number of characters for the name of the traveler
	
	class Contact {
		
		char name[max_name_size];
		long long* phoneNumber;
		int numOfPhone;

	public:
		Contact();
		Contact(const char *, const long long *, int);
		Contact(const Contact& src);
		Contact& operator=(const Contact& rhs);
		Contact& operator+=(long long phoneNumber);
		~Contact(); 			

		bool isEmpty() const;
		void display() const;		
	};
}

#endif
