/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 17 July 2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:

char ans;  //Flag for 'y' and 'Y' check

void getName(struct Name* name) {
	//First
printf("Please enter the contact's first name: ");
scanf(" %[^\t\n]s", (*name).firstName);
printf("Do you want to enter a middle initial(s)? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's middle initial(s): ");
  scanf(" %[^\t\n]s", (*name).middleInitial);
  ans = '\0';  //Reset flag value
}

printf("Please enter the contact's last name: ");
scanf(" %[^\t\n]s", (*name).lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* address) {
	//Street #
printf("Please enter the contact's street number: ");
scanf("%u" ,&(*address).streetNumber);  //Since it is an unsigned integer, pointer w %u, and get address
printf("Please enter the contact's street name: ");
scanf(" %[^\t\n]s", (*address).street);  // [^\t\n]s ignores tabs and whitespace
printf("Do you want to enter an apartment number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's apartment number: ");
  scanf("%u", &(*address).apartmentNumber);
  ans = '\0';
}

printf("Please enter the contact's postal code: ");
scanf(" %[^\t\n]s", (*address).postalCode);
printf("Please enter the contact's city: ");
scanf(" %[^\t\n]s", (*address).city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {
	//Cell
printf("Do you want to enter a cell phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){  //Check for both case 'y' and 'Y'
  printf("Please enter the contact's cell phone number: ");
  scanf(" %[^\t\n]s", (*numbers).cell);
  ans = '\0';
}

printf("Do you want to enter a home phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's home phone number: ");
  scanf(" %[^\t\n]s", (*numbers).home);
  ans = '\0';
}

printf("Do you want to enter a business phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's business phone number: ");
  scanf(" %[^\t\n]s", (*numbers).business);
  ans = '\0';
}
}