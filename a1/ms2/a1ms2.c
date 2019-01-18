/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 10 July 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

;
int main(void) {
    // Declare variables here:
struct Name name = {{0}};
struct Address address = {0};
struct Numbers no = {{0}};
char ans;
    // Display the title
printf("Contact Management System\n");
printf("-------------------------\n");

    // Contact Name Input:
printf("Please enter the contact's first name: ");
scanf(" %[^\t\n]s", name.firstName);
printf("Do you want to enter a middle initial(s)? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's middle initial(s): ");
  scanf(" %[^\t\n]s", name.middleInitial);
  ans = '\0';
}

printf("Please enter the contact's last name: ");
scanf(" %[^\t\n]s", name.lastName);

    // Contact Address Input:
printf("Please enter the contact's street number: ");
scanf("%u" ,&address.streetNumber);
printf("Please enter the contact's street name: ");
scanf(" %[^\t\n]s", address.street);
printf("Do you want to enter an appartment number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's appartment number: ");
  scanf("%u", &address.apartmentNumber);
  ans = '\0';
}

printf("Please enter the contact's postal code: ");
scanf(" %[^\t\n]s", address.postalCode);
printf("Please enter the contact's city: ");
scanf(" %[^\t\n]s", address.city);
    // Contact Numbers Input:
printf("Do you want to enter a cell phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's cell phone number: ");
  scanf(" %[^\t\n]s", no.cell);
  ans = '\0';
}

printf("Do you want to enter a home phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's home phone number: ");
  scanf(" %[^\t\n]s", no.home);
  ans = '\0';
}

printf("Do you want to enter a business phone number? (y or n): ");
scanf(" %c", &ans);
if (ans == 'y' || ans ==  'Y'){
  printf("Please enter the contact's business phone number: ");
  scanf(" %[^\t\n]s", no.business);
  ans = '\0';
}

    // Display Contact Summary Details
printf("\nContact Details");
printf("\n---------------\n");
printf("Name Details\n");
printf("First name: %s\n", name.firstName);
printf("Middle initial(s): %s\n", name.middleInitial);
printf("Last name: %s\n", name.lastName);

printf("\nAddress Details\n");
printf("Street number: %d\n", address.streetNumber);
printf("Street name: %s\n", address.street);
printf("Apartment: %d\n", address.apartmentNumber);
printf("Postal code: %s\n", address.postalCode);
printf("City: %s\n", address.city);

printf("\nPhone Numbers:\n");
printf("Cell phone number: %s\n", no.cell);
printf("Home phone number: %s\n", no.home);
printf("Business phone number: %s\n", no.business);
    // Display Completion Message
printf("\nStructure test for Name, Address, and Numbers Done!\n");


    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/