// Date: 2019/03/18
// Author: Youngeun Hong(ID: 159100171)

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include <iostream>
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int bonus;
		int defend_strength;		

	public:
		SuperHero(); //defalt constructor
		SuperHero(const char * name_, int healthNum_, int strength_, int bnus, int dp_strength); //constructor with 5 parameters

		int attackStrength() const;
		int defend() const;
	};

	//a helper operator
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif
