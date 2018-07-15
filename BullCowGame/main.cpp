#include <iostream>
#include <string>
#include <locale>
#include "FBullCowGame.h"

//Console executable that uses FBullCow class. Responsible for user interaction
//for game logic see the FBullCowGame
//
using FText = std::string; 
using int32 = int; 

void PrintIntro();
FText GetGuess();
void PlayGame();
void GetValidUserGuess();
void PlayAgain();
FBullCowGame Game;
bool BGameWon = false;
bool keepPlaying = Game.KeepPlaying(true);

//entry point
int main()
{ 
	do {
		PrintIntro();
		PlayGame();
	} while (keepPlaying);

	return 0;
	
}

void PrintIntro() {
	int32 LENGTH = Game.GetMaxTries(); 
	std::cout << "\nWelome To Hangman\n";
	std::cout << "Guess the " << LENGTH;
	std::cout << " letter isogram I'm thinking of \n";
}
FText GetGuess() {
	int32 CurrentTry = Game.GetCurrentTurn(); 
	std::cout << "\n\nTry " << CurrentTry << "-";
	std::cout << "Enter a guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}
void PlayGame()
{
	int32 MaxTry = Game.GetMaxTries();

	for (int32 i = 0; i < Game.GetMaxTries(); i++) {
			GetValidUserGuess();
			if (BGameWon) {
				std::cout << "YOU WON! ";
				break;
			}
	}
	PlayAgain();
}

void GetValidUserGuess()
{
		FText Guess = GetGuess();

		EGuessStatus Status = Game.isValidGuess(Guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters for a chance to win";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a word of correct length for a chance to win";
			break;
		case EGuessStatus::Ok:
			BullCowCount BullCowCount = Game.SubmitGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
			BGameWon = Game.isGameWon();
		}
}

void PlayAgain() {
	std::cout << "\nWould you like to play again? : ";
	FText Response = "";
	std::getline(std::cin, Response);
	//logic
	if (tolower(Response[0]) == 'y') {
		keepPlaying= Game.KeepPlaying(true);
		Game.Reset();
	}
	else {
		keepPlaying= Game.KeepPlaying(false);
	}
}



