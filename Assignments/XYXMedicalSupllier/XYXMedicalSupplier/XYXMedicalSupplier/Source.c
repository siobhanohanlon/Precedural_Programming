//G00389108
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structs
//Company Details
typedef struct
{
    int regNumber, yearFounded, numEmployees, vReg, avT, emplo, comA, check;
    char name[20], country[20], email[20], contactName[20];
    float lastOrder, averageAnnOrder;
    char vatReg[5], avTurnover[25], staff[25], area[25];
}company;

//Stats
typedef struct
{
    int less1, less10, mil10;
    int select1, selection;
}stats;

//----------------------------------------------------------------------------
//Functions
#pragma region Functions
void Menu(company* client, stats generate);
bool Login();
void initArray(company* client, stats generate);
void AddClient(company* client, stats generate);
void DisplayAll(company* client, stats generate);
void DisplayClient(company* client, stats generate);
void UpdateClient(company* client, stats generate);
void DeleteClient(company* client, stats generate);
void GenerateStats(company* client, stats generate);
void ListByAvT(company* client, stats generate);
void PrintFile(company* client, stats generate);
#pragma endregion

//----------------------------------------------------------------------------
//Main
void main()
{
    //Declare Struct
    company* client;
    stats generate;

    //SetUp Array
    client = (company*)malloc(100 * sizeof(company));
  
    //Display Company Screen
    printf("\n\t\t*************************************************");
    printf("\n\t\t*\t\t\t\t\t\t*");
    printf("\n\t\t*\t\t    Welcome to    \t\t*");
    printf("\n\t\t*\t    XYX Medical Supplier Limited     \t*");
    printf("\n\t\t*\t\t\t\t\t\t*");
    printf("\n\t\t*************************************************\n\n");

    //Variables
    bool login;

    //Get User to Login to System
    do {
        login = Login();

        if (login == true)
        {
            printf("\n\n\n******************************************");
            printf("\n\tSystem Access Granted!!!\n");
            printf("\n******************************************");
        }

        else
        {
            printf("\n\n\n******************************************");
            printf("\n\tSystem Access Denied!!!\n");
            printf("Wrong UserName or Password Entered");
            printf("\n******************************************\n\n");
        }
    } while (login == false);

    generate.selection = 0;

    //Initalise Struct Array
    initArray(client, generate);

    //Menu
    Menu(client, generate);
}

//----------------------------------------------------------------------------
//Initialize Array
void initArray(company* client, stats generate)
{
    FILE* info;

    //Set Array
    for (int i = 0; i < 100; i++)
    {
        (*(client + i)).regNumber = -1;
        (*(client + i)).check = 0;
    }

    //Read into Array from file
    info = fopen("Clients.txt", "r");

    while (!feof(info))
    {
        for (int j = 0; j < 100; j++)
        {
            if ((*(client + j)).regNumber == -1)
            {
                //Display
                fscanf(info, "%d %s %s %d %s ", &(*(client + j)).regNumber, (*(client + j)).name, (*(client + j)).country, &(*(client + j)).yearFounded, (*(client + j)).email);
                fscanf(info, "%s %f %d %f ", (*(client + j)).contactName, &(*(client + j)).lastOrder, &(*(client + j)).numEmployees, &(*(client + j)).averageAnnOrder);
                fscanf(info, "%d %d %d %d\n", &(*(client + j)).vatReg, &(*(client + j)).avT, &(*(client + j)).emplo, &(*(client + j)).comA);
            }
        }
    }
    
}

