// Workshop 4 - Constructors - Test Main
// w4_in_home.cpp
// SBB
// 08/Feb/2019
// name: Youngeun Hong
// ID: 159100171


// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the constants here
	const int max_destination_size = 32; //the maximum number of characters for the destination of the trav-eler
	const int max_name_size = 16; // the maximum number of characters for the name of the traveler

	// TODO: define the Traveler class here
	class Traveler
	{
		char firstName[max_name_size];
		char lastName[max_name_size];
		char destination[max_destination_size];
		int yearDpt;
		int monthDpt;
		int dayDpt;

	public:
		Traveler();		//default constructor 
		Traveler(const char* F_Name, const char* L_Name, const char* Destination); //constructor with 3 parameters
		Traveler(const char* F_Name, const char* L_Name, const char* Destination, //constructor with 6 parameters
			const int y_dpt, const int m_dpt, const int d_dpt);

		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler& t) const;
			
	};
};

#endif

