#pragma once
#include <string>
#include "Class.h"
#include "Move.h"
#include "SoundPlayer.h"
// Hero - NPC/PC that fights an Enemy
class Hero:public Class, public SoundPlayer{
private:
	double experience; // Amount of XP hero has
	// Pause function
	void Pause() {
		Sleep(3000);
		cout << endl;
	}
public:
	// Constructor - Class, Name
	Hero() {};
	Hero(int type, string nm)
	{
		name = nm;
		lvl = 1;
		experience = 0;
		if (type == 1) {
			hp = 20;
			mp = 5;
			def = .85;
			atk = 2;
			typeClass = "Warrior";
			move1 = Move("PSI Fire A", 3, 2);
		}
		else if (type == 2) {
			hp = 15;
			mp = 10;
			def = .90;
			atk = 1.5;
			typeClass = "Mage";
			move1 = Move("PSI Flash A", 5, 3);
		}
		else {
			hp = 10;
			mp = 15;
			def = .95;
			atk = 1;
			typeClass = "Cleric";
			move1 = Move("PSI Freeze A", 4, 3);
		}
		hpMax = hp;
		mpMax = mp;
	}
	// Modifies attack - double modifier
	void setAtk(double mod) {
		atk += mod;
	}
	// Modifies defense - int modifier
	void setDef(int mod) {
		def += mod;
	}
	// Modifies MP - int modifier
	void setMP(int mod) {
		mp += mod;
	}
	// Modifies HP - int modifier
	void setHP(double mod) {
		hp += mod;
	}
	// Returns name
	string getName() {
		return name;
	}
	// Returns class
	string getClass() {
		return typeClass;
	}
	// Returns attack
	double getAtk() {
		return atk;
	}
	// Returns defense
	double getDef() {
		return def;
	}
	// Returns MP
	int getMP() {
		return mp;
	}
	// Returns HP
	double getHP() {
		return hp;
	}
	// Uses move, returns damage if any
	double useMove(int slot) {
		if (slot == 0) {
			cout << endl << name << " hit the enemy!" << endl << endl;
			playBash();
			return atk;
		}
		else if (slot == 1) {
			cout << name << " tried " << move1.getName() << "!" << endl;
			move1.playMoveSound();
			return move1.getPow() * atk;
		}
		else if (slot == 2) {
			cout << name << " tried " << move2.getName() << "!" << endl;
			move2.playMoveSound();
			return move2.getPow() * atk;
		}
		else if (slot == 3) {
			cout << name << " tried " << move3.getName() << "!" << endl;
			move3.playMoveSound();
			return move3.getPow() * atk;
		}
		else if (slot == 4) {
			cout << name << " tried " << move4.getName() << "!" << endl;
			move4.playMoveSound();
			return move4.getPow() * atk;
		}
		else { cout << name << " panicked!";
		return 0;
		}
	}
	// Returns Hero's XP
	double showXP() {
		return experience;
	}
	// Adds XP to total XP
	void getXP(double XP) {
		cout << name << " gained " << XP << " XP!";
		Pause();
		experience += XP;
		cout << name << " now has " << experience << " XP." << endl;
		Pause();
		if (experience >= 50 * lvl) {
			experience = 0;
			mp = mpMax;
			hp = hpMax;
			cout << name << " leveled up!";
			Pause();
			++lvl;
			learnMove();
			srand((unsigned)time(NULL));
			hp += rand() % 3 + 1;
			mp += rand() % 3 + 1;
			def -= (rand() % 2 + 1) * .01;
			atk += (rand() % 2 + 1) * .1;
			mpMax = mp;
			hpMax = hp;
		}
	}
	// Hero learns new move based on level
	void learnMove() {
		if (typeClass == "Warrior") {
			if (lvl == 2) {
				move2 = Move("PSI Hypnosis A", 0, 4);
				cout << name << " realized " << move2.getName() << "!";
			}
			else if (lvl == 3) {
				move3 = Move("PSI Rockin A", 5, 5);
				cout << name << " realized " << move3.getName() << "!";
			}
			else if (lvl == 4) {
				move4 = Move("PSI Shield A", 0, 4);
				cout << name << " realized " << move4.getName() << "!";
			}
			else if (lvl = 5) {
				move2 = Move("PSI Paralysis A", 0, 5);
				cout << name << " realized " << move2.getName() << "!";
			}
			else { cout << ""; }
		}
		else if (typeClass == "Mage") {
			if (lvl == 2) {
				move1 = Move("PSI Flash B", 8, 6);
				cout << name << " realized " << move1.getName() << "!";
			}
			else if (lvl == 3) {
				move2 = Move("PSI Thunder A", 11, 10);
				cout << name << " realized " << move2.getName() << "!";
			}
			else if (lvl == 4) {
				move3 = Move("PSI Magnet A", 0, 6);
				cout << name << " realized " << move3.getName() << "!";
			}
			else if (lvl = 5) {
				move3 = Move("PSI Magnet B", 0, 5);
				cout << name << " realized " << move3.getName() << "!";
			}
		}
		else {
			if (lvl == 2) {
				move2 = Move("PSI Lifeup A", 0, 5);
				cout << name << " realized " << move2.getName() << "!";
			}
			else if (lvl == 3) {
				move1 = Move("PSI Freeze B", 6, 5);
				cout << name << " realized " << move1.getName() << "!";
			}
			else if (lvl == 4) {
				move3 = Move("PSI Shield B", 0, 7);
				cout << name << " realized " << move3.getName() << "!";
			}
			else if (lvl = 5) {
				move2 = Move("PSI Lifeup B", 0, 8);
				cout << name << " realized " << move3.getName() << "!";
			}
		}
	}
	// Restores MP and HP
	void reset(){
		hp = hpMax;
		mp = mpMax;
	}
};