#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* NEXT;
}nodeT;

void displayList(nodeT);

main()
{
	nodeT* headPtr = NULL; //indicates that the list is empty..
	int choice, length = 0, search, found = -1;
	nodeT* newNode;
	nodeT* temp;

	printf("1: Add Element to Start of List\t\t2:Add Element to End of List\t\t3: Display List\n4: Delete an Item from List\t\t5: Display the Length of List\t\t6: Search List\t\t-1: Exit\nPlease Enter Choice: ");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			newNode = (nodeT*)malloc(sizeof(nodeT));

			//Populating the new node
			printf("\nPlease Enter the Nodes Value:");
			scanf("%d", &newNode->data);

			//Collecting it into the list
			newNode->NEXT = headPtr;
			headPtr = newNode;
		}

		else if (choice == 2)
		{
			if (headPtr == NULL)
			{
				newNode = (nodeT*)malloc(sizeof(nodeT));

				//Populating the new node
				printf("\nPlease Enter the Nodes Value:");
				scanf("%d", &newNode->data);

				//Collecting it into the list
				newNode->NEXT = headPtr;
				headPtr = newNode;
			}

			newNode = (nodeT*)malloc(sizeof(nodeT));

			//Populating the new node
			printf("\nPlease Enter the Nodes Value:");
			scanf("%d", &newNode->data);

			//Collecting it into the list
			temp = headPtr;

			while (temp->NEXT != NULL)
			{
				temp = temp->NEXT;
			}

			temp->NEXT = newNode;
			newNode->NEXT = NULL;
		}

		else if (choice == 3)
		{
			displayList(headPtr);
		}

		else if (choice == 4)
		{

		}

		else if (choice == 5)
		{
			temp = headPtr;

			while (temp != NULL)
			{
				length++;
				temp = temp->NEXT;
			}
			printf("\nLength of List is %d\n", length);
		}

		else if (choice == 6)
		{
			searchList(headPtr);
		}

		printf("\n1: Add Element to Start of List\t\t2:Add Element to End of List\t\t3: Display List\n4: Delete an Item from List\t\t5: Display the Length of List\t\t6: Search List\t\t-1: Exit\nPlease Enter Choice: ");
		scanf("%d", &choice);
	}
}

void displayList(nodeT* top)
{
	nodeT* temp = top;

	while (temp != NULL)
	{
		printf("1. Value of this Node is %d\n", temp->data);
		temp = temp->NEXT;
	}
}

void searchList(nodeT* headPtr)
{
	nodeT* temp = headPtr;
	int length = 1, found = 0, search;

	printf("Please Enter Int you want to Search for: ");
	scanf("%d", &search);

	while (temp != NULL && found != 1)
	{
		if (search == temp->data)
		{
			found = 1;
			printf("\nInt %d has been found at Location %d\n", search, length);
		}

		length++;
		temp = temp->NEXT;
	}

	if (found == 0)
	{
		printf("\nInt %d was not found\n", search);
	}
}