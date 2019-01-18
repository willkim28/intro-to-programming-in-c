/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 24 July 2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
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
    scanf("%c%c", &a, &NL);
    if (NL != '\n') {
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      clearKeyboard();
    } else if (a == 'Y' || a == 'y') {
      return 1;
    } else if (a == 'N' || a == 'n')
    {
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

  scanf("%d",&option);
  while (option < 0 || option > 6)
  {
    printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
    scanf("%d", &option);
  }
  return option;
}

// ContactManagerSystem: Empty function definition goes here:

void ContactManagerSystem(void){
  int option = 1;
  int flag, exit = 0;
  do {
    option = menu();
    switch (option){
      case 1:
      printf("\n<<< Feature 1 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;

      case 2:
      printf("\n<<< Feature 2 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;
  
      case 3:
      printf("\n<<< Feature 3 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;
      
      case 4:
      printf("\n<<< Feature 4 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;
  
      case 5: 
      printf("\n<<< Feature 5 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;
      
      case 6:
      printf("\n<<< Feature 6 is unavailable >>>\n\n");pause2();clearKeyboard();
      break;

      case 0: 
      printf("\nExit the program? (Y)es/(N)o: ");
      clearKeyboard();
      flag = yes();
      printf("\n");
      if (flag == 1)
      {
        printf("Contact Management System: terminated\n");
        exit = 1;
        } if (flag == 0)
        {
          break;
        }
    }
  } while (exit == 0);
}