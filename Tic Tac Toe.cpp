#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;

void Initialize_Game(char**&);
void Display_Board(char**);
void Instructions();
bool Check_Board(char**, char);
bool Check_If_Filled(char**);
void Menu();
void Switch_Player(char&);
void Multiplayer(char**);
void SinglePlayer(char**);
char AIMove(char**);


int main()
{
	int choice = 0;	
	char** gameMatrix = NULL;
	while (choice != 3){
	Initialize_Game(gameMatrix);
	system("Color 0F");
	Menu();
	cin >> choice;
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	if (choice == 1)
	{
		cout << "\t\t\t\t\t       Player - 1 [X]  VS  Bot [O]\n\n";
		SinglePlayer(gameMatrix);
	}
	else if (choice == 2){
		cout << "\t\t\t\t\t    Player - 1 [X]  VS  Player - 2 [O]\n\n";
		Multiplayer(gameMatrix);
	}
	else if (choice == 3)
	{
		cout << "\t\t\t\t\t\t ---------------------\n";
		cout << "\t\t\t\t\t\t| Thanks for Playing! |\n";
		cout << "\t\t\t\t\t\t ---------------------\n";
		break;
	}
	else
		cout << "Wrong Choice!\n";
	}
	system("pause");
	return 0;
}

void Menu(){
	cout << "\n\t\t\t\t\t --------- Welcome to Tic-Tac-Toe --------- \n\n";
	cout << "\t\t\t\t Choose Mode: \n";
	cout << "\t\t\t\t 1. Single Player Mode (against Bot)\n";
	cout << "\t\t\t\t 2. Two Player Mode\n";
	cout << "\t\t\t\t 3. Exit Program\n\n ";
	cout << "\t\t\t\t Enter Choice: ";
}

void Initialize_Game(char**& mat)
{
	if (mat == nullptr)
	{
		mat = new char*[3];
		char j = '0';
		for (int i = 0; i < 3; i++){
			mat[i] = new char[3]{j, j + 1, j + 2};
			j += 3;
		}
	}
	else{
		char j = '0';
		for (int i = 0; i < 3; i++){
			mat[i][0] = j;
			mat[i][1] = j + 1;
			mat[i][2] = j + 2;
			j += 3;
		}
	}

}

void Display_Board(char** mat)
{
	int i = 0;
	cout << '\n';
	while(i != 3){
		cout << "\t\t\t\t\t\t\t " << mat[i][0] << " | " << mat[i][1] << " | " << mat[i][2] << "\n";
		if(i != 2)	
			cout << "\t\t\t\t\t\t\t-----------" << "\n";
		i++;
	}
	cout << '\n';
}

bool Check_Board(char** gameMatrix, char player)
{
	// Horizontal Check
	for (int i = 0; i < 3; i++){
		if (gameMatrix[i][0] == player && gameMatrix[i][1] == player && gameMatrix[i][2] == player)
			return true;
	}

	// Vertical Check
	for (int i = 0; i < 3; i++){
		if (gameMatrix[0][i] == player && gameMatrix[1][i] == player && gameMatrix[2][i] == player)
			return true;
	}

	// Diagonal Check
	if (gameMatrix[0][0] == player && gameMatrix[1][1] == player && gameMatrix[2][2] == player)
		return true;
	else if (gameMatrix[0][2] == player && gameMatrix[1][1] == player && gameMatrix[2][0] == player)
		return true;
	return false;
}

void Instructions()
{
	ifstream fin("How to Play.txt");
	string read = "";
	while (!fin.eof())
		read += fin.get(); 
	cout << read << "\n\n";
}

void Switch_Player(char& p)
{
	if (p == 'X')
		p = 'O';
	else
		p = 'X';
}

bool Check_If_Filled(char** mat)
{
	int i = 0;
	bool check = false;
	while (i != 3){
		if ((mat[i][0] != 'X' && mat[i][0] != 'O') || (mat[i][1] != 'X' && mat[i][1] != 'O') ||
			(mat[i][2] != 'X' && mat[i][2] != 'O')){
			check = false;
			break;
		}
		else
			check = true;
		i++;
	}
	return check;
}

