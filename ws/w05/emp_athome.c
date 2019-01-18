/*
Name: Woohyun Will Kim
Student number: 122733157
Email: wkim31@myseneca.ca
Workshop: 05@Home
Section: K
Date: 19/06/2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4          //Define SIZE to be 4

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
		{0}    //and initialize the variables to 0
	};
	int i = 0;                     //Declare and initialize loop count variable 'i' to 0
    
	printf("---=== EMPLOYEE DATA ===---\n");  //Display program name

	do {                                                  //Start do-while loop
		// Print the option list
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
    printf("3. Update Employee Salary\n");
    printf("4. Remove Employee\n");
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
      if (emp[i].no > 0){  //Only display while the 'no' variable (could be others too, but simplicity) is greater than 0
				printf("%6d%9d%11.2lf\n", emp[i].no, emp[i].age, emp[i].salary);  //and print each variable in struct array 'emp' for each 'i' value
      }
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
			if (empNo < SIZE) {                    //Allow access only when 'empNo' variable is less than 'SIZE'
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
    int empNoInput = 0;  //Declare and initialize variable to keep track of employee number input
    case 3:
      printf("Update Employee Salary\n");
      printf("======================\n");
      int flag = 0;  //Flag for exit
      do {  //Start do-while loop
        printf("Enter Employee ID: ");  //Print prompt for input
        scanf("%d",&empNoInput);  //Save input into variable
        for (i = 0; i < empNo; i++)  //For loop, go through each i
        {
          if (empNoInput == emp[i].no)  //Nest IF within to check if input matches index element
          {
            printf("The current salary is %.2lf\n", emp[i].salary);  //Once matched, print the salary
            printf("Enter Employee New Salary: ");
            scanf("%lf", &emp[i].salary);  //Then accept a new input (overwrite) for the salary
            flag = 1;  //Then exit
            break;
          }
        }
      } while (flag == 0);  //Keep going while flag is 0

      break;
    case 4:
      printf("Remove Employee\n");
      printf("===============\n");
      flag = 0;
      do {  //Start do-while loop
        printf("Enter Employee ID: ");  //Print prompt
        scanf("%d",&empNoInput);  //Accept prompt
        for (i = 0; i < empNo; i++)  //Same structure as case 3
        {
          if (empNoInput == emp[i].no)
          {
            printf("Employee %d will be removed\n", emp[i].no);  //But this case will overwrite the index elements with 0
            emp[i].no = 0;
            emp[i].age = 0;
            emp[i].salary = 0;
            flag = 1;  //Then exits
            break;
          }
        }
      } while (flag == 0);
      break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n");  //If none of the switch options are met, print this
		}

	} while (option != 0);        //Repeat switch while option is NOT 0


	return 0;  //End program
}