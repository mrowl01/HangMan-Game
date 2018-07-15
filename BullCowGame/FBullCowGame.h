#pragma once
#include <string>
#include <iostream>

using FString = std::string; 
using int32 = int; 

enum class EGuessStatus {
	Not_Isogram,
	Wrong_Length,
	Ok
};


struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public: 
	FBullCowGame();
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTurn() const;
	int32 GetTurnsLeft() const;
	bool isGameWon() ;
	BullCowCount SubmitGuess(FString);
	EGuessStatus isValidGuess(FString) const;
	bool KeepPlaying(bool);
	int32 GetHiddenWordLength();
private : 
	int32 CurrentTry;
	int32 MaxTry;
	FString HiddenWord; 
	bool gameWon;
	bool keepPlaying;

};