void Multiplayer(char** gameMatrix)
{
	char player = 'X';
	bool keepTurn = true;
	string choice = "0";
	cout << "\n\t\t\t\t\t\t -- Player 1 [X] turn --\n";
	while (true){
		if (!keepTurn){
			Switch_Player(player);
			if (player == 'X')
				cout << "\n\t\t\t\t\t\t -- Player 1 [X] turn --\n";
			else
				cout << "\n\t\t\t\t\t\t -- Player 2 [O] turn --\n";
			//_getch();
		}
		else
			keepTurn = false;
		Display_Board(gameMatrix);
		cout << "\t\t\t\t Pick a Position (0-8): ";
		cin >> choice;
		if (choice.size() == 1){
			switch (choice[0])
			{
			case '0':
			{
						if (gameMatrix[0][0] != 'X' && gameMatrix[0][0] != 'O')
							gameMatrix[0][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '1':
			{
						if (gameMatrix[0][1] != 'X' && gameMatrix[0][1] != 'O')
							gameMatrix[0][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '2':
			{
						if (gameMatrix[0][2] != 'X' && gameMatrix[0][2] != 'O')
							gameMatrix[0][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '3':
			{
						if (gameMatrix[1][0] != 'X' && gameMatrix[1][0] != 'O')
							gameMatrix[1][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '4':
			{
						if (gameMatrix[1][1] != 'X' && gameMatrix[1][1] != 'O')
							gameMatrix[1][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '5':
			{
						if (gameMatrix[1][2] != 'X' && gameMatrix[1][2] != 'O')
							gameMatrix[1][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '6':
			{
						if (gameMatrix[2][0] != 'X' && gameMatrix[2][0] != 'O')
							gameMatrix[2][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '7':
			{
						if (gameMatrix[2][1] != 'X' && gameMatrix[2][1] != 'O')
							gameMatrix[2][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '8':
			{
						if (gameMatrix[2][2] != 'X' && gameMatrix[2][2] != 'O')
							gameMatrix[2][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			default:
			{
					   cout << "\t\t\t\t Wrong Choice!\n";
					   keepTurn = true;
					   break;
			}
			}

			if (Check_Board(gameMatrix, player)){
				Display_Board(gameMatrix);
				cout << "\t\t\t\t\t--------------------------------------\n";
				if (player == 'X')
					cout << "\t\t\t\t\t| Congratulations, Player 1 has won! | \n";
				else
					cout << "\t\t\t\t\t| Congratulations, Player 2 has won! | \n";
				cout
					<< "\t\t\t\t\t--------------------------------------\n";

				break;
			}

			if (Check_If_Filled(gameMatrix)){
				Display_Board(gameMatrix);
				cout << "\t\t\t\t\t\t       --------------\n";
				cout << "\t\t\t\t\t\t      | It's a Draw! |\n";
				cout << "\t\t\t\t\t\t       --------------\n";
				break;
			}
		}
		else{
			keepTurn = true;
			cout << "\t\t\t\t Invalid Choice!\n";
		}
	}
		cout << "\t\t\t\t\t\t Press a Key to Continue...\n";
		_getch();
		system("cls");
}

void SinglePlayer(char** gameMatrix)
{
	char player = 'X';
	bool keepTurn = true;
	string choice = "0";
	cout << "\n\t\t\t\t\t\t -- Player 1 [X] turn --\n";
	while (true){
		if (!keepTurn){
			Switch_Player(player);
			if (player == 'X')
				cout << "\n\t\t\t\t\t\t -- Player 1 [X] turn --\n";
			else
				cout << "\n\t\t\t\t\t\t   -- Bot [O] turn --\n";
			//_getch();
		}
		else
			keepTurn = false;
		Display_Board(gameMatrix);
		if (player == 'X'){
			cout << "\t\t\t\t Pick a Position (0-8): ";
			cin >> choice;
		}
		else
			choice = AIMove(gameMatrix);
		if (choice.size() == 1){
			switch (choice[0])
			{
			case '0':
			{
						if (gameMatrix[0][0] != 'X' && gameMatrix[0][0] != 'O')
							gameMatrix[0][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '1':
			{
						if (gameMatrix[0][1] != 'X' && gameMatrix[0][1] != 'O')
							gameMatrix[0][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '2':
			{
						if (gameMatrix[0][2] != 'X' && gameMatrix[0][2] != 'O')
							gameMatrix[0][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '3':
			{
						if (gameMatrix[1][0] != 'X' && gameMatrix[1][0] != 'O')
							gameMatrix[1][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '4':
			{
						if (gameMatrix[1][1] != 'X' && gameMatrix[1][1] != 'O')
							gameMatrix[1][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '5':
			{
						if (gameMatrix[1][2] != 'X' && gameMatrix[1][2] != 'O')
							gameMatrix[1][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '6':
			{
						if (gameMatrix[2][0] != 'X' && gameMatrix[2][0] != 'O')
							gameMatrix[2][0] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '7':
			{
						if (gameMatrix[2][1] != 'X' && gameMatrix[2][1] != 'O')
							gameMatrix[2][1] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			case '8':
			{
						if (gameMatrix[2][2] != 'X' && gameMatrix[2][2] != 'O')
							gameMatrix[2][2] = player;
						else{
							cout << "\t\t\t\t Spot is already filled! \n\n";
							keepTurn = true;
						}
						break;
			}
			default:
			{
					   keepTurn = true;
					   cout << "\t\t\t\t Wrong Choice!\n";
					   break;
			}
			}

			if (Check_Board(gameMatrix, player)){
				Display_Board(gameMatrix);
				cout << "\t\t\t\t\t ----------------------------------------\n";
				if (player == 'X')
					cout << "\t\t\t\t\t|    Congratulations, Player 1 has won!   | \n";
				else
					cout << "\t\t\t\t\t| Oopsie, you have just lost to a bot :) | \n";
				cout << "\t\t\t\t\t ----------------------------------------\n";

				break;
			}

			if (Check_If_Filled(gameMatrix)){
				Display_Board(gameMatrix);
				cout << "\t\t\t\t\t\t       --------------\n";
				cout << "\t\t\t\t\t\t      | It's a Draw! |\n";
				cout << "\t\t\t\t\t\t       --------------\n";
				break;
			}
		}
		else{
			keepTurn = true;
			cout << "\t\t\t\t Invalid Choice!\n";
		}
	}
	cout << "\t\t\t\t\t\t Press a Key to Continue...\n";
	_getch();
	system("cls");
}

char AIMove(char** board)
{
	// Checking if AI can make a winning Move

	// Play [0][0] -- return 0
	if (((board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[2][0] == 'O') ||
		(board[1][1] == 'O' && board[2][2] == 'O')) && board[0][0] == '0')
		return '0';

	// Play [0][1] -- return 1
	else if (((board[0][0] == 'O' && board[0][2] == 'O') || (board[1][1] == 'O' && board[2][1] == 'O')) && board[0][1] == '1')
		return '1';

	// Play [0][2] -- return 2
	else if (((board[0][0] == 'O' && board[0][1] == 'O') || (board[1][1] == 'O' && board[2][0] == 'O') ||
		(board[1][2] == 'O' && board[2][2] == 'O')) && board[0][2] == '2')
		return '2';

	// Play [1][0] -- return 3
	else if (((board[0][0] == 'O' && board[2][0] == 'O') || (board[1][1] == 'O' && board[1][2] == 'O')) && board[1][0] == '3')
		return '3';

	// Play [1][1] -- return 4
	else if (((board[0][0] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O'
		&& board[2][1] == 'O') || (board[1][0] == 'O' && board[1][2] == 'O')) && board[1][1] == '4')
		return '4';

	// Play [1][2] -- return 5
	else if (((board[0][2] == 'O' && board[2][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O')) && board[1][2] == '5')
		return '5';

	// Play [2][0] -- return 6
	else if (((board[1][1] == 'O' && board[0][2] == 'O') || (board[0][0] == 'O' && board[1][0] == 'O') ||
		(board[2][1] == 'O' && board[2][2] == 'O')) && board[2][0] == '6')
		return '6';

	// Play [2][1] -- return 7
	else if (((board[0][1] == 'O' && board[1][1] == 'O') || (board[2][0] == 'O' && board[2][2] == 'O')) && board[2][1] == '7')
		return '7';

	// Play [2][2] -- return 8
	else if (((board[0][0] == 'O' && board[1][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' &&
		board[2][1] == 'O')) && board[2][2] == '8')
		return '8';



	// Else if Checking the Bot can prevent the Player from winning

	// Play [0][0] -- return 0
	if (((board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[2][0] == 'X') ||
		(board[1][1] == 'X' && board[2][2] == 'X')) && board[0][0] == '0')
		return '0';

	// Play [0][1] -- return 1
	else if (((board[0][0] == 'X' && board[0][2] == 'X') || (board[1][1] == 'X' && board[2][1] == 'X')) && board[0][1] == '1')
		return '1';

	// Play [0][2] -- return 2
	else if (((board[0][0] == 'X' && board[0][1] == 'X') || (board[1][1] == 'X' && board[2][0] == 'X') ||
		(board[1][2] == 'X' && board[2][2] == 'X')) && board[0][2] == '2')
		return '2';

	// Play [1][0] -- return 3
	else if (((board[0][0] == 'X' && board[2][0] == 'X') || (board[1][1] == 'X' && board[1][2] == 'X')) && board[1][0] == '3')
		return '3';

	// Play [1][1] -- return 4
	else if (((board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X'
		&& board[2][1] == 'X') || (board[1][0] == 'X' && board[1][2] == 'X')) && board[1][1] == '4')
		return '4';

	// Play [1][2] -- return 5
	else if (((board[0][2] == 'X' && board[2][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X')) && board[1][2] == '5')
		return '5';

	// Play [2][0] -- return 6
	else if (((board[1][1] == 'X' && board[0][2] == 'X') || (board[0][0] == 'X' && board[1][0] == 'X') ||
		(board[2][1] == 'X' && board[2][2] == 'X')) && board[2][0] == '6')
		return '6';

	// Play [2][1] -- return 7
	else if (((board[0][1] == 'X' && board[1][1] == 'X') || (board[2][0] == 'X' && board[2][2] == 'X')) && board[2][1] == '7')
		return '7';

	// Play [2][2] -- return 8
	else if (((board[0][0] == 'X' && board[1][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' &&
		board[2][1] == 'X')) && board[2][2] == '8')
		return '8';

	// Else playing a random spot
	srand(time(NULL));
	int temp = (rand() % 9) + 1;
	switch (temp){
	case 0:{
		return '0';
		break;
	}
	case 1:{
			   return '1';
			   break;
	}
	case 2:{
			   return '2';
			   break;
	}
	case 3:{
			   return '3';
			   break;
	}
	case 4:{
			   return '4';
			   break;
	}
	case 5:{
			   return '5';
			   break;
	}
	case 6:{
			   return '6';
			   break;
	}	
	case 7:{
			   return '7';
			   break;
	}	
	case 8:{
		return '8';
		break;
	}
	}
}