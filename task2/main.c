#include <stdio.h>

#define row 25
#define col 25

int isValidMove(char direction, int *x, int *y);
void movePlayer(char direction, int *x, int *y);

int main()
{
	char grid[row][col];
	printf("\033[H\033[j");
	int x,y;//player position
	x = rand()%row;
	y = rand()%col;
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			grid[i][j] = '*';
		}
	}
	grid[x][y] = '0';
	printGrid(grid);
	char direction = rand()%8;// 0 is up then clock wise ; 1 top right ; 2 right...etc
	while(1)
	{
	grid[x][y] = ' ';
	while(1)
	{
		if(isValidMove(direction, &x, &y) == -1)
			direction = rand()%8;
		else
		{
			grid[x][y] = ' ';//previous player position
			movePlayer(direction, &x, &y);
			grid[x][y] = '0';//current player position
			printGrid(grid);
			//printf("(%d,%d)\n",x,y);
		}
	}//keep trying to find a valid move
	}
	return 0;
}

void printGrid(char grid[row][col])
{
	printf("\033[H\033[j");
	printf("======================GRID=======================\n");
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("%c ",grid[i][j]);
		}
		printf("\n");
	}
	printf("=================================================\n");
}
void movePlayer(char direction, int *x, int *y)
{
	switch(direction)
	{
		case 0:
			*x=*x-1;
			break;
		case 1:
			*x=*x-1;
			*y=*y+1;
			break;
		case 2:
			*y=*y+1;
			break;
		case 3:
			*y=*y+1;
			*x=*x+1;
			break;
		case 4:
			*x=*x+1;
			break;
		case 5:
			*x=*x+1;
			*y=*y-1;
			break;
		case 6:
			*y=*y-1;
			break;
		case 7:
			*y=*y-1;
			*x=*x-1;
			break;
	}
	return 0;
}

int isValidMove(char direction, int *x, int *y)
{
	switch(direction)
	{
		case 0:
			if(*x == 0)
				return -1;
//			*x--;
			break;
		case 1:
			if(*x == 0 || *y == col)
				return -1;
//			*x--;
//			*y++;
			break;
		case 2:
			if(*y == col)
				return -1;
//			*y++;
			break;
		case 3:
			if(*y == col || *x == row)
				return -1;
//			*y++;
//			*x++;
			break;
		case 4:
			if(*x == row)
				return -1;
//			*x++;
			break;
		case 5:
			if(*x == row || *y == 0)
				return -1;
//			*x++;
//			*y--;
			break;
		case 6:
			if(*y == 0)
				return -1;
//			*y--;
			break;
		case 7:
			if(*y == 0 || *x == 0)
				return -1;
//			*y--;
//			*x--;
			break;
	}
	return 0;
}
