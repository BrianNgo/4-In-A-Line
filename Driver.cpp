#include "FourInLine.hpp"

int main(int argc, char** argv) {
    int choice = 0, depth = 5, thinkTime = 0;
    std::cout << "*** WELCOME TO FOUR IN LINE ***\n";
    std::cout << "1. Player starts first\n";
    std::cout << "2. Computer starts first\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "How long should the computer allow to think? ";
    std::cin >> thinkTime;

    FourInLine game(thinkTime, depth);
    int currentTurn = 0;
    std::string inputMove= "";
    if (choice == 1)
	std::cout << game.currentStateOfTheBoard();
    else
	currentTurn = 1;

    int resultOfTheGame = game.checkForWinner();
    while (resultOfTheGame != 1 && resultOfTheGame != 5000 
	   && resultOfTheGame != -5000) {
	if (currentTurn == 0) {
	    std::cout << "Your move is: ";
	    std::cin.clear();
	    std::cin >> inputMove;
	    while (!game.playerMove(inputMove)) {
		std::cout << "Your move is: ";
		std::cin.clear();
		std::cin >> inputMove;
	    }
	    currentTurn = 1;
	} else {
	    game.computerMove();
	    currentTurn = 0;
	}
	std::cout << game.currentStateOfTheBoard();
	resultOfTheGame = game.checkForWinner();
    }
    if (resultOfTheGame == -5000)
	std::cout << "\nYou Win!!\n";
    else if (resultOfTheGame == 5000)
	std::cout << "\nYou Lose!!\n";
    else if (resultOfTheGame == 1)
	std::cout << "\nDraw Game!!\n";
    std::cout << "Thanks for playing!!!\n";

    return 0;
}
