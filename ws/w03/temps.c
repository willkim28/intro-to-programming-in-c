// Name:           Woohyun Will Kim
// Student Number: 122733157
// Email:          wkim31@senecacollege.ca
// Section:        SKK
// Workshop:       03@Home

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4                                                   //Declare variable 'NUM' as 4 (AT_HOME change)

int main(void) {
	double high, low, avg = 0, lowest = 40, highest = -40;       //Declare variables for temperature (high&low) + variable for average calculation
	int days, highDay, lowDay;                                   //Declare variable days for iteration
	printf("---=== IPC Temperature Analyzer ===---\n");          //Display text prompt
	for (days = 0; days < NUMS; days++) {                        //For loop, iterating for each integer of 'days' until 'NUMS'
		printf("Enter the high value for day %d: ", days+1);     //Text prompt for entering high value, and then returns value of days+1 (since the value starts at 0)
		scanf("%lf",&high);                                      //Accepts the input value into variable 'high'
		printf("\n");                                            //Add new lines for format
		printf("Enter the low value for day %d: ", days + 1);    //Text prompt for entering low value
		scanf("%lf", &low);                                      //Accepts the input value into variable 'low'
		printf("\n");                                            //Add new lines for format
		if (high < -40 || high > 40 || low < -40 || low > 40 || low > high) {    //Sets conditions (numerical constraint) for the variables. high being lower than -40, and low being higher than 40 is redundant, but kept in for uniformity
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");  //Displays error message if condition is met and
			days--;                                                                                                       //Reverts the days iteration back, so that inputs prompts are iterated again
		}
		else {                         //If conditions are not met (done correctly)
			avg += (high + low) / 2;   //Adds the halved value of a sum of high and low of the current loop/iteration to variable 'avg'
      if (highest < high) {            //Condition check if 'highest' temperature is lower than current iteration's 'high'
        highest = high;                //Set variable 'highest' to current iteration's high temperature if above condition is met
        highDay = days + 1;            //Set day accordingly with +1
      }
      if (lowest > low) {              //Repeat of 'highest' but for 'lowest'
        lowest = low;
        lowDay = days + 1;
      }
		}
	}
	printf("The average (mean) temperature was: %.2lf\n", avg / NUMS);        //Displays the average temperature (total 'avg' (sum of temperature) divided by 'NUMS' (number of days), specified to 2 decimal places
    printf("The highest temperature was %.0lf, on day %d\n", highest, highDay); //Displays highest temperature, and the according date
    printf("The lowest temperature was %.0lf, on day %d\n", lowest, lowDay);    //Displays lowest temperature, and the according date
	return 0;
}