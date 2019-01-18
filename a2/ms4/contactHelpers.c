/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 31 July 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
  while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void)
{
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// pause2 for formatting
void pause2(void)
{
  printf("(Press Enter to Continue)\n");
  clearKeyboard();
}

// getInt: Empty function definition goes here:

int getInt(void)
{
  char NL = 'x';
  int Value;

  do {
    scanf("%d%c", &Value, &NL);
    if (NL != '\n') {
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      clearKeyboard();
    }
  } while (NL != '\n');
  return Value;
}

// getIntInRange: Empty function definition goes here:

int getIntInRange(int min, int max)
{
  int i;
  i = getInt();
    while (i < min || i > max) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
      scanf("%d", &i);
    }
  return i;
}

// yes: Empty function definition goes here:
int yes(void)
{
  char a, NL = 'x';
  
  do {
    scanf(" %c%c", &a, &NL);
    if (NL != '\n') {
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      clearKeyboard();
    } else if (a == 'Y' || a == 'y') {
      return 1;
    } else if (a == 'N' || a == 'n') {
      return 0;
    }
  } while (NL != '\n');
  return 0;
}

// menu: Empty function definition goes here:

int menu(void){
  int option;
  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\nSelect an option:> ");

  option = getIntInRange(0, 6);
  printf("\n");
  return option;
}

// ContactManagerSystem: Empty function definition goes here:

void ContactManagerSystem(void){

  struct Contact cn[MAXCONTACTS] = {
    {
      {"Rick", {'\0'}, "Grimes"},
      {11, "Trailer Park", 0, "A7A 2J2", "King City"},
      {"4161112222", "4162223333", "4163334444"}
    },
    {
      {"Maggie", "R.", "Greene"},
      {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
      {"9051112222", "9052223333", "9053334444"}
    },
    {
      {"Morgan", "A.", "Jones"},
      {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
      {"7051112222", "7052223333", "7053334444"}
    },
    {
      {"Sasha", {'\0'}, "Williams"},
      {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
      {"9052223333", "9052223333", "9054445555"}
    },
  };
  int flag, exit = 0;
  do {
    int option = menu();

    switch (option){
      case 1:
      displayContacts(cn, MAXCONTACTS);
      pause2();
      break;

      case 2:
      addContact(cn, MAXCONTACTS);
      pause2();
      break;
  
      case 3:
      updateContact(cn, MAXCONTACTS);
      pause2();
      break;
      
      case 4:
      deleteContact(cn, MAXCONTACTS);
      pause2();
      break;
  
      case 5: 
      searchContacts(cn, MAXCONTACTS);
      pause2();
      break;
      
      case 6:
      sortContacts(cn, MAXCONTACTS);
      pause2();
      break;

      case 0: 
      printf("Exit the program? (Y)es/(N)o: ");
      flag = yes();
      if (flag == 1)
      {
        printf("\nContact Management System: terminated\n");
        exit = 1;
        } if (flag == 0)
        {
		  printf("\n");
          break;
        }
    }
  } while (exit == 0);
}

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact cn[], int size, const char cellNum[])
{
  int i;
  int value = -1;
  for(i = 0; i < size; i++){
    if (strcmp(cn[i].numbers.cell, cellNum) == 0){
      value = i;
    }
  }
    return value;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void){
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int x){
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", x);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* cn) {
	printf(" %s ", (*cn).name.firstName);
	if (strlen((*cn).name.middleInitial) > 0) {
		printf("%s ", (*cn).name.middleInitial);
	}
	printf("%s\n", (*cn).name.lastName);
	printf("    C: %s   ", (*cn).numbers.cell);
	if (strlen((*cn).numbers.home) > 0) {
		printf("H: %s   ", (*cn).numbers.home);
	}
	else {
		printf("H:              ");
	}
	if (strlen((*cn).numbers.business) > 0) {
		printf("B: %s\n", (*cn).numbers.business);
	}
	else {
		printf("B:           ");
		printf("\n");

	}
	printf("       %d ", (*cn).address.streetNumber);
	printf("%s, ", (*cn).address.street);
	if ((*cn).address.apartmentNumber > 0) {
		printf("Apt# %d, ", (*cn).address.apartmentNumber);
	}
	printf("%s, ", (*cn).address.city);
	printf("%s\n", (*cn).address.postalCode);
};

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact cn[], int size){
  int i, j = 0;
  displayContactHeader();
  for (i = 0; i < size; i++){
    if (strlen(cn[i].numbers.cell) > 0){
      displayContact(&cn[i]);
      j++;
    }
  }
  displayContactFooter(j);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact cn[], int size){
  char num[11];
  int b;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(num);
  b = findContactIndex(cn, size, num);
  if (b != -1){
    printf("\n");
    displayContact(&cn[b]);
    printf("\n");
  }
  else printf("*** Contact NOT FOUND ***\n");
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact cn[], int size){
  int i = 0, j = 0;
  for (i = 0; i < size; i++){
    if (strlen(cn[i].numbers.cell) == 0){
      j = i;
    }
  }
  if (j > 0) {
    getContact(&cn[j]);
    printf("--- New contact added! ---\n");
  }
  else {
    printf("*** ERROR: The contact list is full! ***\n");
  }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact cn[],int size){
  char num[11];
  int i;
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(num);
  i = findContactIndex(cn, size, num);
  if (i == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  
  else {
    printf("\nContact found:\n");
    displayContact(&cn[i]);
    printf("\n");

    printf("Do you want to update the name? (y or n): ");
    if (yes() == 1) {
      getName(&cn[i].name);
    }

    printf("Do you want to update the address? (y or n): ");
    if (yes() == 1) {
      getAddress(&cn[i].address);
    }

    printf("Do you want to update the numbers? (y or n): ");
    if (yes() == 1) {
      getNumbers(&cn[i].numbers);
    }
    printf("--- Contact Updated! ---\n");
  }

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact cn[], int size){
  char num[11];
  int i;
  
  printf("Enter the cell number for the contact: ");
  getTenDigitPhone(num);
  i = findContactIndex(cn, size, num);
  if (i == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  else {
    printf("\nContact found:\n");
    displayContact(&cn[i]);
    printf("\nCONFIRM: Delete this contact? (y or n): ");
    if (yes() == 1) {
      *cn[i].numbers.cell = '\0';
      *cn[i].numbers.home = '\0';
      printf("--- Contact deleted! ---\n");
    }
  }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact cn[], int size) {
	int i, j;
	struct Contact temp = { {{0}} };

	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(cn[j].numbers.cell, cn[j + 1].numbers.cell) > 0) {
				temp = cn[j];
				cn[j] = cn[j + 1];
				cn[j + 1] = temp;

			}
		}
	}

	printf("--- Contacts sorted! ---\n");
}