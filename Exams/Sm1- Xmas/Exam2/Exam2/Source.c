#include <stdio.h>
#include <string.h>

//Declare Struct
typedef struct
{
	char regNum[20];
	char manufName[20];
	char model[20];
	int fuelType, stockQty, bracket;
	float salesPrice;
}car;

//Declare Funstions
void initArray(car* vehicle);
void menu(car* model);
void addNewCar(car* model);;
void displayCar(car* model);
void editCar(car* model);
void carStats(car* model);
void printToFile(car* model);

//Main
void main()
{
	//Declare Struct and Variables
	car* vehicle;

	//SetUp Array
	vehicle = (car*)malloc(100 * sizeof(car));

	//Initialise Array
	initArray(vehicle);

	//Display Company Screen
	printf("\n\t\t*************************************************");
	printf("\n\t\t*\t\t\t\t\t\t*");
	printf("\n\t\t*\t\t    Welcome to    \t\t*");
	printf("\n\t\t*\t\t  Auto Sales Ltd  \t\t*");
	printf("\n\t\t*\t\t\t\t\t\t*");
	printf("\n\t\t*************************************************\n\n");

	//Menu
	menu(vehicle);
}

//Initialise Array
void initArray(car* vehicle)
{
	for (int i = 0; i < 100; i++)
	{
		(*(vehicle + i)).fuelType = -1;
	}
}

//Menu
void menu(car* model)
{
	int choice;

	printf("\nSelect\n1. Add New Car\n2. Display Cars by Fuel Type\n3. Edit Car\n4. Query Car Valuation\n5. Print Database to File\nOther to Exit\nChoice:");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		addNewCar(model);
		break;
	case 2:
		displayCar(model);
		break;
	case 3:
		editCar(model);
		break;
	case 4:
		carStats(model);
		break;
	case 5:
		printToFile(model);
		break;
	default:
		exit(0);
		return;
		break;
	}
}

//Add New Car
void addNewCar(car* autoCars)
{
	int unique;
	char thisReg[20];

	for (int i = 0; i < 100; i++)
	{
		if ((*(autoCars + i)).fuelType == -1)
		{
			//Unique
			do
			{
				//Reset Unique
				unique = 0;

				printf("\nPlease Enter Car Registration: ");
				scanf("%s", &thisReg);

#pragma region CheckUniqueNumber
				//Check if correct number entered
				for (int j = 0; j < 100; j++)
				{
					if (stricmp(thisReg, (*(autoCars + j)).regNum) == 0)
					{
						unique = -1;
					}
				}

				if (unique == -1)
				{
					printf("\n\nERROR!!!!!!!!!!!!!!");
					printf("\nNot a unique Car Registration Entered\n");
				}

				else
				{
					//Assign as it is unique
					for (int k = 0; k < 20; k++)
					{
						(*(autoCars + i)).regNum[k] = thisReg[k];
					}
				}
#pragma endregion

			} while (unique == -1);

			//Manufacturer Name
			printf("Please Enter Manufacturers Name: ");
			scanf("%s", (*(autoCars+ i)).manufName);

			//Model Name
			printf("Please Enter Model Name: ");
			scanf("%s", (*(autoCars + i)).model);

			//Fuel Type
			printf("Please Select Fuel Type\n1. Diesel\t2. Petrol\t3.Hybrid\nChoice:");
			scanf("%d", &(*(autoCars + i)).fuelType);

			

			//Quantity
			printf("Please Enter Stock Quantity: ");
			scanf("%d", &(*(autoCars + i)).stockQty);

			//Send User back to Menu
			menu(autoCars);
		}
	}
}

