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

//Contact
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

//Name
void getName(struct Name * name);

//Address
void getAddress(struct Address *);

//Numbers
void getNumbers(struct Numbers *);