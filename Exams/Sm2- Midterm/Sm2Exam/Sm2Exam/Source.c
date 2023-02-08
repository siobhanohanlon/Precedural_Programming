#include <stdio.h>
#include <string.h>

//Declare Struct
typedef struct
{
	int studentType;
	int studentID;
	float averageGrade;
	char homeCountry[30];
	char firstName[30];
	char surName[30];
}studentDetails;

//Declare Funstions
void initArray(studentDetails* stud, int size);
void menu(studentDetails* student, int size);
void addNewStudent(studentDetails* student, int size);
void displayStudent(studentDetails* student, int size);
void findStudent(studentDetails* student, int size);
void homeCountry(studentDetails* student, int size);

//Main
void main()
{
	//Declare Struct and Variables
	studentDetails* stud;
	int size;

	//Enter Size of Array
	printf("Please Enter amount of Students to be entered: ");
	scanf("%d", &size);

	//SetUp Array
	stud = (studentDetails*)malloc(size * sizeof(studentDetails));

	//Initialise Array
	initArray(stud, size);

	//Show User Menu
	menu(stud, size);
}

//Initialise Array
void initArray(studentDetails* stud, int size)
{
	for (int i = 0; i < size; i++)
	{
		(*(stud + i)).studentID = -1;
	}
}

//Menu
void menu(studentDetails* student, int size)
{
	int choice;

	printf("\nSelect 1. Add New Student 2. Display Best Student 3. Find Student by Type 4. Home Country Statistics  Other to Exit \nChoice:");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		addNewStudent(student, size);
		break;
	case 2:
		displayStudent(student, size);
		break;
	case 3:
		findStudent(student, size);
		break;
	case 4:
		homeCountry(student, size);
		break;
	default:
		exit(0);
		return;
		break;
	}
}

//Add new Student
void addNewStudent(studentDetails* student, int size)
{
	int thisStudent, unique, homeCountry;

	for (int i = 0; i < size; i++)
	{
		if ((*(student + i)).studentID == -1)
		{
			//Student ID
			do
			{
				//Reset Unique
				unique = 0;

				printf("\nPlease Enter Student ID: ");
				scanf("%d", &thisStudent);

#pragma region CheckUniqueNumber
				//Check if correct number entered
				for (int j = 0; j < size; j++)
				{
					if (thisStudent == (*(student + j)).studentID)
					{
						unique = -1;
					}
				}

				if (unique == -1)
				{
					printf("\n\nERROR!!!!!!!!!!!!!!");
					printf("\nNot a unique Student ID Entered\n");
				}

				else
				{
					//Assign as it is unique
					(*(student + i)).studentID = thisStudent;
				}

#pragma endregion



			} while (unique == -1);

			//Name
			printf("Please Enter Student's First Name: ");
			scanf("%s", (*(student + i)).firstName);

			printf("Please Enter Student's Surname: ");
			scanf("%s", (*(student + i)).surName);

			//Student Type
			printf("1:On Campus\t2:Hybrid\t3:Online\nPlease Enter Student Type:");
			scanf("%d", &(*(student + i)).studentType);

			//Home Country
			printf("Ireland\tEngland\tWales\tScotland\nFrance\tSpain\tItaly\nPlease Enter Student's Home Country: ");
			scanf("%s", (*(student + i)).homeCountry);

			//Average Grade
			printf("Please Enter Student's Average Grade: ");
			scanf("%f", &(*(student + i)).averageGrade);

			//Send User back to Menu
			menu(student, size);
		}
	}
}

