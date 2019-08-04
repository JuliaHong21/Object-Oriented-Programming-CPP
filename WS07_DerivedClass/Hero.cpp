// Date: 2019/03/18
// Author: Youngeun Hong(ID: 159100171)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {

	//defalt instructor
	Hero::Hero() { 
		name[0] = '\0';
		healthNum = 0;
		strength = 0;
	}

	//constructor with 3 parameters
	Hero::Hero(const char * name_, int healthNum_, int strength_) {
		if (name_ != nullptr && name_[0] != '\0' && healthNum_ > 0 && strength_ > 0) {
			strncpy(name, name_, 41);
			name[40] = '\0';
			healthNum = healthNum_;
			strength = strength_;
		}
		else {
			*this = Hero();
		}
	}	

	//if that strength is positive-valued, deducts that strength from the cur-rent object’s health
	void Hero::operator-=(int attact) {
		if (attact > 0) {
			healthNum -= attact;

			if (healthNum < 0) {
				healthNum = 0;
			}
		}
	}

	//returns true if the current object is healthy and false otherwise
	bool Hero::isAlive() const {
		bool survive = false;
			if (healthNum != 0)
			{
				survive = true;
			}
		return survive; 
	}

	// checks the safe empty states
	bool Hero::isEmpty() const {
		return (name[0] == '\0' && healthNum == 0 && strength == 0);
	}

	//returns the attack strength of the current object
	int Hero::attackStrength() const { 
		
		return (isEmpty() == false) ? strength : 0;
	}	

	//inserts the name of hero into stream os 
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.name == nullptr && hero.name[0] == '\0' && hero.healthNum <= 0 && hero.strength) {
			os << "No hero";
		}
		else {
			os << hero.name;
		}
		return os;
	}

	//a helper operator
	//returns a reference to the winner object
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero fst = first;
		Hero snd = second;
		int rounds = 0;
		const Hero *winner = nullptr;		

		for (int i = 0 ; i < max_rounds && fst.isAlive() && snd.isAlive(); i++) {

			fst -= snd.attackStrength();
			snd -= fst.attackStrength();
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
		cout << "Ancient Battle! " << fst; 
		cout << " vs "<< snd; 
		cout << " : Winner is " << *winner;			 
		cout << " in " << rounds << " rounds." << endl;

		return *winner;
	}
}