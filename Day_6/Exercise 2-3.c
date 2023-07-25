#include <stdio.h>
#include <ctype.h>
/******************************************************************************************
** Functions    : main,	hexa_ot_int												     	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_str[] 	-- arry of characters 				                     **
** 				: int_result	-- Decimal Result		      							 **
**				: i,j		   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: converts a string of hexadecimal digits into its equivalent integer value                                						 **
*******************************************************************************************/
//Hexa to int function
int hexa_ot_int(char input_str[])
{
	int int_result = 0, i = 0;
	
	//skip optional 0x or 0X
	if (input_str[i] == '0' && (tolower(input_str[i+1]) == 'x'))
	{
		i +=2;
	}
	
	// process each hexa degit
	while (input_str[i] != '\0')
	{
		char update_char = tolower(input_str[i]); // uppercase alphabetic characters to lowercase
		
		// is character represents a digit
		if (isdigit(update_char))
		{
			int_result = int_result * 16 + (update_char - '0');	// Decimal to hexa formula
		}
		else if (update_char >= 'a' && update_char <= 'f')
		{
			int_result = int_result * 16 + (update_char - 'a' + 10); // Decimal to Hexa formula abouve 10 A to F
		}
		else
		{
			// Invalid character worning
			printf("Your are input invalid Character: %c\n", input_str[i]);
			return -1;
		}
		
		i++;
	}
	
	return int_result;
}

//Main function
int main(int argc, char *argv[])
{
	char hexa_str[100];
	printf("Enter your Hexadecimal String: ");
	scanf("%s", &hexa_str);
	
	printf("\nYour Hexadecimal String: %s\n", hexa_str);
	printf("\nEquivalent decimal value: %d", hexa_ot_int(hexa_str));
	
	return 0;
}
