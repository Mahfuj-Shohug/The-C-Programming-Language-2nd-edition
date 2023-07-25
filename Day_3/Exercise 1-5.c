#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**************************************************************************************
** Function Name: main, tempConveter					  						     ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: temp 		-- variable for tempture                                 **
** 				: low_temp	-- lowest value of tempture 0							 **
**				: high_temp -- 	highest value of temture 300						 **
**				: step_num	-- 	step is decrise by 20				 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			: temperature conversion, print the tables in reverse order(300 to 0)**
***************************************************************************************/

/*tempture convater function both celsius to fahrenheit and fahrenheit to celsius with declearing parameter*/
int tempConveter(int high_temp, int low_temp, int step_num, bool is_celsiTofahr) 
{
	float temp; // declire the float variable for tempture
	
	/*using the ternary operator conditionally choose the appropriate string*/
	printf("%s\t%s\n", is_celsiTofahr ? "Celsius   " : "Fahrenheit", is_celsiTofahr ? "Fahrenheit" : "Celsius"); 
	printf("---------\t----------\n");
	for(temp = high_temp; temp >= low_temp; temp -= step_num)
	{
		if(is_celsiTofahr)
		{
			printf("%.2f\t\t%.2f\n", temp, (temp * 9 / 5) + 32); // celsius to fahrenheit formula 
		}else
		{
			printf("%.2f\t\t%.2f\n", temp, (temp - 32) * 5 / 9); // fahrenheit to celsius formula
		}
	}
}
int main(int argc, char *argv[])
{
	tempConveter(300, 0, 20, true); // for  bool value true calculate Celsius to Fahrenheit
    printf("\n");
    tempConveter(300, 0, 20, false); //for  bool value false calculate Fahrenheit to Celsius
    return 0;
}