//Display Student
void displayStudent(studentDetails* student, int size)
{
	//Declare Variables
	float bestGrade = 0.0;
	int bestStudent = 0;
	char studentType[15];

	//Find Student with Best Grade
	for (int i = 0; i < size; i++)
	{
		if ((*(student + i)).studentID != -1)
		{
			if ((*(student + i)).averageGrade > bestGrade)
			{
				bestGrade = (*(student + i)).averageGrade;
				bestStudent = (*(student + i)).studentID;
			}
		}
	}

	//Display best Student Stats
	for (int j = 0; j < size; j++)
	{
		if ((*(student + j)).studentID != -1)
		{
			if ((*(student + j)).studentID == bestStudent)
			{
				printf("\n----------------------------------------------------------");
				printf("\nStudent ID: %d\nStudent Name: %s %s\nStudent Type: ", (*(student + j)).studentID, (*(student + j)).firstName, (*(student + j)).surName);

				//Switch to change Student type from int to string
				switch ((*(student + j)).studentType)
				{
					//1:On - Campus\t2 : Hybrid\t3 : Online
					case 1:
						printf("On Campus");
						break;
					case 2:
						printf("Hybrid");
						break;
					case 3:
						printf("Online");
						break;
				}

				printf("\nHome Country: %s\nAverage Grade: %.2f", (*(student + j)).homeCountry, (*(student + j)).averageGrade);
				printf("\n----------------------------------------------------------");

				//Send User back to Menu
				menu(student, size);
			}
		}
	}
}

//Find Student bt type
/*
*	I wasnt completely sure on what you were asking here, wasnt sure if want to find or just print 
*	i was also unsure if you meant we could choose the variable we search by or if it was something else
*	as we didnt use the student type i thought this was the best one to go about by so i print all students in the type picked
*/
void findStudent(studentDetails* student, int size)
{
	//Declare Variables
	int choice;

	//Ask User which type they would like to search
	printf("\n1. On Campus\t2.Hybrid\t3.Online\nPlease Choose which Type youd like to Search: ");
	scanf("%d", &choice);

	//Find Student with Best Grade
	for (int l = 0; l < size; l++)
	{
		if ((*(student + l)).studentType == choice)
		{
			printf("\n----------------------------------------------------------");
			printf("\nStudent ID: %d\nStudent Name: %s %s\nStudent Type: ", (*(student + l)).studentID, (*(student + l)).firstName, (*(student + l)).surName);

			//Switch to change Student type from int to string
			switch ((*(student + l)).studentType)
			{
				//1:On - Campus\t2 : Hybrid\t3 : Online
			case 1:
				printf("On Campus");
				break;
			case 2:
				printf("Hybrid");
				break;
			case 3:
				printf("Online");
				break;
			}

			printf("\nHome Country: %s\nAverage Grade: %.2f", (*(student + l)).homeCountry, (*(student + l)).averageGrade);
			printf("\n----------------------------------------------------------");

		}
	}

	//Send User back to Menu
	menu(student, size);
}

//Percentage of Home County
/*
*	I was very unsure on how to do this one so i made it hoping the user would only enter countries suggested
*	I tried a way i thought might work but unsure if it is what you are asking for
*/
void homeCountry(studentDetails* student, int size)
{
	//Declare Variables
	float ire = 0, engl = 0, wales = 0, scot = 0, fran = 0, spain = 0, italy = 0;
	float counter = 0;

	//Print Out Home Country Choices
	printf("Please Choose a country Below to ");

	//Find Student with Best Grade
	for (int l = 0; l < size; l++)
	{
		if ((*(student + l)).studentID != -1)
		{
			counter++;
#pragma region Count Countrys
			//Ireland
			if ((*(student + l)).homeCountry == "Ireland")
			{
				ire++;
			}

			//England
			if ((*(student + l)).homeCountry == "England")
			{
				engl++;
			}

			//Wales
			if ((*(student + l)).homeCountry == "Wales")
			{
				wales++;
			}

			//Scotland
			if ((*(student + l)).homeCountry == "Scotland")
			{
				scot++;
			}

			//France
			if ((*(student + l)).homeCountry == "France")
			{
				fran++;
			}

			//Spain
			if ((*(student + l)).homeCountry == "Spain")
			{
				spain++;
			}

			//Italy
			if ((*(student + l)).homeCountry == "Italy")
			{
				italy++;
			}

#pragma endregion
		}		
	}

	printf("\n----------------------------------------------------------");
	printf("\nIreland: %.2f ", (ire/counter));
	printf("\nEngland: %.2f ", (engl / counter));
	printf("\nWales: %.2f ", (wales / counter));
	printf("\nScotland: %.2f ", (scot/ counter));
	printf("\nFrance: %.2f ", (fran / counter));
	printf("\nSpain: %.2f ", (spain / counter));
	printf("\nItaly: %.2f ", (italy / counter));
	printf("\n----------------------------------------------------------");

	//Send User back to Menu
	menu(student, size);
}