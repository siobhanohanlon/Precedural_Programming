#include <stdio.h>
#include <stdlib.h>

//Struct
typedef struct
{
	char name[30];
	int age;
}studentT;

//Declare Funstions
void PrintArray(int* table, int size);
void ReadArray(int* table2, int size);
void ReadStudentArray(studentT* studArray, int size);
void DisplayStudent(studentT* studArray1, int size);


void main()
{
	int* myArray;
	studentT* sArray;
	int numComp;

	//Enter Size of Array
	printf("Please enter size of the Array: ");
	scanf("%d", &numComp);

	myArray = (int*)malloc(numComp * sizeof(int));
	sArray = (studentT*)malloc(numComp * sizeof(studentT));

	printf("\n");

	//Set Array
	ReadArray(myArray, numComp);

	//Print Array
	PrintArray(myArray, numComp);

	//Student Array
	ReadStudentArray(sArray, numComp);

	//Display
	DisplayStudent(sArray, numComp);

	//Free Alocation- Cant use after doing this
	free(myArray);
}

//MyArray
void ReadArray(int* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Please enter the Value for Element %d: ", i);
		scanf("%d", (table + i));
	}
}

void PrintArray(int* table2, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("\nThe Value at Element %d is %d", i, *(table2 + i));
	}
}

//Student Array
void ReadStudentArray(studentT* studArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Please Enter Student Name: ");
		scanf("%s", (*(studArray + i)).name); //scanf("%s", (sArray + i)->name);

		printf("Please Enter Student Age: ");
		scanf("%d", &(*(studArray + i)).age); //scanf("%d", &(sArray + i)->age);
	}
}

void DisplayStudent(studentT* studArray1, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("The Name is %s and Age is %d", (studArray1 + i)->name, (studArray1 + i)->age);
	}
}