#include <stdio.h>

//Set Up Structure
typedef struct
{
	char name[40];
	int companyReg, companyVAT;
	float averageSales[12];
}company;

void main()
{
	//Variables
	int input;
	float averSales, sales;

	//Ask user how many companys they wish to enter
	printf("Please Enter the amount of companies you wish to enter:\t");
	scanf("%d", &input);

	//Only need to display info dont need to store
	company company;

	//File 
	FILE* companyDetails;
	FILE* companyData;
	companyDetails = fopen("Companies.txt", "w");
	companyData = fopen("CompanyData.txt", "w");
	fclose(companyDetails);
	fclose(companyData);

	//Reading into group
	for (int i = 1; i <= input; i++)
	{
		sales = 0;
		averSales = 0;

		printf("Please Enter Company %ds Name:\t", i);
		scanf("%s", company.name); 

		printf("Please Enter Company %ds Registration Number:\t", i);
		scanf("%d", &company.companyReg);

		printf("Please Enter Company %ds VAT Number:\t", i);
		scanf("%d", &company.companyVAT);

		for (int j = 0; j < 12; j++)
		{
			printf("Please Enter Company %ds Average Sales for month %d:\t", i, (j+1));
			scanf("%f", &company.averageSales[j]);

			sales += company.averageSales[j];
		}

		averSales = sales / 12;

		//Display
		printf("\n\nCompanies Name: %s\nCompanies Reg: %d\nCompanies VAT Number: %d\nTotal Average Sales: %.2f\n\n", 
			company.name, company.companyReg, company.companyVAT, averSales);
	
		//Print to file for Human Reading
		companyDetails = fopen("Companies.txt", "a");

		fprintf(companyDetails, "Company %d\n  Name: %s\n  Reg Number: %d\n  VAT Number: %d\n  Total Average Sales: %.2f\n\n", 
			i, company.name, company.companyReg, company.companyVAT, averSales);
	
		fclose(companyDetails);

		//Print to File for Computer Reading
		companyData = fopen("CompanyData.txt", "a");
		fprintf(companyDetails, "%s\n%d\n%d\n%.2f\n",
			company.name, company.companyReg, company.companyVAT, averSales);
	}
}