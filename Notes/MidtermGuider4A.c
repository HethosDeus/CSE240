#define _CRT_SECURE_NO_WARNINGS_

#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Did you now the tic-tac-toe game? Create a 3x3 array to store a tic-tac-toe. Fill the array with ‘X’ or ‘O’. All the cells with the same value. 
	Which data type should be used?  Char [][] to store the array type, that will be filled with Xs and Ox.
	Provide your source code using C.  Source code above
*/

void drawBoard(char board[][3])
{
	int rows, columns;
	for (rows = 0; rows < 3; rows++)
	{
		for (columns = 0; columns < 3; columns++)
		{
			if (board[rows][columns]) {
				printf("|%c", board[rows][columns]);
			}
			else {
				printf("| ");
			}
		}
		printf("|\n");
	}
}/* end function drawboard */


int main()
{
	char game[3][3] = { {0} };
	int totalEntry = 0, row, column;
	char value;

	while (totalEntry <= 9) {
		printf("Enter (x) or (o): ");
		scanf("%c", &value);
		getchar();
		printf("Enter row number: ");
		scanf("%d", &row);
		getchar();
		printf("Enter Column number: ");
		scanf("%d", &column);
		getchar();
		game[row][column] = value;
		drawBoard(game);
	}

	return 0;
} 

/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
• Use the language C. Create a struct named ball. Put 2 variables inside: an array of chars to store a color and an integer to store an id.
• Ask the user for a number using	scanf.
• Use the number that the user provides to create an array of balls. The number represents how many elements the array should have.
• Store in the first position of the array a ball with color= blue and id=1
*/
struct ball
{
	char *color;
	int id;
};

int main()
{
	int user; 

	printf("Enter a number: \n");
	scanf("%d", &user);
	struct ball *arrBalls = (int)malloc(user * sizeof(int));

	arrBalls[0].color = "blue";
	arrBalls[0].id = 1;
	printf("Ball array size: %d \n", user);
	printf("Ball color: %s \n", arrBalls[0].color);
	printf("Ball id: %d \n", arrBalls[0].id);
	
	return 0;
}
