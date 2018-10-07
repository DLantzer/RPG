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
	void battle(Hero& h, Enemy& e) {
		while (h.getHP() > 0 && e.getHP() > 0) {
			cout << "What do you wanna do?" << endl << endl
				<< "Enemy has " << e.getHP() << " HP" << endl << endl
				<< "HP: " << h.getHP() << endl
				<< "MP: " << h.getMP() << endl
				<< "XP: " << h.showXP() << endl
				<< ":: 0 :: Physical :: POW: " << h.getAtk() << endl;
			if (h.getMove(1) != "")
				cout << ":: 1 :: " << h.getMove(1) << " :: POW: " << h.move1.getPow() << " MP: " << h.move1.getMPUsed() << endl;
			if (h.getMove(2) != "")
				cout << ":: 2 :: " << h.getMove(2) << " :: POW: " << h.move2.getPow() << " MP: " << h.move2.getMPUsed() << endl;
			if (h.getMove(3) != "")
				cout << ":: 3 :: " << h.getMove(3) << " :: POW: " << h.move3.getPow() << " MP: " << h.move3.getMPUsed() << endl;
			if (h.getMove(4) != "")
				cout << ":: 4 :: " << h.getMove(4) << " :: POW: " << h.move4.getPow() << " MP: " << h.move4.getMPUsed() << endl;
			cout << " :: ";
			int move;
			cin >> move;
			double dmg;
			int mp;
			cout << endl;
			if (move == 0) { 
				h.useMove(0); dmg = h.getAtk(); mp = 0;}
			else if (move == 1) { 
				if (h.getMP() >= h.move1.getMPUsed() && h.move1.getName() != "") {
					h.useMove(1); h.move1.effect(); dmg = h.move1.getFinalPow() * h.getAtk(); mp = h.move1.getMPUsed();
				}
				else { dmg = 0; mp = 0; cout << h.getName() << " couldn't think straight!" << endl; }
			}
			else if (move == 2) {
				if (h.getMP() >= h.move2.getMPUsed() && h.move2.getName() != ""){
					h.useMove(2); h.move2.effect(); dmg = h.move2.getFinalPow() * h.getAtk(); mp = h.move2.getMPUsed();
				}
				else { dmg = 0; mp = 0; cout << h.getName() << " couldn't think straight!" << endl; }
			}
			else if (move == 3) {
				if (h.getMP() >= h.move3.getMPUsed() && h.move3.getName() != "") {
					h.useMove(3); h.move3.effect(); dmg = h.move3.getFinalPow() * h.getAtk(); mp = h.move3.getMPUsed();
				}
				else { dmg = 0; mp = 0; cout << h.getName() << " couldn't think straight!" << endl; }
			}
			else if (move == 4) {
				if (h.getMP() >= h.move4.getMPUsed() && h.move4.getName() != "") {
					h.useMove(4); h.move4.effect(); dmg = h.move4.getFinalPow() * h.getAtk(); mp = h.move4.getMPUsed();
				}
				else { dmg = 0; mp = 0; cout << h.getName() << " couldn't think straight!" << endl; }
			}
			else {
				dmg = 0; mp = 0; cout << h.getName() << " panicked!";}
			cout << h.getName() << " dealt " << dmg << " damage." << endl;
			Pause();
			e.setHP(-dmg);
			h.setMP(-mp);
			cout << e.getName() << " has " << e.getHP() << " health." << endl;
			Pause();
			if (e.getHP() <= 0) {
				cout << h.getName() << " defeated " << e.getName() << "!";
				Pause();
				h.reset();
				h.getXP(e.getXP());
				break;
			}
			double heroDmg = e.useMove(h);
			Pause();
			cout << endl << h.getName() << " took " << heroDmg << " damage." << endl;
			Pause();
			h.setHP(-heroDmg);
		}
	}
};