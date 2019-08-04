// Date: 2019/03/18
// Author: Youngeun Hong(ID: 159100171)

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include<iostream>

namespace sict {
	const int max_rounds = 100;
	class Hero {
		char name[41];
		int healthNum;
		int strength;		

	public:
		Hero(); //defalt constructor
		Hero(const char *, int, int); //constructor with 3 parameters
				
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;

		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif
