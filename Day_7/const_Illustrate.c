#include <stdio.h>
/*******************************************************************************************
** Function Name: main											  					 	  ** 
** Inputs		: 1. argc        -- The number of parameters provided to the main function**
**				: 2. argv   	 -- The pointer to the input string array of parameters   **
** Variable		: const_variable -- Using for const variable                              **
** 				: g_variable   	 -- using for genaral variable 	 						  **
** Return		: = 0 	   		 -- Success 											  **
** 				: <	0	    	 -- Failed												  **
** Note			:Illustrate the usage of const										      **
*******************************************************************************************/

//main function
int main(int argc, char *argv[])
{
	const float const_variable = 3.14; //set variable as a const variable and assign a const value
	float g_variable = 13.5;
	printf("The Const variable is : %.2f\n", const_variable);
	printf("Non const variable is : %.2f\n", g_variable);
/*	
	const_variable = 9.8; //// Attempting to modify a constant variable will result in a compilation error
//	printf("The Const variable is : %.2f\n", const_variable);*/
}
