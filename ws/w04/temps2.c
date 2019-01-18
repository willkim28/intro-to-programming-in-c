//--------------------------------------------------
// Name:           Woohyun Will Kim
// Student Number: 122733157
// Email:          wkim31@senecacollege.ca
// Section:        SKK
// Workshop:       04@Home
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>

int main(void) {  //Start program
	double avg = 0;
	int days, daysInput, avgInput, high[10], low[10], highDay, lowDay, lowest = 40, highest = -40; //Declare variables
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");  //Print name of program
  printf("Please enter the number of days, between 3 and 10, inclusive: ");  //Print prompt for # of days

  do {  //Start 'do while' loop
    scanf("%d",&daysInput);  //Accept input for # of days
    if (daysInput < 3 || daysInput > 10) {  //Check condition to see if input is NOT between 3 and 10
      printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");  //Print error message, and prompt
    }
  } while (daysInput < 3 || daysInput > 10);  //Repeat while condition is met

  printf("\n");

  for (days = 0; days < daysInput; days++) {  //Iterate for every integer between 0 and var 'daysInput'
    printf("Day %d - High: ", days + 1);  //Print out each day for High input
    scanf("%d", &high[days]);  //Accept input into the appropriate index in array 'high'
    printf("Day %d - Low: ", days + 1);  //Print out each day for Low input
    scanf("%d", &low[days]);  //Accept input into the appropriate index in array 'low'
    if (highest < high[days]) {  //Condition check if 'highest' temperature is lower than current iteration's 'high'
      highest = high[days];  //If condition is met, set 'highest' to current 'high'
      highDay = days + 1;  //And set highDay to current 'days'+1
    }
    if (lowest > low[days]) {  //Condition check if 'lowest' temperature is lower than current iteration's 'low'
      lowest = low[days];  //If condition is met, set 'lowest' to current 'low'
      lowDay = days + 1;  //And set lowDay to current 'days'+1
    }
  }

  printf("\nDay  Hi  Low\n");  //New line breaks for formatting, lay out the first&label row of table
  for (days = 0; days < daysInput; days++) {  //For loop, iterating for ever integer of 'days' until 'daysInput'
  printf("%d    %d    %d\n", days+1, high[days], low[days]);  //Prints out values of 'days'+1, and the relevant index value of 'high' and 'low'
  }
  
  printf("\nThe highest temperature was %d, on day %d\n", highest, highDay);  //Print out the highest temerature, and the day it was on
  printf("The lowest temperature was %d, on day %d\n", lowest, lowDay);  //Print out the lowest temperature, and the day it was on

  do {  //Start do-while loop
    printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", daysInput);  //Print prompt to enter a number
    scanf("%d", &avgInput);  //Accept input into var 'avgInput'
    while (avgInput > daysInput) {  //While 'avgInput' is greater than 'daysInput'
      printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", daysInput);  //Print error message
      scanf("%d", &avgInput);  //And reprompt
    }
    for (days = 0; days < avgInput; days++) {  //Iterate for every integer of 'days' until 'avgInput'
      avg += ((double)high[days] + (double)low[days])/2;  //Add the values of 'high' and 'low' of the index (casted to double for compatibility with 'avg' variable) divided by 2 to var 'avg'
    }
    if (avgInput >= 0) {  //If 'avgInput' is greater than 0,
      printf("\nThe average temperature up to day %d is: %.2lf\n", avgInput, avg / avgInput);  //Print out the avg temperature for the range of days chosen
      avg = 0;  //Reset var 'avg' for recalculation
      } else if (avgInput < 0) {  //If 'avgInput' is less than 0
      printf("\nGoodbye!\n");  //Print exit message
    }
  } while (avgInput > 0);  //Repeat while 'avgInput' is greater than 0
  return 0;  //Exit program
}