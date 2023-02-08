#include <stdio.h>

typedef struct person
{
	char name[20], surname[20];
	int age;
}personT;

void main()
{
	struct person p1; //this is done without typedef or personT at end
	personT p2; //This is done with typedef and personT at end
	personT group[5]; //Can make arrays of structs

	//Reading in Person1
	printf("Please Enter Person 1s first name :\t");
	scanf("%s", p1.name); //Dont need & for strings

	printf("\nPlease Enter Person 1s Surname:\t");
	scanf("%s", p1.surname);

	printf("\nPlease Enter Person 1s Age:\t");
	scanf("%d", &p1.age);

	printf("The first name is %s, the surname is %s and the age is %d", p1.name, p1.surname, p1.age);

	//Reading into group
	for (int i = 0; i < 5; i++)
	{
		printf("Please Enter First Name of Person at index %d:\t", i);
		scanf("%s", group[i].name); //Dont need & for strings

		printf("\nPlease Enter Surname of Person at index %d:\t", i);
		scanf("%s", group[i].surname);

		printf("\nPlease Enter Age of Person at index %d:\t", i);
		scanf("%d", &group[i].age);
	}

	//Display
	for (int j = 0; j < 5; j++)
	{
		printf("First Name: %s\tSurname: %s\tAge: %d\n", group[j].name, group[j].surname, group[j].age);
	}
}