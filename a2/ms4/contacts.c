/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 26 July 2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+

char ans;

// getName:
void getName(struct Name *name)
{
	//First
  printf("Please enter the contact's first name: ");
  scanf(" %[^\t\n]s", (*name).firstName);
  clearKeyboard();

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  if(yes())
  {
	  printf("Please enter the contact's middle initial(s): ");
	  scanf(" %[^\t\n]s", (*name).middleInitial);
	} else (*name).middleInitial[0] = '\0';

  printf("Please enter the contact's last name: ");
  scanf(" %[^\t\n]s", (*name).lastName);
}

// getAddress:
void getAddress(struct Address *address)
{
	//Street #
printf("Please enter the contact's street number: ");
(*address).streetNumber=getInt();

printf("Please enter the contact's street name: ");
scanf(" %[^\t\n]s", (*address).street);

printf("Do you want to enter an apartment number? (y or n): ");
if(yes())
{
  printf("Please enter the contact's apartment number: ");
  (*address).apartmentNumber = getInt();
}
else
(*address).apartmentNumber = '\0';

printf("Please enter the contact's postal code: ");
scanf(" %[^\t\n]s", (*address).postalCode);

printf("Please enter the contact's city: ");
scanf(" %[^\t\n]s", (*address).city);
}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
	//Cell
printf("Please enter the contact's cell phone number: ");
getTenDigitPhone((*numbers).cell);

printf("Do you want to enter a home phone number? (y or n): ");
if (yes())
{
  printf("Please enter the contact's home phone number: ");
  getTenDigitPhone((*numbers).home);
}
else
(*numbers).home[0]='\0';

printf("Do you want to enter a business phone number? (y or n): ");
if (yes())
{
  printf("Please enter the contact's business phone number: ");
  getTenDigitPhone((*numbers).business);
} else
(*numbers).business[0] = '\0';
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact){
  getName(&contact->name);
  getAddress(&contact->address);
  getNumbers(&contact->numbers);
}