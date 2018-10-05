#pragma once
#include <string>
using namespace std;
// SoundPlayer - Serves as a means of playing sound effects, music, .wav files etc.
class SoundPlayer {
public:
	void playIntro() {
		PlaySound(TEXT("Intro"), NULL, SND_SYNC);
	}
	void playBash() {
		PlaySound(TEXT("bash"), NULL, SND_SYNC);
	}
	void playBrainshockA() {
		PlaySound(TEXT("PSI Brainshock a"), NULL, SND_SYNC);
	}
	void playBrainshockO() {
		PlaySound(TEXT("PSI Brainshock O"), NULL, SND_SYNC);
	}
	void playDefenseA() {
		PlaySound(TEXT("PSI Defense a"), NULL, SND_SYNC);
	}
	void playDefenseO() {
		PlaySound(TEXT("PSI Defense O"), NULL, SND_SYNC);
	}
	void playFireA() {
		PlaySound(TEXT("PSI Fire a"), NULL, SND_SYNC);
	}
	void playFireB() {
		PlaySound(TEXT("PSI Fire B"), NULL, SND_SYNC);
	}
	void playFireE() {
		PlaySound(TEXT("PSI Fire e"), NULL, SND_SYNC);
	}
	void playFireO() {
		PlaySound(TEXT("PSI Fire O"), NULL, SND_SYNC);
	}
	void playFlashA() {
		PlaySound(TEXT("PSI Flash a"), NULL, SND_SYNC);
	}
	void playFlashB() {
		PlaySound(TEXT("PSI Flash B"), NULL, SND_SYNC);
	}
	void playFlashE() {
		PlaySound(TEXT("PSI Flash e"), NULL, SND_SYNC);
	}
	void playFlashO() {
		PlaySound(TEXT("PSI Flash O"), NULL, SND_SYNC);
	}
	void playFreezeA() {
		PlaySound(TEXT("PSI Freeze a"), NULL, SND_SYNC);
	}
	void playFreezeB() {
		PlaySound(TEXT("PSI Freeze B"), NULL, SND_SYNC);
	}
	void playFreezeE() {
		PlaySound(TEXT("PSI Freeze e"), NULL, SND_SYNC);
	}
	void playFreezeO() {
		PlaySound(TEXT("PSI Freeze O"), NULL, SND_SYNC);
	}
	void playHypnosisA() {
		PlaySound(TEXT("PSI Hypnosis a"), NULL, SND_SYNC);
	}
	void playHypnosisO() {
		PlaySound(TEXT("PSI Hypnosis O"), NULL, SND_SYNC);
	}
	void playMagnetA() {
		PlaySound(TEXT("PSI Magnet a"), NULL, SND_SYNC);
	}
	void playMagnetO() {
		PlaySound(TEXT("PSI Magnet O"), NULL, SND_SYNC);
	}
	void playParalysisA() {
		PlaySound(TEXT("PSI Paralysis a"), NULL, SND_SYNC);
	}
	void playParalysisO() {
		PlaySound(TEXT("PSI Paralysis O"), NULL, SND_SYNC);
	}
	void playRockinA() {
		PlaySound(TEXT("PSI Rockin a"), NULL, SND_SYNC);
	}
	void playRockinB() {
		PlaySound(TEXT("PSI Rockin B"), NULL, SND_SYNC);
	}
	void playRockinE() {
		PlaySound(TEXT("PSI Rockin e"), NULL, SND_SYNC);
	}
	void playRockinO() {
		PlaySound(TEXT("PSI Rockin O"), NULL, SND_SYNC);
	}
	void playShieldA() {
		PlaySound(TEXT("PSI Shield a"), NULL, SND_SYNC);
	}
	void playShieldB() {
		PlaySound(TEXT("PSI Shield B"), NULL, SND_SYNC);
	}
	void playShieldKiller() {
		PlaySound(TEXT("PSI Shield Killer"), NULL, SND_SYNC);
	}
	void playStarstormA() {
		PlaySound(TEXT("PSI Starstorm a"), NULL, SND_SYNC);
	}
	void playStarstormB() {
		PlaySound(TEXT("PSI Starstorm B"), NULL, SND_SYNC);
	}
	void playStarstormE() {
		PlaySound(TEXT("PSI Starstorm e"), NULL, SND_SYNC);
	}
	void playStarstormO() {
		PlaySound(TEXT("PSI Starstorm O"), NULL, SND_SYNC);
	}
	void playThunderA() {
		PlaySound(TEXT("PSI Thunder a b"), NULL, SND_SYNC);
	}
	void playThunderB() {
		PlaySound(TEXT("PSI Thunder a b"), NULL, SND_SYNC);
	}
	void playThunderE() {
		PlaySound(TEXT("PSI Thunder e O"), NULL, SND_SYNC);
	}
	void playThunderO() {
		PlaySound(TEXT("PSI Thunder e O"), NULL, SND_SYNC);
	}
};
