
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>

using namespace std;

bool checkWin(char arr[3][3]);
void computerPlay(char arr[3][3]) {
	int move1 = rand() % 9;
	int row = (move1 - 1) / 3;
	int col = (move1 - 1) % 3;

	if (arr[row][col] != 'O' && arr[row][col]!='X') {
		arr[row][col] = 'O';
	}
	else
		computerPlay(arr);

}
int main() {
	srand(time(0));
	int row = 0;;
	int col = 0;;
	system("color 0f");

	// Front Desktop

	cout << "/< TIC TAC TOE >/" << endl << endl;

	cout << "\033[88m                              < Welcome To Tic Tac Toe Game Developed By (Hamza) >" << endl;

	cout << "                          --------------------------------------------------------------" << endl;
	cout << " \033[91m------" << endl;
	cout << "\033[91m |Rule| : " << endl;
	cout << " ------" << endl;
	cout << "\033[93m There Would be Two Players represented as (X / O) ..." << endl;
	cout << "--------------------------------------------------------" << endl << endl;

	// Selecting Game mode

	int chooseGame = 0;
	cout << "\nSelect 1 or 2:" << endl;
	cout << "1) Single Player " << endl;
	cout << "2) Multi Player   ";
	cin >> chooseGame;

	// Single Player

	if (chooseGame == 1) {
		cout << "\nLet's Start Play as Single_Player ...." << endl;


		char arr[3][3] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'} };

		for (int i = 0; i < 3; i++) {
			cout << endl;
			for (int j = 0; j < 3; j++) {
				cout << arr[i][j] << " | ";
			}
			cout << endl;
			cout << "---------";
		}


		char currentPlayer = 'X';
		int moves = 0;

		while (true) {
			if (currentPlayer == 'X') {
				int position;
				cout << "\033[95m\nPlayer " << currentPlayer << ", enter a position: ";
				cin >> position;

				int row = position / 3;
				int col = position % 3;
				if (arr[row][col] != 'X') {
					arr[row][col] = currentPlayer;
					moves++;
					system("cls");

					for (int i = 0; i < 3; i++) {
						cout << endl;
						for (int j = 0; j < 3; j++) {
							cout << arr[i][j] << " | ";
						}
						cout << endl;
						cout << "---------";
					}
					cout << endl << endl;

					if (checkWin(arr)) {
						cout << "\nPlayer " << currentPlayer << " wins!" << endl;
						break;
					}

					if (moves == 9) {
						cout << "\nIt's a draw!" << endl;
						break;
					}



					currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

				}
				else
					cout << "Invalid move. Please try again." << endl;


			}



			else if (currentPlayer == 'O')
			{
				{

					computerPlay(arr);
				}
				if (arr[row][col] != 'O') {

					moves++;
					system("cls");

					for (int i = 0; i < 3; i++) {
						cout << endl;
						for (int j = 0; j < 3; j++) {
							cout << arr[i][j] << " | ";
						}
						cout << endl;
						cout << "---------";
					}
					cout << endl << endl;

					if (checkWin(arr)) {
						cout << "\nPlayer Computer  " << currentPlayer << " wins!" << endl;
						break;
					}

					if (moves == 9) {
						cout << "\nIt's a draw!" << endl;
						break;
					}



					currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

				}
				else
					cout << "Invalid move. Please try again." << endl;


			}

		}
	}

	// Multi Player 

	else if (chooseGame == 2) {
		cout << "\nLet's Start Play as a Multi - Player ...." << endl;


		char arr[3][3] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'} };

		for (int i = 0; i < 3; i++) {
			cout << endl;
			for (int j = 0; j < 3; j++) {
				cout << arr[i][j] << " | ";
			}
			cout << endl;
			cout << "---------";
		}


		char currentPlayer = 'X';
		int moves = 0;

		while (true) {
			int position;
			cout << "\033[95m\nPlayer " << currentPlayer << ", enter a position: ";
			cin >> position;

			int row = position / 3;
			int col = position % 3;

			if (arr[row][col] != 'X' && arr[row][col] != 'O') {
				arr[row][col] = currentPlayer;
				moves++;
				system("cls");

				for (int i = 0; i < 3; i++) {
					cout << endl;
					for (int j = 0; j < 3; j++) {
						cout << arr[i][j] << " | ";
					}
					cout << endl;
					cout << "---------";
				}
				cout << endl << endl;

				if (checkWin(arr)) {
					cout << "\nPlayer " << currentPlayer << " wins!" << endl;
					break;
				}

				if (moves == 9) {
					cout << "\nIt's a draw!" << endl;
					break;
				}



				currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

			}
			else
				cout << "Invalid move. Please try again." << endl;

		}
	}
	else
	cout << "\nYou Entered Wrong Input...";

	return 0;
}

// Check win  

bool checkWin(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
			return true;
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
			return true;
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
		return true;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
		return true;
	}

	return false;
}

