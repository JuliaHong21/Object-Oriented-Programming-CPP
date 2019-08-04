// Date: 2019/03/18
// Author: Youngeun Hong(ID: 159100171)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#include <cstring>

using namespace std;

namespace sict {

	//defalt constructor
	SuperHero::SuperHero() : Hero() {
		bonus = 0;
		defend_strength = 0;
	}

	//constructorr with 5 parameters
	SuperHero::SuperHero(const char * name_, int healthNum_, int strength_, int bnus, int dp_strength) : Hero(name_, healthNum_, strength_) {
		bonus = bnus;
		defend_strength = dp_strength;
	}
	
	//returns the attack strength of the current object including its super power bonus
	int SuperHero::attackStrength() const {	
		return (Hero::attackStrength() != 0) ? Hero::attackStrength() + bonus : 0;
	}

	//returns the defend strength of the current object
	int SuperHero::defend() const {
		return (defend_strength != 0) ? defend_strength : 0;
	}

	//a helper operator
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

		SuperHero fst = first;
		SuperHero snd = second;
		int rounds = 0;
		const SuperHero *winner = nullptr;

		for (int i = 0; i < max_rounds && fst.isAlive() && snd.isAlive(); i++) {

			fst -= snd.attackStrength() - fst.defend();
			snd -= fst.attackStrength() - snd.defend();
			
			rounds++;


			if (!fst.isAlive() && !snd.isAlive()) {
				winner = &first;
			}

			else if (!snd.isAlive()) {
				winner = &first;
			}

			else if (!fst.isAlive()) {
				winner = &second;
			}

		}

		//displays the names of the battle participants and the name of the winner
		cout << "Super Fight! " << fst;
		cout << " vs " << snd;
		cout << " : Winner is " << *winner;
		cout << " in " << rounds << " rounds." << endl;

		return *winner;
	
	}
}