//Display Car
void displayCar(car* model)
{
	int thisFuel;
	char fuel[10];

	printf("Please Select Fuel Type to Search\n1. Diesel\t2. Petrol\t3.Hybrid\nChoice:");
	scanf("%d", &thisFuel);
	
	for (int g = 0; g < 100; g++)
	{
		//Change Fuel from int to String
		switch ((*(model + g)).fuelType)
		{
		case 1:
			strncpy(fuel, "Diesel", 100);
			break;
		case 2: 
			strncpy(fuel, "Petrol", 100);
			break;
		case 3: 
			strncpy(fuel, "Hybrid", 100);
			break;
		default:
			break;
		}

		printf("\nCar DataBase: All %s Cars", thisFuel);

		//Display Car
		if ((*(model + g)).fuelType == thisFuel)
		{
			printf("\nRegistration Number: %s", (*(model + g)).regNum);
			printf("\nManufacturer Name: %s", (*(model + g)).manufName);
			printf("\nModel Namw: %s", (*(model + g)).model);
			printf("\nFuel Type: %s", fuel);
			printf("\nSales Price: %s", (*(model + g)).salesPrice);
			printf("\nQuantity in Stock: %s", (*(model + g)).stockQty);
		}
	}
}

//Edit Car
void editCar(car* model)
{
	//Variables
	char reg[10];
	int choice, done;

	//Ask user for car reg
	printf("\nPlease Enter Car Registration: ");
	scanf("%s", &reg);

	//Choose what to edit
	for (int j = 0; j < 100; j++)
	{
		if (stricmp(reg, (*(model+ j)).regNum) == 0)
		{
			do
			{
				done = 0;
				
				printf("\nPlease Choose what to change");
				printf("\n1. Fuel Type or 2. Sales Price");

				scanf("%d", &choice);

				switch (choice)
				{
					case 1:
						//Fuel Type
						printf("Please Select Fuel Type\n1. Diesel\t2. Petrol\t3.Hybrid\nChoice:");
						scanf("%d", &(*(model + j)).fuelType);
						done = 1;
						break;
					case 2:
						//Sales Price
						printf("Please Enter Sales Price: ");
						scanf("%f", &(*(model + j)).salesPrice);
						done = 1;
						break;
					default:
						//Wrong number enetered
						printf("ERROR!!!!!!!!!!!!!!");
						printf("Number Entered outside of reach please re-enter");
						break;
				}
			} while (done == 0);
		}
	}
}

//Car Valuation
//I ran out of time and didnt get to finish this but was going to let them decide which bracket to print and only print them
void carStats(car* model)
{
	//Variables
	float thisPrice;
	
	//Find cars Price
	for (int j = 0; j < 100; j++)
	{
		thisPrice = (*(model + j)).salesPrice;

		if (thisPrice < 10000)
		{
			(*(model + j)).bracket = 1;
		}

		else if (thisPrice < 20000 && thisPrice > 10000)
		{
			(*(model + j)).bracket = 2;
		}

		else if (thisPrice < 30000 && thisPrice > 20000)
		{
			(*(model + j)).bracket = 3;
		}

		else if (thisPrice < 40000 && thisPrice > 30000)
		{
			(*(model + j)).bracket = 4;
		}

		else if (thisPrice > 40000)
		{
			(*(model + j)).bracket = 5;
		}
	}

	//Print to Screen by Sales Price
	printf("\nPlease Select a Price Valuation Bracket:");
	printf("\n1. Less then €10,000\n2. Between €10,000 & €20,000\n3. Between €20,000 & €30,000\n4. Between €30,000 & €40,000\n5.Over €40,000");
}

//Print to File
void printToFile(car* model)
{
	//Variables
	char thisFuel[10];

	//Object of File
	FILE* newFile;

	//Open File to write to
	newFile = fopen("Car.txt", "w");

	for (int g = 0; g < 100; g++)
	{
		//Change Fuel from int to String
		switch ((*(model + g)).fuelType)
		{
		case 1:
			strncpy(thisFuel, "Diesel", 100);
			break;
		case 2:
			strncpy(thisFuel, "Petrol", 100);
			break;
		case 3:
			strncpy(thisFuel, "Hybrid", 100);
			break;
		default:
			break;
		}

		//Write to File
		fprintf("%s %s %s %s %f %d", 
			(*(model + g)).regNum, (*(model + g)).manufName, (*(model + g)).model, 
			thisFuel, (*(model + g)).salesPrice, (*(model + g)).stockQty);
	}

	//Close File
	fclose(newFile);
}