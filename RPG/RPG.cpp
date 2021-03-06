#include "pch.h"
#include <iostream>
#include <string>
#include "Windows.h"
#include "MMSystem.h"
#include "SoundPlayer.h"
#include "Hero.h"
#include "Class.h"
#include "Move.h"
#include "Enemy.h"
#include "BattleManager.h"
void Pause();
using namespace std;
int main()
{
	cout << "View intro? (Y/N) :: ";
	string reply;
	SoundPlayer SoundManager;
	BattleManager battleManager;
	while (true) 
	{
		cin >> reply;
		if (reply == "Y" || reply == "y") 
		{
			cout << "The world is under attack by evil monsters!" << endl;
			cout << "It is your job to purge the world of this evil!" << endl;
			cout << "This war is not your own to fight. People will come to your aid during your journey." << endl;
			cout << "Go, brave Hero! It's up to you to stop the Corruption!" << endl;
			SoundManager.playIntro();
			break;
		}
		else if (reply == "N" || reply == "n") 
		{
			break;
		}
		else 
			cout << "What? ";
	}
	cout << endl << "What's your name anyways, Hero? :: ";
	string n;
	cin >> n;
	cout << endl << "Hello, " << n << "!" << endl << endl;
	cout << "[1] Warrior\n"
		<< "[2] Mage\n"
		<< "[3] Cleric\n"
		<< " :: ";
	int c;
	while (true)
	{
		cin >> c;
		if (c > 0 && c < 4)
		{
			break;
		}
		else cout << "What? ";
	}
	Hero hero1(c,n);
	cout << endl << hero1.getName() << " realized they were meant to be a " << hero1.getClass() << "!" << endl;
	Pause();
	cout << hero1.getName() << " realized " << hero1.getMove(1) << "!";
	Pause();
	hero1.viewStats();
	Pause();
	Enemy enemy(1);
	battleManager.battle(hero1, enemy);
	enemy = Enemy(2);
	battleManager.battle(hero1, enemy);
	enemy = Enemy(3);
	battleManager.battle(hero1, enemy);
};
void Pause() {
	Sleep(3000);
	cout << endl;
}