//----------------------------------------------------------------------------
//Login
bool Login()
{
    //Variables
    char userName[20], password[20];
    char user[20], pass[20];
    int passLength = 0, endFile, correct = 0;

    //Ask User for username and password
    printf("Please Enter Username:\t\t");
    scanf("%s", userName);

    //Password
    printf("Please Enter Password:\t\t");

    //Print * as you enter Password
    do {
        password[passLength] = getch();
        if (password[passLength] != '\r') {
            printf("*");
        }
        passLength++;
    } while (password[passLength - 1] != '\r');
    password[passLength - 1] = '\0';
    getch();

    //Read in login file
    FILE* log;

    //Open file
    log = fopen("login.txt", "r");

    //Check if File Opened
    if (NULL == log) {
        printf("\nERROR!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("File can't be opened \n");
    }

    else
    {
        endFile = getc(log);
        //Read in file contents
        while (correct < 4) 
        {  
            fscanf(log, "%s %s", user, pass);

            if (strcmp(user, userName) == 0)
            {               
                if (strcmp(pass, password) == 0)
                {
                    correct = 5;
                }
            }

            correct++;
        }

        if (correct > 4)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
}

//----------------------------------------------------------------------------
//Menu
void Menu(company* client, stats generate)
{
    //Variables
    int choice;

    //Display Menu
    printf("\n\n\t***** Menu *****");
    printf("\nPlease Select an Option");
    printf("\n1. Add Client\n2. Display All Client Details\n3. Display Client Details\n4. Update Client Details");
    printf("\n5. Delete Client\n6. Generate Statics\n7. Print All Clients to File\n8. List Clients in Average Turnover Order\n");
    printf("Other to Exit\n");

    printf("Option: ");
    scanf("%d", &choice);

    //Ask User to choose an option

    //Menu Choice
    switch (choice)
    {
        case 1:
            AddClient(client, generate);
            break;
        case 2:
            DisplayAll(client, generate);
            break;
        case 3:
            DisplayClient(client, generate);
            break;
        case 4:
            UpdateClient(client, generate);
            break;
        case 5:
            DeleteClient(client, generate);
            break;
        case 6:
            GenerateStats(client, generate);
            break;
        case 7:
            PrintFile(client, generate);
            break;
        case 8:
            ListByAvT(client, generate);
            break;
        default:
            PrintFile(client, generate);
            exit(0);
            break;
    }
}

//----------------------------------------------------------------------------
//Add Client
void AddClient(company* client, stats generate)
{
    //Variables
    int thisClient, unique, check, vat, avTurn, staff, area;
    char email[30];

    //Check Array for Next Available Array Entry
    for (int i = 0; i < 100; i++)
    {
        if ((*(client + i)).regNumber == -1)
        {
            //Register Number 
            do
            {
                //Reset Unique
                unique = 0;

                printf("\nPlease Enter Client Register Number: ");
                scanf("%d", &thisClient);

#pragma region CheckUniqueNumber
                //Check if number entered is unique
                for (int j = 0; j < 100; j++)
                {
                    if (thisClient == (*(client + j)).regNumber)
                    {
                        unique = -1;
                    }
                }

                if (unique == -1)
                {
                    printf("\n\nERROR!!!!!!!!!!!!!!");
                    printf("\nNot a unique Client Reg Number Entered\n");
                }

                else
                {
                    //Assign as it is unique
                    (*(client + i)).regNumber = thisClient;
                }

#pragma endregion

            } while (unique == -1);

            //Name
            printf("Please Enter Company Name: ");
            scanf("%s", (*(client + i)).name);

            //Company Country
            printf("Please Enter Companys Country: ");
            scanf("%s", (*(client + i)).country);

            //Year Founded
            printf("Please Enter Year Company was founded: ");
            scanf("%d", &(*(client + i)).yearFounded);

            //Email Address
            do
            {
                check = 0;
                printf("Please Enter Company Email: ");
                printf("\n(don't forget @ & .com)\nEmail: ");
                scanf("%s", email);

                //Check if email is entered correctly
                if (strstr(email, "@") == NULL || strstr(email, ".com") == NULL)
                {
                    printf("\n\nERROR!!!!");
                    printf("\nPlease enter a @ and .com");
                    check = -1;
                }
            } while (check == -1);

            strncpy((*(client + i)).email, email, 30);

            //Company Contact Name
            printf("Please Enter Company Contact Name: ");
            scanf("%s", &(*(client + i)).contactName);

            //Last Order
            printf("Please Enter Last Order Amount: ");
            scanf("%f", &(*(client + i)).lastOrder);

            //Number of Employees
            printf("Please Enter Number of Employees: ");
            scanf("%d", &(*(client + i)).numEmployees);

            //Average Annual Order
            printf("Please Enter Average Annual Order: ");
            scanf("%f", &(*(client + i)).averageAnnOrder);

            //Vat Registered
            printf("Is the Client Vat Registered (1: Yes 2:No)\nPlease Select: ");
            scanf("%d", &(*(client + i)).vatReg);

            //Client Average Turnover
            printf("What are the Clients Average Turnover (1: Less than 1 Mil 2: Less than 10 Mil 3: Over 10 Mil)\nPlease Select: ");
            scanf("%d", &(*(client + i)).avT);

            //Staff Employed
            printf("How many staff are employed (1: Less than 10 2: Less than 100 3: Over 100)\nPlease Select: ");
            scanf("%d", &(*(client + i)).emplo);

            //Which Area of Sales is the company
            printf("Which Area of Sales is the Company (1: ICT 2: Medical Devices 3: Other)\nPlease Select: ");
            scanf("%d", &(*(client + i)).comA);

            //Display Message 
            printf("New Client Added!");
            
            //Send User back to Menu
            Menu(client, generate);
        }
    }

}

//----------------------------------------------------------------------------
//Display All Clients
void DisplayAll(company* client, stats generate)
{
    for (int j = 0; j < 100; j++)
    {
#pragma region SetQuestions
        //Vat Reg
        if ((*(client + j)).vReg == 1)
        {
            strncpy((*(client + j)).vatReg, "Yes", 5);
        }
        else
        {
            strcpy((*(client + j)).vatReg, "No", 5);
        }

        //Average Turnover
        if ((*(client + j)).avT == 1)
        {
            strncpy((*(client + j)).avTurnover, "Less than 1 Mil", 25);
        }
        else if ((*(client + j)).avT == 2)
        {
            strncpy((*(client + j)).avTurnover, "Less than 10 Mil", 25);
        }
        else
        {
            strncpy((*(client + j)).avTurnover, "Over 10 Mil", 25);
        }

        //Staff
        if ((*(client + j)).emplo == 1)
        {
            strncpy((*(client + j)).staff, "Less than 10", 25);
        }
        else if ((*(client + j)).emplo == 2)
        {
            strncpy((*(client + j)).staff, "Less than 100", 25);
        }
        else
        {
            strncpy((*(client + j)).staff, "Over 100", 25);
        }

        //Area
        if ((*(client + j)).comA == 1)
        {
            strncpy((*(client + j)).area, "ICT", 25);
        }
        else if ((*(client + j)).comA == 2)
        {
            strncpy((*(client + j)).area, "Medical Devices", 25);
        }
        else
        {
            strncpy((*(client + j)).area, "Other Area", 25);
        }
#pragma endregion

        if ((*(client + j)).regNumber != -1)
        {
            //Display
            printf("\n----------------------------------------------------------");
            printf("\nClient Reg Number: %d\nName: %s\nCountry: %s", (*(client + j)).regNumber, (*(client + j)).name, (*(client + j)).country);
            printf("\nYear Founded: %d\nEmail: %s\nContact Name: %s", (*(client + j)).yearFounded, (*(client + j)).email, (*(client + j)).contactName);
            printf("\nLast Order: %.2f\nNumber of Employees: %d\nAverage Annual Order: %.2f", (*(client + j)).lastOrder, (*(client + j)).numEmployees, (*(client + j)).averageAnnOrder);
            printf("\nVat Registered: %s\nAverage Turnover: %s\nStaff: %s\nArea: %s", (*(client + j)).vatReg, (*(client + j)).avTurnover, (*(client + j)).staff, (*(client + j)).area);
        }
    }

    printf("\n\nAll Clients Displayed");

    Menu(client, generate);
}

//----------------------------------------------------------------------------
//Display Client
void DisplayClient(company* client, stats generate)
{
    //Declare Variables
    int reg;

    //Ask User which Company to print
    printf("Please Enter Reg Number of Company you wish to Display: ");
    scanf("%d", &reg);

    //Check for matching Reg
    for (int j = 0; j < 100; j++)
    {
#pragma region SetQuestions
        //Vat Reg
        if ((*(client + j)).vReg == 1)
        {
            strncpy((*(client + j)).vatReg, "Yes", 5);
        }
        else
        {
            strcpy((*(client + j)).vatReg, "No", 5);
        }

        //Average Turnover
        if ((*(client + j)).avT == 1)
        {
            strncpy((*(client + j)).avTurnover, "Less than 1 Mil", 25);
        }
        else if ((*(client + j)).avT == 2)
        {
            strncpy((*(client + j)).avTurnover, "Less than 10 Mil", 25);
        }
        else
        {
            strncpy((*(client + j)).avTurnover, "Over 10 Mil", 25);
        }

        //Staff
        if ((*(client + j)).emplo == 1)
        {
            strncpy((*(client + j)).staff, "Less than 10", 25);
        }
        else if ((*(client + j)).emplo == 2)
        {
            strncpy((*(client + j)).staff, "Less than 100", 25);
        }
        else
        {
            strncpy((*(client + j)).staff, "Over 100", 25);
        }

        //Area
        if ((*(client + j)).comA == 1)
        {
            strncpy((*(client + j)).area, "ICT", 25);
        }
        else if ((*(client + j)).comA == 2)
        {
            strncpy((*(client + j)).area, "Medical Devices", 25);
        }
        else
        {
            strncpy((*(client + j)).area, "Other Area", 25);
        }
#pragma endregion

        if ((*(client + j)).regNumber == reg)
        {
            //Display
            printf("\n----------------------------------------------------------");
            printf("\nClient Reg Number: %d\nName: %s\nCountry: %s", (*(client + j)).regNumber, (*(client + j)).name, (*(client + j)).country);
            printf("\nYear Founded: %d\nEmail: %s\nContact Name: %s", (*(client + j)).yearFounded, (*(client + j)).email, (*(client + j)).contactName);
            printf("\nLast Order: %.2f\nNumber of Employees: %d\nAverage Annual Order: %.2f", (*(client + j)).lastOrder, (*(client + j)).numEmployees, (*(client + j)).averageAnnOrder);
            printf("\nVat Registered: %s\nAverage Turnover: %s\nStaff: %s\nArea: %s", (*(client + j)).vatReg, (*(client + j)).avTurnover, (*(client + j)).staff, (*(client + j)).area);
        }
    }

    //Display Message
    printf("\nClient Displayed");

    //Menu
    Menu(client, generate);
}

//----------------------------------------------------------------------------
//Update Client
void UpdateClient(company* client, stats generate)
{
    //Declare Variables
    int reg, check, vat, avTurn, staff, area;
    char email[30];

    //Ask User which Company to Update
    printf("Please Enter Reg Number of Company you wish to Update: ");
    scanf("%d", &reg);

    //Check for matching Reg
    for (int i = 0; i < 100; i++)
    {
        if ((*(client + i)).regNumber == reg)
        {
            //Name
            printf("Please Enter Company Name: ");
            scanf("%s", (*(client + i)).name);

            //Company Country
            printf("Please Enter Companys Country: ");
            scanf("%s", (*(client + i)).country);

            //Year Founded
            printf("Please Enter Year Company was founded: ");
            scanf("%d", &(*(client + i)).yearFounded);

            //Email Address
            do
            {
                check = 0;
                printf("Please Enter Company Email: ");
                printf("\n(don't forget @ & .com)\nEmail: ");
                scanf("%s", email);

                //Check if email is entered correctly
                if (strstr(email, "@") == NULL || strstr(email, ".com") == NULL)
                {
                    printf("\n\nERROR!!!!");
                    printf("\nPlease enter a @ and .com");
                    check = -1;
                }
            } while (check == -1);

            strncpy((*(client + i)).email, email, 30);

            //Company Contact Name
            printf("Please Enter Company Contact Name: ");
            scanf("%s", &(*(client + i)).contactName);

            //Last Order
            printf("Please Enter Last Order Amount: ");
            scanf("%f", &(*(client + i)).lastOrder);

            //Number of Employees
            printf("Please Enter Number of Employees: ");
            scanf("%d", &(*(client + i)).numEmployees);

            //Average Annual Order
            printf("Please Enter Average Annual Order: ");
            scanf("%f", &(*(client + i)).averageAnnOrder);

            //Vat Registered
            printf("Is the Client Vat Registered (1: Yes 2:No)\nPlease Select: ");
            scanf("%d", &(*(client + i)).vReg);

            //Client Average Turnover
            printf("What are the Clients Average Turnover (1: Less than 1 Mil 2: Less than 10 Mil 3: Over 10 Mil)\nPlease Select: ");
            scanf("%d", &(*(client + i)).avT);

            //Staff Employed
            printf("How many staff are employed (1: Less than 10 2: Less than 100 3: Over 100)\nPlease Select: ");
            scanf("%d", &(*(client + i)).emplo);

            //Which Area of Sales is the company
            printf("Which Area of Sales is the Company (1: ICT 2: Medical Devices 3: Other)\nPlease Select: ");
            scanf("%d", &(*(client + i)).comA);

            //Display Message 
            printf("Client Updated!");

            //Menu
            Menu(client, generate);
        }
    }
}

//----------------------------------------------------------------------------
//Delete Client
void DeleteClient(company* client, stats generate)
{
    //Declare Variables
    int reg;

    //Ask User which Company to Delete
    printf("Please Enter Reg Number of Company you wish to Delete: ");
    scanf("%d", &reg);

    //Check for matching Reg
    for (int i = 0; i < 100; i++)
    {
        if ((*(client + i)).regNumber == reg)
        {
            //Reg Number
            (*(client + i)).regNumber = -1;

            //Reset All
            strncpy((*(client + i)).name, "", 20);
            strncpy((*(client + i)).country, "", 20);
            (*(client + i)).yearFounded = 0;
            strncpy((*(client + i)).email, "", 20);
            strncpy((*(client + i)).contactName, "", 20);
            (*(client + i)).lastOrder = 0.0;
            (*(client + i)).numEmployees = 0;
            (*(client + i)).averageAnnOrder = 0.0;
            strncpy((*(client + i)).vatReg, "", 5);
            strncpy((*(client + i)).avTurnover, "", 25);
            strncpy((*(client + i)).staff, "", 25);
            strncpy((*(client + i)).area, "", 25);
            (*(client + i)).avT = 0;
            (*(client + i)).vReg = 0;
            (*(client + i)).emplo = 0;
            (*(client + i)).comA = 0;
            (*(client + i)).check = 0;

            //Display Message 
            printf("Client Deleted!");

            //Menu
            Menu(client, generate);
        }
    }
}

//----------------------------------------------------------------------------
//Generate Statistics
void GenerateStats(company* client, stats generate)
{
    //Variables
    int choice, area, numE, count = 0;
    int a = 0, b = 0, c= 0;
    int lMil, l10Mil, mil10;
    
    //Select which to be completed by
    printf("Would you like stats done by 1. Area of Company or 2. Number of Employees");
    scanf("%d", &choice);
    generate.select1 = choice;

    //Area
    if (choice == 1)
    {
        //Reset
        a = 0; 
        b = 0; 
        c = 0;
        count = 0;

        printf("Next Selection 1. ICT 2. Medical Devices 3. Other");
        scanf("%d", &area);
        //generate.selection = area;

        for (int i = 0; i < 100; i++)
        {
            if ((*(client + i)).regNumber != -1)
            {
                if ((*(client + i)).comA == area)
                {
                    count++;

                    switch ((*(client + i)).avT)
                    {
                    case 1:
                        a++;
                        break;
                    case 2:
                        b++;
                        break;
                    case 3:
                        c++;
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        //Work Out Stats
        lMil = (a / count) ;
        l10Mil = (b / count) ;
        mil10 = (c / count) ;

        generate.less1 = lMil;
        generate.less10 = l10Mil;
        generate.mil10 = mil10;

        //Print Stats
        printf("\nThe Statistics are as Follows:");
        printf("\n-Less than 1 Million: %d %", lMil);
        printf("\n-Less than 10 Million: %d %", l10Mil);
        printf("\n-More than 10 Million: %d %", mil10);
    }

    //Num Employees
    if (choice == 2)
    {
        //Reset
        a = 0;
        b = 0;
        c = 0;
        count = 0;

        printf("Next Selection 1. Less than 10 2. Less than 100 3. More than 100");
        scanf("%d", &numE);
        generate.selection = numE;

        for (int i = 0; i < 100; i++)
        {
            if ((*(client + i)).regNumber != -1)
            {
                if ((*(client + i)).emplo == numE)
                {
                    count++;

                    switch ((*(client + i)).emplo)
                    {
                    case 1:
                        a++;
                        break;
                    case 2:
                        b++;
                        break;
                    case 3:
                        c++;
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        //Work Out Stats
        lMil = (a / count) * 100;
        l10Mil = (b / count) * 100;
        mil10 = (c / count) * 100;

        generate.less1 = lMil;
        generate.less10 = l10Mil;
        generate.mil10 = mil10;

        //Print Stats
        printf("\nThe Statistics are as Follows:");
        printf("\n-Less than 1 Million: %d %", lMil);
        printf("\n-Less than 10 Million: %d %", l10Mil);
        printf("\n-More than 10 Million: %d %", mil10);
    }

    

    //Done
    printf("\n\nStats Printed");

    //Menu
    Menu(client, generate);
}

//----------------------------------------------------------------------------
//Print to File
void PrintFile(company* client, stats generate)
{
    int hello = 3;
    //Object of File
    FILE* newFile;
    FILE* stats;

    //Open File to write to
    newFile = fopen("Clients.txt", "a");

    //Write to File
    for (int j = 0; j < 100; j++)
    {
        if ((*(client + j)).regNumber != -1)
        {
            //Display
            fprintf(newFile, "%d %s %s %d %s ", (*(client + j)).regNumber, (*(client + j)).name, (*(client + j)).country, (*(client + j)).yearFounded, (*(client + j)).email);
            fprintf(newFile, "%s %.2f %d %.2f ", (*(client + j)).contactName, (*(client + j)).lastOrder, (*(client + j)).numEmployees, (*(client + j)).averageAnnOrder);
            fprintf(newFile, "%s %s %s %s ", (*(client + j)).vatReg, (*(client + j)).avTurnover, (*(client + j)).staff, (*(client + j)).area);
            fprintf(newFile, "%d %d %d %d\n", (*(client + j)).vReg, (*(client + j)).avT, (*(client + j)).emplo, (*(client + j)).comA);
        }
    }

    fclose(newFile);

    //Stats File
    stats = fopen("Stats.txt", "w");

    //Write to File
    for (int j = 0; j < 100; j++)
    {
        if ((*(client + j)).regNumber != -1)
        {
            //Display
            fprintf(stats, "%d %d %d %d %d\n", generate.selection, generate.select1, generate.less1, generate.less10, generate.mil10);
        }
    }

    fclose(stats);

    //Menu
    Menu(client, generate);
}

//----------------------------------------------------------------------------
//List by Average Turnover
void ListByAvT(company* client, stats generate)
{
    //Variables
    int max, j, print;

    max = (*(client)).yearFounded;

    for (int k = 0; k < 100; k++)
    {
        print = 0;
        for (int i = 0; i < 100; i++)
        {
            if (max > (*(client + i)).yearFounded && (*(client + i)).check != 0)
            {
                max = (*(client + i)).yearFounded;
                j = i;
                print = 1;
            }
        }
        if (print == 1)
        {
            printf("\n----------------------------------------------------------");
            printf("\nClient Reg Number: %d\nName: %s\nCountry: %s", (*(client + j)).regNumber, (*(client + j)).name, (*(client + j)).country);
            printf("\nYear Founded: %d\nEmail: %s\nContact Name: %s", (*(client + j)).yearFounded, (*(client + j)).email, (*(client + j)).contactName);
            printf("\nLast Order: %.2f\nNumber of Employees: %d\nAverage Annual Order: %.2f", (*(client + j)).lastOrder, (*(client + j)).numEmployees, (*(client + j)).averageAnnOrder);
            printf("\nVat Registered: %s\nAverage Turnover: %s\nStaff: %s\nArea: %s", (*(client + j)).vatReg, (*(client + j)).avTurnover, (*(client + j)).staff, (*(client + j)).area);

        }
        
    }
}