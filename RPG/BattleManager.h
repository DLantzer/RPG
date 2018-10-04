#pragma once
#include "Class.h"
#include "Hero.h"
#include "Enemy.h"
class BattleManager:public Class {
public:
	void Pause() {
		Sleep(3000);
		cout << endl;
	}
	void battle(Hero h, Enemy e) {
		while (h.getHP() > 0 && e.getHP() > 0) {
			cout << "What do you wanna do?" << endl
				<< "Enemy has " << e.getHP() << " HP" << endl
				<< "MP: " << h.getMP() << endl
				<< ":: 0 :: Physical" << endl
				<< ":: 1 :: " << h.getMove(1) << endl
				<< ":: 2 :: " << h.getMove(2) << endl
				<< ":: 3 :: " << h.getMove(3) << endl
				<< ":: 4 :: " << h.getMove(4) << endl 
				<< " :: ";
			int move;
			cin >> move;
			double dmg;
			int mp;
			if (move == 0) { 
				h.usePhysical(); dmg = h.getAtk(); mp = 0; cout << h.getName() << " hit the enemy!"; }
			else if (move == 1) { 
				h.useMove(1); dmg = h.move1.getPow() * h.getAtk(); mp = h.move1.getMPUsed();}
			else if (move == 2) { 
				h.useMove(2); dmg = h.move2.getPow() * h.getAtk(); mp = h.move2.getMPUsed();}
			else if (move == 3) { 
				h.useMove(3); dmg = h.move3.getPow() * h.getAtk(); mp = h.move3.getMPUsed();}
			else if (move == 4) { 
				h.useMove(4); dmg = h.move4.getPow() * h.getAtk(); mp = h.move4.getMPUsed();}
			else {
				dmg = 0; mp = 0; cout << h.getName() << " panicked!";}
			cout << h.getName() << " dealt " << dmg << " damage.";
			Pause();
			e.setHP(-dmg);
			h.setMP(-mp);
			cout << e.getName() << " has " << e.getHP() << " health." << endl;
			Pause();
			if (e.getHP() <= 0) {
				cout << h.getName() << " defeated " << e.getName() << "!";
				Pause();
				break;
			}
			double heroDmg = e.useMove(h);
			Pause();
			cout << h.getName() << " took " << heroDmg << " damage.";
			Pause();
		}
	}
};