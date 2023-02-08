#include<stdio.h>
#include<stdlib.h>

void Read2DArray(int** table, int rowSize, int colSize);
void DisplayArray(int** table, int rowSize, int colSize);

void main()
{
	int** array2D;
	int rows, cols, i;

	//Ask User to enter Rows&Cols amount
	printf("Please enter the number of rows and cols in the 2D Array:\t");
	scanf("%d %d", &rows, &cols);

	//Set Array
	array2D = (int**)malloc(rows * sizeof(int*));

	for (i = 0; i < rows; i++)
	{
		array2D[i] = (int**)malloc(cols * sizeof(int));
	}

	//Read in Array
	Read2DArray(array2D, rows, cols);

	//Display Array
	DisplayArray(array2D, rows, cols);
}

void Read2DArray(int** table, int rowSize, int colSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("Please enter the value for row %d cold %d:\t", i+1, j+1);
			scanf("%d", *(table + i) + j);
		}
	}
}

void DisplayArray(int** table, int rowSize, int colSize)
{
	printf("\n\n--------------------Table--------------------");

	for (int i = 0; i < rowSize; i++)
	{
		printf("\n\t\t");
		for (int j = 0; j < colSize; j++)
		{
			printf("%d \t", *(*(table + i) + j));
		}
	}
}