#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct
typedef struct
{
	long bNum;
	char bTitle[30];
	char bAuthor[25];
	double bPrice;
}libraryB;

//Declare Funstions
void initArray(libraryB* bkArr, int size);
void displayArr(libraryB* bkArr, int size);
void add_Book(libraryB* bkArr, int size);
void menu();
void edit_Price();

void main()
{
	int* bookArray;
	libraryB* bArray;
	int numB, choice;

	//Enter Size of Array
	printf("Please Enter amount of Books to be enetered: ");
	scanf("%d", &numB);

	//SetUp Array
	bookArray = (int*)malloc(numB * sizeof(int));
	bArray = (libraryB*)malloc(numB * sizeof(libraryB));

	initArray(bArray, numB);

	do
	{
		printf("Enter 1 to add a book or 0 to exit:\t");
		scanf("%d", &choice);

		if (choice == 1)
		{
			add_Book(bArray, numB);
		}
	} while (choice == 1);
	
	displayArr(bArray, numB);
}

//Initialise Array
void initArray(libraryB* bkArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		(*(bkArr + i)).bNum = 0;
	}
}

//Set Array
void add_Book(libraryB* bkArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if ((*(bkArr + i)).bNum == 0)
		{
			printf("Please Enter Book Number: ");
			scanf("%ld", &(*(bkArr + i)).bNum);

			printf("Please Enter Book Title: ");
			scanf("%s", (*(bkArr + i)).bTitle);

			printf("Please Enter Book Author: ");
			scanf("%s", (*(bkArr + i)).bAuthor);

			printf("Please Enter Book Price: ");
			scanf("%d", &(*(bkArr + i)).bPrice);

			return;
		}
	}
}

//Display Array
void displayArr(libraryB* bkArr, int size)
{
	int findBk;

	//Ask for Book Number
	printf("\nEnter Book Number you want to display: ");
	scanf("%d", &findBk);

	for (int i = 0; i < size; i++)
	{
		if ((*(bkArr + i)).bNum == findBk)
		{
			printf("\n----------------------------------------------------------");
			printf("\nBook Number: %ld", (*(bkArr + i)).bNum);
			printf("\nTitle: %s", (*(bkArr + i)).bTitle);
			printf("\nAuthor: %s", (*(bkArr + i)).bAuthor);
			printf("\nPrice: %.2d", (*(bkArr + i)).bPrice);
			printf("\n----------------------------------------------------------");

			return;
		}
	}
}

//Edit Price
void edit_Price(libraryB* bkArr, int size)
{
	int changeBk, change, repeat;

	do {
		//Ask for Book Number
		printf("\nEnter Book Number you want to change the price of: ");
		scanf("%d", &changeBk);

		for (int i = 0; i < size; i++)
		{
			if ((*(bkArr + i)).bNum == changeBk)
			{
				printf("\nPrice: was %.2d", (*(bkArr + i)).bPrice);
				printf("\nNew Price:");
				scanf("%d", &(*(bkArr + i)).bPrice);
			}
		}

		printf("Would you like to edit another books price?\nEnter 1: Yes Other: No");
		scanf("%d", &change);

		if (change == 1)
		{
			repeat = 1;
		}

		else
		{
			repeat = 0;
		}
	} while (repeat == 1);
}

//Menu
void menu(libraryB* bkArr, int size)
{
	int choice;

	printf("Select 1. Search & Display Book  2. Add Book  3.Edit Book Price  Other to Exit ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
			displayArr(bkArr, size);
			break;
		case 2:
			add_Book(bkArr, size);
			break;
		case 3:
			edit_Price(bkArr, size);
			break;
		default:
			exit(0);
			break;
	}
}