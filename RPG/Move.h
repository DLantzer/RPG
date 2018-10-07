#pragma once
#include "SoundPlayer.h"
#include "Hero.h"
#include <time.h>
// Move - An attack/support an Enemy or Hero can use
class Move{
private:
	string className, moveName; // Move name
	int pow, mpUsed, tempPow; // Move power, Move MP value, temporary power boost
public:
	// Default Constructor
	Move() 
	{
		moveName = "";
		pow = 0;
		mpUsed = 0;
		tempPow = 0;
	}
	// Constructor
	Move(string n, int p, int m) 
	{
		moveName = n;
		pow = p;
		mpUsed = m;
		tempPow = 0;
	}
	// Plays sound specific to move based on moveName
	void playMoveSound() {
		SoundPlayer SoundManager;
		if (moveName == "PSI Brainshock A") { SoundManager.playBrainshockA(); }
		else if (moveName == "PSI Brainshock O") { SoundManager.playBrainshockO(); }
		else if (moveName == "PSI Defense A") { SoundManager.playDefenseA(); }
		else if (moveName == "PSI Defense O") { SoundManager.playDefenseO(); }
		else if (moveName == "PSI Fire A") { SoundManager.playFireA(); }
		else if (moveName == "PSI Fire B") { SoundManager.playFireB(); }
		else if (moveName == "PSI Fire E") { SoundManager.playFireE(); }
		else if (moveName == "PSI Fire O") { SoundManager.playFireO(); }
		else if (moveName == "PSI Flash A") { SoundManager.playFlashA(); }
		else if (moveName == "PSI Flash B") { SoundManager.playFlashB(); }
		else if (moveName == "PSI Flash E") { SoundManager.playFlashE(); }
		else if (moveName == "PSI Flash O") { SoundManager.playFlashO(); }
		else if (moveName == "PSI Freeze A") { SoundManager.playFreezeA(); }
		else if (moveName == "PSI Freeze B") { SoundManager.playFreezeB(); }
		else if (moveName == "PSI Freeze E") { SoundManager.playFreezeE(); }
		else if (moveName == "PSI Freeze O") { SoundManager.playFreezeO(); }
		else if (moveName == "PSI Hypnosis A") { SoundManager.playHypnosisA(); }
		else if (moveName == "PSI Hypnosis O") { SoundManager.playHypnosisO(); }
		else if (moveName == "PSI Magnet A") { SoundManager.playMagnetA(); }
		else if (moveName == "PSI Magnet O") { SoundManager.playMagnetO(); }
		else if (moveName == "PSI Paralysis A") { SoundManager.playParalysisA(); }
		else if (moveName == "PSI Paralysis O") { SoundManager.playParalysisO(); }
		else if (moveName == "PSI Rockin A") { SoundManager.playRockinA(); }
		else if (moveName == "PSI Lifeup A") { SoundManager.playLifeupA(); }
		else if (moveName == "PSI Lifeup B") { SoundManager.playLifeupB(); }
		else if (moveName == "PSI Rockin B") { SoundManager.playRockinB(); }
		else if (moveName == "PSI Rockin E") { SoundManager.playRockinE(); }
		else if (moveName == "PSI Rockin O") { SoundManager.playRockinO(); }
		else if (moveName == "PSI Shield A") { SoundManager.playShieldA(); }
		else if (moveName == "PSI Shield B") { SoundManager.playShieldB(); }
		else if (moveName == "PSI ShieldKiller") { SoundManager.playShieldKiller(); }
		else if (moveName == "PSI Starstorm B") { SoundManager.playStarstormA(); }
		else if (moveName == "PSI Starstorm O") { SoundManager.playStarstormO(); }
		else if (moveName == "PSI Thunder A") { SoundManager.playThunderA(); }
		else if (moveName == "PSI Thunder B") { SoundManager.playThunderA(); }
		else if (moveName == "PSI Thunder E") { SoundManager.playThunderE(); }
		else if (moveName == "PSI Thunder O") { SoundManager.playThunderE(); }
		else { cout << "Invalid name"; }
	}
	// Causes move effect
	void effect() {
		tempPow = 0;
		srand((unsigned)time(NULL));
		if (moveName == "PSI Fire A" || moveName == "PSI Fire B") {
			int chance = rand() % 2;
			if (chance == 1) {
				cout << "Ouch! That's hot!";
				Pause();
				tempPow = 2;
			}
		}
	}
	// Returns move name
	string getName() 
	{
		return moveName;
	}
	// Returns move power
	int getPow() { 
		return pow
; 
	}
	// Returns move power + tempPow
	int getFinalPow() {
		return pow + tempPow;
	}
	// Returns move MP value
	int getMPUsed() {
		return mpUsed;
	}
	// Stops execution for 3 seconds
	void Pause() {
		Sleep(3000);
		cout << endl;
	}
};