#pragma once
#include "Class.h"
#include <time.h>
// Enemy - Enemy a Hero fights
class Enemy:public Class {
public:
	// Constructor - int level
	Enemy(int lvl) {
		srand((unsigned)time(NULL));
		hp = (rand() % 5 + 1) * lvl + 5;
		srand((unsigned)time(NULL));
		atk = (rand() % 2 + 1) * .1 * lvl + 1;
		srand((unsigned)time(NULL));
		def = 1 - (rand() % 5 + 1) * .01 * lvl;
		srand((unsigned)time(NULL));
		mp = (rand() % 5 + 1) * lvl;
		this->lvl = lvl;
		if (lvl < 6) {
			move1 = Move("PSI Fire A", 2, 3);
		}
		name = "Enemy";
		cout << "A level " << lvl << " enemy appeared!" << endl;
		Pause();
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
	// Sets HP to a mod value
	void setHP(double mod) {
		hp += mod;
	}
	// Uses move based on slot #
	double useMove(Hero h) {
		SoundPlayer sound;
		srand((unsigned)time(NULL));
		int slot = rand() % 5;
		if (slot == 0) {
			cout << name << " hit " << h.getName() << "!";
			sound.playBash();
			return atk;
		}
		else if (slot == 1) {
			if (move1.getName() != "") {
				cout << name << " tried " << move1.getName() << "!";
				move1.playMoveSound();
				return move1.getPow() * atk;
			}
			else {
				cout << name << " panicked!";
				return 0;
			}
		}
		else if (slot == 2) {
			if (move2.getName() != "") {
				cout << name << " tried " << move2.getName() << "!";
				move2.playMoveSound();
				return move2.getPow() * atk;
			}
			else {
				cout << name << " panicked!" << endl;
				return 0;
			}
		}
		else if (slot == 3) {
			if (move3.getName() != "") {
				cout << name << " tried " << move3.getName() << "!";
				move3.playMoveSound();
				return move3.getPow() * atk;
			}
			else {
				cout << name << " panicked!" << endl;
				return 0;
			}
		}
		else if (slot == 4) {
			if (move4.getName() != "") {
				cout << name << " tried " << move4.getName() << "!";
				move4.playMoveSound();
				return move4.getPow() * atk;
			}
			else {
				cout << name << " panicked!" << endl;
				return 0;
			}
		}
		else { cout << name << " panicked!" << endl; return 0; }
	}
	// Returns XP based on level
	int getXP() {
		srand((unsigned)time(NULL));
		int num = (rand() % 25 + 1) * lvl * 2;
		return num;
	}
	// Stops execution for 3 seconds
	void Pause() {
		Sleep(3000);
		cout << endl;
	}
};