#include <stdio.h>
#include <stdlib.h>
/**************************************************************************************
** Function Name: main					  										     ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: temp_fahr -- The fahrenheit tempture value                         **
** 				: temp_celsi-- The Celsius tempture value							 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			: temperature conversion celsius to fahrenheit                       **
***************************************************************************************/
int main(int argc, char *argv[])
{
	float temp_fahr, temp_celsi; 			// declire the float variable for tempture
	int low_temp = 0, high_temp = 300, step_num = 20; // initialize the value
	printf("Celsius \t Fahrenheit\n"); 		// define table header
	printf("---------- \t --------\n");
	
	temp_celsi = low_temp;
	while(temp_celsi <= high_temp)
	{
		temp_fahr = (1.8*temp_celsi)+32; 	// celsius to fahrenheit formula
		printf("%.2f \t \t %.2f\n", temp_celsi, temp_fahr);
		temp_celsi = temp_celsi + step_num;
	}
	return 0;
}
