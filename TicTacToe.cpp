#include<iostream>

#include<conio.h>

using namespace std; 



class ticTacToe

{

	bool shouldExit, matrixEmpty, runNext;

	public:

	int matrix[3][3];

	ticTacToe();

	bool checkWinner();

	void manageGameFlow();

	void moveX();

	void moveO();

	void displayMatrix();

	void endGame();

	void CPUTurn();

	bool updateVal(int);

	void decidePosition();

	bool occupyCorners();

	bool checkAdjecency();

	void smartInsert();

};



ticTacToe :: ticTacToe()

{

	shouldExit = false;

	matrixEmpty = true;

	runNext = true;

	for(int i=0; i<3; i++)

	{

		for(int j=0; j<3; j++)

		{

			matrix[i][j] = -1;

		}

	}

}



void ticTacToe :: manageGameFlow()

{

	int choice;

	cout<<"\n---------------------------*******TIC-TAC-TOE*******----------------------------\n\n";

	cout<<"1. Vs. Player\n2. Vs. CPU\n";

	cin>>choice;

	if(choice == 1)

	{

		for(int i=0; i<9; i++)

		{

			if(i%2 == 0)

			{

				moveX();

				shouldExit = checkWinner();

			}

			else

			{

				moveO();

				shouldExit = checkWinner();

			}

			if(shouldExit)

			{

				endGame();

				break;

			}	

		}

		if(!shouldExit)

		{	

			displayMatrix();

			cout<<"\t\t\t\tDRAW! -_- ";

		}

	}

	else if(choice == 2)

	{

		for(int i=0; i<9; i++)

		{

			if(i%2 == 0)

			{

				CPUTurn();

				shouldExit = checkWinner();

			}

			else

			{

				moveO();

				shouldExit = checkWinner();

			}

			if(shouldExit)

			{

				endGame();

				break;

			}	

		}

		if(!shouldExit)

		{	

			displayMatrix();

			cout<<"\t\t\t\t\tDRAW! -_- ";

		}

	}

}



void ticTacToe :: moveX()

{

	int row,col;

	bool repeat = false;

	cout<<"\n--------------------------------PLAYER 1's TURN---------------------------------\n";

	displayMatrix();

	do

	{

		cout<<"Enter the position where you want to mark X (row,column): \n";

		cout<<"Row: ";

		cin>>row;

		row--;

		cout<<"Column: ";

		cin>>col;

		col--;

	

		if(matrix[row][col] == -1)

		{

			matrix[row][col] = 1;

			repeat = false;

		}

		else

		{

			cout<<"Position already occupied! Try again: \n";

			repeat = true;

		}

	}while(repeat == true);	

}



void ticTacToe :: moveO()

{

	int row,col;

	bool repeat = false;

	cout<<"\n--------------------------------PLAYER 2's TURN---------------------------------\n";

	displayMatrix();

	do

	{

		cout<<"Enter the position where you want to mark O (row,column): \n";

		cout<<"Row: ";

		cin>>row;

		row--;

		cout<<"Column: ";

		cin>>col;

		col--;

	

		if(matrix[row][col] == -1)

		{

			matrix[row][col] = 2;

			repeat = false;

		}

		else

		{

			repeat = true;

			cout<<"Position already occupied! Try again:\n";

		}

	}while(repeat == true);

}



void ticTacToe :: displayMatrix()

{

	cout<<"\t\t\t\t  | | \n";

	for(int i=0; i<3; i++)

	{

		cout<<"\t\t\t\t ";

		for(int j=0; j<3; j++)

		{

			if(matrix[i][j] == -1)

				cout<<" ";

			else

			{

				if(matrix[i][j] == 1)

					cout<<"X";

				else

					cout<<"O";

			}

			if(j != 2)

				cout<<"|";

			if(j == 2)

				cout<<"\n";

		}

		if(i != 2)

			cout<<"\t\t\t\t-------\n";

	}

	cout<<"\t\t\t\t  | | \n";

}



bool ticTacToe :: checkWinner()

{

	for(int i=0; i<3; i++)  //check row-wise

		if( matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] && matrix[i][1]==matrix[i][2] && matrix[i][0]!=-1)

		{	

			displayMatrix();

			cout<<"Player "<<matrix[i][0]<<" Wins!!!!!!!";

			return true;

		}	

	for(int i=0; i<3; i++)  //check column-wise

		if( matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i] && matrix[1][i]==matrix[2][i] && matrix[0][i]!=-1)

		{

			displayMatrix();

			cout<<"Player "<<matrix[0][i]<<" Wins!!!!!!!";

			return true;

		}	

	

	//check diagonals		

	if( (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[1][1] == matrix[2][2]) && matrix[0][0]!=-1)

	{

		displayMatrix();

		cout<<"Player "<<matrix[0][0]<<" Wins!!!!!!!";

		return true;

	}	

	if( (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[1][1] == matrix[2][0]) && matrix[0][2]!=-1)

	{

		displayMatrix();

		cout<<"Player "<<matrix[0][2]<<" Wins!!!!!!!";

		return true;

	}	

	return false;

}



void ticTacToe :: endGame()

