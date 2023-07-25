#include <stdio.h>
#include <stdbool.h>
/**************************************************************************************
** Function Name: main, temperature_conversion					  					 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: temp 		-- variable for tempture                                 **
** 				: low_temp	-- lowest value of tempture 0							 **
**				: high_temp -- 	highest value of temture 300						 **
**				: step_num	-- 	step is decrise by 20				 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:Temperature conversion program, using a function for conversion.	 **
***************************************************************************************/

/**tempture convater function both celsius to fahrenheit and fahrenheit to celsius 
** with declearing parameter**/
void temperature_conversion (int high_temp, int low_temp, int step_num, bool is_celsiTofahr) 
{
	float temp = low_temp; // declire the float variable for tempture
	
	/*using the ternary operator conditionally choose the appropriate string*/
	printf("%s\t%s\n", is_celsiTofahr ? "Celsius   " : "Fahrenheit", is_celsiTofahr ? "Fahrenheit" : "Celsius"); 
	printf("---------\t----------\n");
	while(temp <= high_temp)
	{
		if(is_celsiTofahr)
		{
			printf("%.2f\t\t%.2f\n", temp, (temp * 9 / 5) + 32); // celsius to fahrenheit formula 
		}else
		{
			printf("%.2f\t\t%.2f\n", temp, (temp - 32) * 5 / 9); // fahrenheit to celsius formula
		}
		temp += step_num;
	}
}

//Main Function
int main(int argc, char *argv[])
{
	temperature_conversion (300, 0, 20, true); // for  bool value true calculate Celsius to Fahrenheit
    printf("\n");
    temperature_conversion (300, 0, 20, true); //for  bool value false calculate Fahrenheit to Celsius
    return 0;
}
