/*
Name:
Student number:
Email:
Workshop:
Section:
Date:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2          //Define SIZE to be 2

// Declare Struct Employee 
struct emps {           //Declare 'emps' struct, containing two ints and one double
	int no;
	int age;
	double salary;
};

/* main program */
int main(void) {        //Start program

	int option = 0;     //Declare and initialize option variable to 0
	int empNo = 0;      //Declare and initialize empNo variable to 0, used for counting number of employees inputted

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct emps emp[SIZE] = {      //Declare an array of 'emps' struct, named 'emp' that hold 'SIZE' elements
		{ 0, 0, 0 },{ 0, 0, 0 }    //and initialize the variables to 0
	};
	int i = 0;                     //Declare and initialize loop count variable 'i' to 0
    
	printf("---=== EMPLOYEE DATA ===---\n");  //Display program name

	do {                                                  //Start do-while loop
		// Print the option list
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {      //Utilize switch for menu
		case 0:	// Exit the program
		printf("Exiting Employee Data Program. Good Bye!!!\n");  //Display exit message
			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");  //Print label row
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {             //Utilize for loop, while the incrementing 'i' is less than 'SIZE'
				printf("%6d%9d%11.2lf\n", emp[i].no, emp[i].age, emp[i].salary);  //and print each variable in struct array 'emp' for each 'i' value
			}
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 
			
			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:	// Adding Employee
				// @IN-LAB
				printf("Adding Employee\n");
				printf("===============\n");
				if (empNo < SIZE) {                //Allow access only when 'empNo' variable is less than 'SIZE'
				printf("Enter Employee ID: ");     //Print prompt for input for ID
				scanf("%d", &emp[empNo].no);       //And save into the current 'empNo' index for emp's 'no' variable
				printf("Enter Employee Age: ");    //Print prompt for input for Age
				scanf("%d", &emp[empNo].age);      //And save into the current 'empNo' index for emp's 'age' variable
				printf("Enter Employee Salary: "); //Print prompt for input for Salary
				scanf("%lf", &emp[empNo].salary);  //And save into the current 'empNo' index for emp's 'salary' variable
				empNo++;
			}
			else {       //If condition is not met (if 'empNo' is NOT less than 'SIZE'
				printf("ERROR!!! Maximum Number of Employees Reached\n"); //Print out error message
			}

			// Check for limits on the array and add employee 
			// data accordingly. 



			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");  //If none of the switch options are met, print this
		}

	} while (option != 0);        //Repeat switch while option is NOT 0


	return 0;  //End program
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