{

	cout<<"\nCONGRATULATIONS!!!\n";

}



void ticTacToe :: CPUTurn()

{

	cout<<"\n----------------------------------CPU's TURN------------------------------------\n";

	decidePosition();

	cout<<"CPU has played its turn!\n";

}



void ticTacToe :: decidePosition()

{

	for(int i=0; i<3; i++) //check if matrix is empty

	{

		for(int j=0; j<3; j++)

		{

			if(matrix[i][j] != -1)

				matrixEmpty = false;

		}

	}

	if(matrixEmpty)

	{

		matrix[0][0] = 1;

		matrixEmpty = false;

	}

	else

	{

		smartInsert();	

	}

}



bool ticTacToe :: occupyCorners()

{

	if(matrix[0][0] == -1)

	{

		matrix[0][0] = 1;

		return true;

	}

	if(matrix[0][2] == -1)

	{

		matrix[0][2] = 1;

		return true;

	}

	if(matrix[2][0] == -1)

	{

		matrix[2][0] = 1;

		return true;

	}

	if(matrix[2][2] == -1)

	{

		matrix[2][2] = 1;

		return true;

	}

	return false;

}



bool ticTacToe :: updateVal(int val)

{

	for(int i=0; i<3; i++)  //update row-wise

		if( (matrix[i][0]==matrix[i][1] && matrix[i][0] == val && matrix[i][0] != -1) || (matrix[i][0]==matrix[i][2] && matrix[i][0] == val && matrix[i][0] != -1) || (matrix[i][1]==matrix[i][2] && matrix[i][1] == val && matrix[i][1] != -1) )

		{	

			for(int j=0; j<3; j++)

			{

				if(matrix[i][j] == -1)

				{

					matrix[i][j] = 1;

					return true;

				}

			}

		}

	for(int i=0; i<3; i++)  //update column-wise

		if( (matrix[0][i]==matrix[1][i] && matrix[0][i] == val && matrix[0][i] != -1) || (matrix[0][i]==matrix[2][i] && matrix[0][i] == val && matrix[0][i] != -1) || (matrix[1][i]==matrix[2][i] && matrix[1][i] == val && matrix[1][i] != -1) )

		{		

			for(int j=0; j<3; j++)

			{

				if(matrix[j][i] == -1)

				{

					matrix[j][i] = 1;

					return true;

				}

			}

		}

		//check diagonals

	if( ((matrix[0][0] == matrix[1][1] && matrix[0][0] == val && matrix[0][0] != -1) || (matrix[0][0] == matrix[2][2] && matrix[0][0] == val && matrix[0][0] != -1) || (matrix[1][1] == matrix[2][2] && matrix[1][1] == val && matrix[1][1] != -1)) )

	{

		for(int i=0; i<3; i++)

		{

			for(int j=0; j<3; j++)

			{

				if(i==j)

				{

					if(matrix[i][j] == -1)

					{

						matrix[i][j] = 1;

						return true;

					}	

				}

			}

		}

	}

	if( ((matrix[0][2] == matrix[1][1] && matrix[0][2] == val && matrix[0][2] != -1) || (matrix[0][2] == matrix[2][0] && matrix[0][2] == val && matrix[0][2] != -1) || (matrix[1][1] == matrix[2][0] && matrix[1][1] == val && matrix[1][1] != -1)) )

	{

		if(matrix[0][2] == -1)

		{

			matrix[0][2] = 1;

			return true;

		}

		if(matrix[1][1] == -1)

		{

			matrix[1][1] = 1;

			return true;

		}

		if(matrix[2][0] == -1)

		{

			matrix[2][0] = 1;

			return true;

		}

	}

	return false;

}



bool ticTacToe :: checkAdjecency()

{

	if(matrix[0][0] == 1 && matrix[1][1] == -1)

	{

		if(matrix[0][1] == 2 && matrix[1][0] == 2)

		{

			matrix[1][1] = 1;

			return true;

		}

	}

	if(matrix[0][2] == 1 && matrix[1][1] == -1)

	{

		if(matrix[0][1] == 2 && matrix[1][2] == 2)

		{

			matrix[1][1] = 1;

			return true;

		}

	}

	if(matrix[2][0] == 1 && matrix[1][1] == -1)

	{

		if(matrix[1][0] == 2 && matrix[2][1] == 2)

		{

			matrix[1][1] = 1;

			return true;

		}

	}

	if(matrix[2][2] == 1 && matrix[1][1] == -1)

	{

		if(matrix[2][1] == 2 && matrix[1][2] == 2)

		{

			matrix[1][1] = 1;

			return true;

		}

	}

	return false;

}



void ticTacToe :: smartInsert()

{

	if(!checkAdjecency())

		if(!updateVal(1))

			if(!updateVal(2))

			{

				runNext = occupyCorners();

				if(runNext == false)

				{

					for(int i=0; i<3; i++)

						for(int j=0; j<3; j++)

							if(matrix[i][j] == -1)

							{

								matrix[i][j] = 1;

							}

				}

			}

}



int main()

{

	ticTacToe game;

	game.manageGameFlow();

	getch();

}
