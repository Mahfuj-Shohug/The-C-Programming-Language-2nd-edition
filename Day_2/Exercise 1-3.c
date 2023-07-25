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
** Note			:  Modifying the temperature conversion program table	             **
***************************************************************************************/
int main(int argc, char *argv[])
{
	float temp_fahr, temp_celsi;       // declire the float variable 
	int low_temp = 0, high_temp = 300, step_num = 20; // initialize the value
	printf("Fahrenheit \t Celsius\n"); // define table header
	printf("---------- \t --------\n");
	
	temp_fahr = low_temp;
	while(temp_fahr <= high_temp)
	{
		temp_celsi = 5*(temp_fahr-32)/9; // fahrenheite to celsius formula
		printf("%.2f \t \t %.2f\n", temp_fahr, temp_celsi);
		temp_fahr = temp_fahr + step_num;
	}
	return 0;
}
