//Name: Brendan Burdick
//Date: October 11, 2016
//Exam 1 (Midterm)
//
//Purpose of Program:
//The purpose of this program is to generate a tic tac toe game. 2 players will play in this game.
//The turn cycles back and forth until somebody wins. Each turn is checked by my personal function
//called 'checkForWinner', where it traverses the 2D array looking for any potential winning combination.
//If one is detected, the game stops and a winner is announced.
//
//At the end of the game, the system will ask if the players would like to play again. If 'y' or 'Y' is
//typed, then another game will start. If 'n' or 'N' is typed, the system will thank the players and exit.
//If any other input is put into the system at that time, the games will end.

#include <iostream>

using namespace std;
void showTable(char arr[][3]); //Function prototype for showTable.
void resetTable(char arr[][3]); //Function prototype for resetTable.
void checkForWinner(char arr[][3], int &wFlag); //Function prototype for checkForWinner.

int main()
{
	int turn = 1;
	char userChoice;
	char playAgain = 'y';
	char ticTacBoard[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int winnerFlag = 0; //Flag to tell if a winner has been found yet.
	
	while (playAgain == 'y' || playAgain == 'Y')
	{
		turn = 1; // Resets turn to 1 at the start of each new game.
		
		while (turn != 10 && winnerFlag == 0) //There are 9 total turns in each tic tac toe game. This will loop until a winner is found or the tenth turn happens.
		{
			showTable(ticTacBoard); //Prints current board.
			if (turn%2==1) //Determines if it's player one's turn.
			{
				cout<< "Player No. 1 Turn: "<< endl;
				cin >> userChoice; //Takes in player's choice for an X.
			
				for (int i = 0 ; i < 3 ; i++) //Traverses 2D array, and if the requested spot is found it's replaced with an X.
					for (int j = 0 ; j < 3 ; j++)
					{
						if (userChoice == ticTacBoard[i][j])
							ticTacBoard[i][j] = 'X';
					}
				turn++;
			}
		
			else //If it's not player one's turn, it's player two's turn.
			{
				cout<< "Player No. 2 Turn: "<< endl;
				cin >> userChoice; //Takes in player's choice for an O.
			
				for (int i = 0 ; i < 3 ; i++) //Traverses 2D array, and if the requested spot is found it's replaced with an O.
					for (int j = 0 ; j < 3 ; j++)
					{
						if (userChoice == ticTacBoard[i][j])
							ticTacBoard[i][j] = 'O';
					}
					
				turn++;
			}
			
			checkForWinner(ticTacBoard, winnerFlag); //At the end of each turn, there is a check to see if a winner is found.
			cout << "\n" << endl;
		}
		
		if (winnerFlag == 0)
		{
			showTable(ticTacBoard); //One last time for last turn.
			cout << "No one has won." << endl;
		}
		
		cout << "\n";
		resetTable(ticTacBoard); //Resets table at the end of the game.
		winnerFlag = 0; //Winner Flag Resets.
		
		cout << "\nWould you like to play again? ('Y' for yes. 'N' for no.)\n"; //Prompts user to play again.
		cin >> playAgain;
		
		cout << "\n";
	}
	
	if (playAgain == 'n' || playAgain == 'N')
		cout << "Thanks for playing!" << endl; //Thanks user for playing if they stop.
}

/*
 * This function traverses a 2D array, which is inputted, and outputs each cell's value.
 * Since this is set up to be a tic tac toe game, a 2D array will be loaded into this
 * function after every turn. Then, it will display the current layout of the board.
 * */
void showTable(char arr[][3])
{
	for (int i = 0 ; i < 3 ; i++)
	{
		for (int j = 0 ; j < 1 ; j++)
			cout << "| " << arr[i][j] << " | " << arr[i][j+1] << " | " << arr[i][j+2] << " |" << endl;
	}
}

/*
 * This function takes a 2D array as an argument, and resets the 2D array to be the
 * original layout of the tic tac toe board.
 * */
void resetTable(char arr[][3])
{
	arr[0][0] = '1';
	arr[0][1] = '2';
	arr[0][2] = '3';
	arr[1][0] = '4';
	arr[1][1] = '5';
	arr[1][2] = '6';
	arr[2][0] = '7';
	arr[2][1] = '8';
	arr[2][2] = '9';
}

/*
 * This function painstakingly checks all possible combinations that can result in
 * a player winning. If one has been found, then the winning character is checked
 * to see which player has won the game. Once a player has one, it is announced
 * and the winnerFlag will be updated so the corresponding game ends.
 * */
void checkForWinner(char arr[][3], int &wFlag)
{
	if (arr[0][0]==arr[0][1] && arr[0][0]==arr[0][2]) //row 1
	{
		if (arr[0][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[1][0]==arr[1][1] && arr[1][0]==arr[1][2]) //row 2
	{
		if (arr[1][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[2][0]==arr[2][1] && arr[2][0]==arr[2][2]) //row 3
	{
		if (arr[2][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[0][0]==arr[1][0] && arr[0][0]==arr[2][0]) //col 1
	{
		if (arr[0][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[0][1]==arr[1][1] && arr[0][1]==arr[2][1]) //col 2
	{
		if (arr[0][1] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[0][2]==arr[1][2] && arr[0][2]==arr[2][2]) //col 3
	{
		if (arr[0][2] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2]) //cross 1
	{
		if (arr[0][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
	
	else if (arr[2][0]==arr[1][1] && arr[2][0]==arr[0][2]) //cross 2
	{
		if (arr[2][0] == 'X')
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer one wins!";
		}
		else
		{
			cout<<"\n";
			showTable(arr);
			cout<<"\nPlayer two wins!";
		}
			
		wFlag = 1;
	}
}
