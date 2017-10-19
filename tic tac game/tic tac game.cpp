// Created by: Krishna Varadarajan 
// A simple tic-tac game in C++ using 2D arrays, and conditional statements 
// Takes input from user, and declares the winner if same character is found in the whole row, column or a diagonal 
// Idea inspired by a coding challenge on the Udacity course: "C++ for Programmers" 
// Link to the course: <<https://classroom.udacity.com/courses/ud210>> 

//import the necessary header files
#include "stdafx.h"		// rewmove this line if not running on Visual Studio
#include<iostream>
#include<string>

using namespace std;

char gameBoard[4][4];	// declare a gameBoard of 4x4 matrix which can store characters
string nameX, nameO;	// to store the name of the players
int xInput, yInput;		// to store the matrix indices specified by the user
int rounds = 0;			// to store the number of rounds completed in the game
int trigger = 0;		// to check if a player has won

int main() {

	cout << "Enter your name; you are the 'X' user" << endl;
	getline(cin, nameX);
	cout << "Enter your name; you are the 'O' user" << endl;
	getline(cin, nameO);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gameBoard[i][j] = '-';
		}
	}

	/* initiate a while loop which runs for 8 rounds. Sequence of steps performed are:
	1. ask the user X for the position in the matrix he/she wants the character X to be placed
	2. ask the user O for the position in the matrix he/she wants the character O to be placed
	3. check if any row, column or diagonal has all Xs or Os. If so, break out of the while loop after declaring the winner.
	4. If no winner is found after 16 attemps or 8 rounds, declare the game as a tie and end the program
	*/

	while (rounds<8) {

		++rounds;

	tryAgainX:
		cout << nameX << ":: select a position on the 4x4 grid in the form <i j> to place an X on ith row, jth column" << endl;
		cin >> xInput >> yInput;
		if (xInput < 0 || yInput < 0 || xInput>3 || yInput>3) {
			cout << "Values of xInput, and yInput have to be either 0,1,2 or 3. Try again!" << endl;
			goto tryAgainX;

		}

		if (gameBoard[xInput][yInput] == 'X' || gameBoard[xInput][yInput] == 'O') {
			cout << "The position has already been filled, you cannot overwrite. Try again!" << endl;
			goto tryAgainX;

		}

		if (xInput / 10 != 0) {
			goto tryAgainX;
		}

		gameBoard[xInput][yInput] = 'X';

	tryAgainY:
		cout << nameO << ":: select a position on the 4x4 grid in the form <i j> to place an O on ith row, jth column" << endl;
		cin >> xInput >> yInput;
		if (xInput < 0 || yInput < 0 || xInput>3 || yInput>3) {
			cout << "Values of xInput, and yInput have to be either 0,1,2 or 3. Try again!" << endl;
			goto tryAgainY;

		}
		if (gameBoard[xInput][yInput] == 'X' || gameBoard[xInput][yInput] == 'O') {
			cout << "The position has already been filled, you cannot overwrite. Try again!" << endl;
			goto tryAgainY;

		}

		if (xInput / 10 != 0) {
			goto tryAgainY;
		}

		gameBoard[xInput][yInput] = 'O';

		if (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X' && gameBoard[3][3] == 'X') {
			cout << nameX << " is the winner" << endl;
			break;
		}

		if (gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O' && gameBoard[3][3] == 'O' && gameBoard[0][0] == 'O') {
			cout << nameO << " is the winner" << endl;
			break;
		}

		for (int i = 0; i<4; i++) {
			if (gameBoard[i][1] == 'X' && gameBoard[i][2] == 'X' && gameBoard[i][3] == 'X' && gameBoard[i][0] == 'X') {
				cout << nameX << " is the winner" << endl;
				trigger = 1;
				break;
			}

			if (gameBoard[i][1] == 'O' && gameBoard[i][2] == 'O' && gameBoard[i][3] == 'O' && gameBoard[i][0] == 'O') {
				cout << nameO << " is the winner" << endl;
				trigger = 1;
				break;
			}

		}

		for (int i = 0; i<4; i++) {
			if (gameBoard[1][i] == 'X' && gameBoard[2][i] == 'X' && gameBoard[3][i] == 'X' && gameBoard[0][i] == 'X') {
				cout << nameX << " is the winner" << endl;
				trigger = 1;
				break;
			}

			if (gameBoard[1][i] == 'O' && gameBoard[2][i] == 'O' && gameBoard[3][i] == 'O' && gameBoard[0][i] == 'O') {
				cout << nameO << "is the winner" << endl;
				trigger = 1;
				break;
			}

		}


		if (trigger == 1) {
			break;
		}


	}

	if (trigger == 0)
		cout << "The game is tied" << endl;

	return 0;
}



