/*
     Name:      Woohyun Will Kim 
     Student#:  122733157
     Section:   SKK
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double cashDouble;                                    //Declare variables
	int loonies, quarters, dimes, nickels, pennies;       //Declare currency as int since they do are always integer values

	printf("Please enter the amount to be paid: $");      //Text prompt for input
	scanf("%lf", &cashDouble);                            //Accepts input
	printf("GST: 1.13\n");                                //Display GST value
	cashDouble *= 1.13;                                   //Actually calculate GST value
	printf("Balance owing: $%.2lf\n", cashDouble);        //Display cash value after GST
	cashDouble = (cashDouble + 0.005);                    //Force rounding by adding 0.005

	loonies = cashDouble;                                 //Set loonies to cash value, since it is an integer the value gets truncated
	printf("Loonies required: %d, ", loonies);            //Display loonies required
	cashDouble -= loonies;                                //Subtract loonies from cash value
  printf("balance owing $%.2lf\n", cashDouble);         //Display remaining cash value, on the same line as loonies.

  cashDouble *= 100;                                    //Multiply cash by 100 for calculations
	quarters = (int) cashDouble / 25;                     //cast cash as int, then divide by 25 (produces same effect as 1/.25)
	printf("Quarters required: %d, ", quarters);          //Display quarter value from calculation
	cashDouble = (int) cashDouble % 25;                   //Cast cash as int, use remainder function to calculate remaining value
  cashDouble /= 100;                                    //Divide cash by 100
  printf("balance owing $%.2lf\n", cashDouble);         //Then display the value normally

  cashDouble *= 100;
	dimes = (int) cashDouble / 10;
	printf("Dimes required: %d, ", dimes);
	cashDouble = (int) cashDouble % 10;
  cashDouble /= 100;
  printf("balance owing $%.2lf\n", cashDouble);

  cashDouble *= 100;
	nickels = (int) cashDouble / 5;
	printf("Nickels required: %d, ", nickels);
	cashDouble = (int) cashDouble % 5;
  cashDouble /= 100;
  printf("balance owing $%.2lf\n", cashDouble);

  cashDouble *= 100;
	pennies = (int) cashDouble;                           //redundant, but kept for uniformity
	printf("Pennies required: %d, ", pennies);
	cashDouble = (int) cashDouble % 1;
  cashDouble /= 100;
  printf("balance owing $%.2lf\n", cashDouble);
	return 0;
}