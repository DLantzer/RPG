#pragma once
#include "Move.h"
#include <time.h>
// Class - Hero or Enemy that has stats and status effects, and can use Moves.
class Class:public Move{
protected:
	bool isFrozen, isParalysed, isShielded; // Status conditions, true/false
	string typeClass, name; // Class type, NPC/PC name
	int mp, mpMax, lvl; // Stats
	double atk, def, hp, hpMax; // Atk & Def stat, type double serves as a multiplier
public:
	Move move1, move2, move3, move4; // Moveset

	//Uses physical move purely based on attack
	double usePhysical() {
		srand((unsigned)time(NULL));
		return (rand() % 2 + 1) * lvl * atk;
	}
	// Modifies moveset - Move, slot #
	void setMove(Move m, int num) {
		if (num == 1) {
			move1 = m;
		}
		else if (num == 2) {
			move2 = m;
		}
		else if (num == 3) {
			move3 = m;
		}
		else if (num == 4) {
			move4 = m;
		}
		else cout << "Couldn't set move.";
		cout << name << " realized " << m.getName() << "!" << endl;
	}
	// Prints stats
	void viewStats() {
		cout << endl << "Name: " <<  name << endl
			<< "Class: " << typeClass << endl
			<< "Level " << lvl << endl
			<< hp << " HP" << endl
			<< mp << " MP" << endl
			<< atk << " Attack" << endl
			<< def << " Defense" << endl;
	}
	// Returns atk
	double getAtk() {
		return atk;
	}
	// Returns name of move - Slot #
	string getMove(int num) 
	{
		if (num == 1) return move1.getName();
		else if (num == 2) return move2.getName();
		else if (num == 3) return move3.getName();
		else if (num == 4) return move4.getName();
		else return "error returning move name";
	}
};