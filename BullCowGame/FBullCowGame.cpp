#include "FBullCowGame.h";
#include <map>

#define Tmap std::map

using int32 = int;
//Just a comment

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	keepPlaying = true;
	gameWon = false;
	CurrentTry = 1;
	HiddenWord = "ant";
	MaxTry = GetHiddenWordLength();
	
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTry;
}

int32 FBullCowGame::GetCurrentTurn() const
{
	return CurrentTry;
}

int32 FBullCowGame::GetTurnsLeft() const
{
	return MaxTry - CurrentTry;
}

bool FBullCowGame::isGameWon()
{
	return gameWon;
	

}

//recieve valid guess increment turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	BullCowCount BullCowCount;
		CurrentTry++;
		//loop letters ing guess
		for (int32 i = 0; i < MaxTry; i++) {
			//check for bulls
			if (Guess[i] == HiddenWord[i]) {
				BullCowCount.Bulls++;
			}
			else {
				//check for cows
				for (int32 j = 0; j < MaxTry; j++) {
					if (Guess[i] == HiddenWord[j]) {
						BullCowCount.Cows++;
					}
				}
			}
		}
		if (BullCowCount.Bulls == GetHiddenWordLength()) {
			gameWon = true;
		}
		else {
			gameWon = false;
		}
	return BullCowCount;
}

//asdsa
EGuessStatus FBullCowGame::isValidGuess(FString Guess) const
{
	//check if correct length
	if (HiddenWord.length() != Guess.length())
	{
		return EGuessStatus::Wrong_Length; 
	}
	else 
	{
		//check if isogram
		Tmap<char, bool> LetterSeen; 
		for (auto Letter : Guess) {
			Letter = tolower(Letter);
			if (LetterSeen[Letter]) {
				return EGuessStatus::Not_Isogram;
			}
			else {
				LetterSeen[Letter] = true;
			}
		}
		//After loop checks if isogram return ok
		return EGuessStatus::Ok;
	}
}

bool FBullCowGame::KeepPlaying(bool game)
{
	keepPlaying = game;
	return keepPlaying;
}

int32 FBullCowGame::GetHiddenWordLength()
{
	return HiddenWord.length();
}




