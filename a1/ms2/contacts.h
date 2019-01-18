/* -------------------------------------------
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Section: K
Date: 21/06/2018
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */

// Structure type Name declaration
struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address
{
	unsigned int streetNumber;      //
	char street [41];
	unsigned int apartmentNumber;
	char postalCode [8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...
struct Numbers
{
	char cell [21];
	char home [21];
	char business [21];
};