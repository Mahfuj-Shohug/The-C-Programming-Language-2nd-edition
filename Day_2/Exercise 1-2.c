#include <stdio.h>
#include <stdlib.h>
/***********************************************************************************/
/* Function Name: main					  										   */
/* Inputs		: 1. argc -- The number of parameters provided to the main function*/
/*				: 2. argv -- The pointer to the input string array of parameters   */
/* Return		: = 0 	  -- Success 											   */
/* 				: <	0	  -- Failed												   */
/* Note			: A common hello with "escape sequence" instance for C language    */
/*				: Output a string Hello World with diffrent escape sequence		   */
/***********************************************************************************/
int main(int argc, char *argv[])
{
	printf("Hello,\c World!");
	return 0;
}
