#pragma once
#include <string>
#include "Class.h"
#include "Move.h"
#include "SoundPlayer.h"
// Hero - NPC/PC that fights an Enemy
class Hero:public Class{
private:
	int experience;
public:
	// Constructor - Class, Name
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
			move1 = Move("PSI Fire A", 3, 3);
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
	void setHP(int mod) {
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
	double useMove(int slot) {
		SoundPlayer sound;
		if (slot == 0) {
			cout << name << " hit the enemy!" << endl;
			sound.playBash();
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
};