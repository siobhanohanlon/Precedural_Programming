//Siobhan O Hanlon
//G00389108
#include <stdio.h>

void main()
{
	//Declare Variables
	int numEmployees, taxNum, companyCars=0;
	float salary, carValue, mileage, salMax;
	float paye, benefitInKind, totalTaxLiability;
	float taxBill = 0, highestWage = 0, employeeHWage;

	//Ask user to enter number of employees- This is used in loop
	printf("Enter Number of Employees in Company\t");
	scanf("%d", &numEmployees);

	//If No Number Given
	if(numEmployees <= 0)
	{
		printf("\n\n******************************************************************************");
		printf("\n\nERROR: No details entered!!!!!");
		printf("\n\n******************************************************************************\n\n");
	}

	//If Int Given
	else
	{
		//For loop to ask and display employee details
		for (int i = 1; i <= numEmployees; i++)
		{
			//Tax Number
			printf("\nEnter Employee Tax Number\t\t\t\t");
			scanf("%d", &taxNum);

			//Salary
			printf("Enter Employee Annual Salary\t\t\t\t");
			scanf("%f", &salary);

			//Highest Wage
			if (salary > highestWage)
			{
				//Save Employee Details
				employeeHWage = taxNum;
				highestWage = salary;
			}

			//Calculate PAYE
			#pragma region PAYE

			//First 12,000 - 0%
			if (salary <= 12000)
			{
				paye = 0;
			}

			//Between 12,000 & 35,000 - 20%
			else if (12000 < salary && salary <= 35000)
			{
				paye = (salary - 12000) * 0.2;
			}

			//Over 35,000 - 40%
			else if (salary > 35000)
			{
				salMax = salary - 35000;
				paye = ((23000 * 0.2) + (salMax * 0.4));
			}
			#pragma endregion

			//Company Car Valuation
			printf("Enter Employee Company Car Valuation and Mileage:\t");
			scanf("%f %f", &carValue, &mileage);

			//Car Value - Over €40,000
			if (carValue > 40000)
			{
				companyCars++;
			}

			//Calculate Benefit in Kind
			#pragma region BenefitInKind

			//24,000 or Under - 30%
			if (mileage <= 24000)
			{
				benefitInKind = (carValue * 0.3);
			}

			//Between 24,000 & 32,000 - 24%
			else if (24000 < mileage && mileage <= 32000)
			{
				benefitInKind = (carValue * 0.24);
			}

			//Between 32,000 & 40,000 - 18%
			else if (32000 < mileage && mileage <= 40000)
			{
				benefitInKind = (carValue * 0.18);
			}

			//Between 40,000 & 48000 - 12%
			else if (40000 < mileage && mileage <= 48000)
			{
				benefitInKind = (carValue * 0.12);
			}

			//Over 48,000 - 6%
			else if (mileage > 48000)
			{
				benefitInKind = (carValue * 0.06);
			}
			#pragma endregion

			//Employee Total Tax Liability
			totalTaxLiability = paye + benefitInKind;

			//Total Tax
			taxBill += totalTaxLiability;

			//Display Employee Details
			printf("\nEmployee Number:\t%d\nPAYE Liability:\t\t%.2f", taxNum, paye);
			printf("\nBenefit In Kind:\t%.2f\nTotal Tax Liability:\t%.2f\n", benefitInKind, totalTaxLiability);
		}//End of For Loop

		//Display Data Collected
		printf("\n\nTotal Company Tax Bill:\t\t\t\t\t%.2f", taxBill);
		printf("\nTotal Number of Cars Valued Over 40,000 for Company:\t%d", companyCars);
		printf("\nEmpoyee with Highest Wage is:\t\t\t\t%d\twith %.2f\n\n\n", taxNum, highestWage);
	}//End of If Statement
}//End of Main