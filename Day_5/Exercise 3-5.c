#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	reverse_char, int_to_char, int_to_array			    			 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: store_char[] 	-- arry of characters 				                     **
** 				: temp_char		-- Temporary characters store           				 **
**				: input_val	    -- 	Inputed value from user       						 **
**				: i,j		   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: Converting an integer to a string representation in the given base 	 **                               						 **
*******************************************************************************************/

/*Function to reverse the characters in a string */
void reverse_char(char store_char[])
{
	int i, j;
	char temp_char;
	/*Swap characters from the beginning and end of the string */
	for (i = 0, j = strlen(store_char) - 1; i < j; i++, j--)
	{
		temp_char = store_char[i];
		store_char[i] = store_char[j];
		store_char[j] = temp_char;
	}
}

/*Function to convert an integer value to a corresponding character in the given base */
char int_to_char(int input_val)
{
	if (input_val >= 0 && input_val <= 9)
	{
		return input_val + '0';
	}
	else if (input_val >= 10 && input_val <= 15)
	{
		return (input_val - 10) + 'A';
	}
	else
	{
		return '\0';
	}
}

/*Function to convert an integer to a string representation in the given base */
void int_to_array(int input_val, char store_char[], int base)
{
	int sign = input_val, i = 0;
	
	do
	{
		store_char[i++] = int_to_char(abs(input_val) % base); /// Convert remainder to character
		input_val /= base;
	}while (input_val != 0);
	
	if (sign < 0)
	{
		store_char[i++] = '-'; //assign "-" on the string for negative value
	}
	
	switch(base)
	{
		case 2:
			store_char[i++] = 'b'; // Append "b" for binary base
			store_char[i++] = '0';
			break;
		case 8:
			store_char[i++] = 'o'; // Append "o" for octal base
			break;
		case 16:
			store_char[i++] = 'x'; // Append "x" for hexadecimal base
			store_char[i++] = '0';
			break;
	}
	
	store_char[i] = '\0'; // Add null terminator to mark the end of the string
	reverse_char(store_char);
}

/*main function*/
int main(int argc, char *argv[])
{
	int input_val;
	char store_char[100] = ""; // Array to store the resulting string
	printf("Enter A Value: ");
	scanf("%d", &input_val);
	
	int_to_array(input_val, store_char, 16);
	printf("String Output for Hexadecimal: %s\n", store_char);
	
	int_to_array(input_val, store_char, 2);
	printf("String Output for Binary: %s\n", store_char);
	
	int_to_array(input_val, store_char, 8);
	printf("String Output for Octal: %s\n", store_char);
	
	int_to_array(input_val, store_char, 10);
	printf("String Output for Decimal: %s\n", store_char);
	return 0;
}
