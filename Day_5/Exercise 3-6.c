#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	reverse_char, int_to_array						    			 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: store_char[] 	-- arry of characters 				                     **
** 				: temp_char		-- Temporary characters store           				 **
**				: input_val	    -- 	Inputed value from user       						 **
**				: i,j		   	-- 	loop variable						 				 **
**				: char_width	-- Minimum width of the string							 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: The converted number must be padded with blanks on the				 **
**				: left if necessary to make it wide enough	 							 **                               						 **
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

/*Function to convert an integer to a string with minimum width */
void int_to_array(int input_val, int char_width, char store_char[])
{
	int sign = input_val, i = 0;
	
	i = 0;
	do
	{
		store_char[i++] = abs(input_val % 10) + '0'; // Convert int value to absolute and convert to char
		input_val /= 10;
	}while (input_val != 0);
	
	if (sign < 0)
	{
		store_char[i++] = '-'; //assign "-" on the string for negative value
	}
	 // Pad the string with blanks on the left to meet the minimum width
	while (i < char_width)
	{
		store_char[i++] = ' ';
	}
	store_char[i] = '\0';
	reverse_char(store_char);
}

int main(int argc, char *argv[])
{
	char store_char[100] = ""; // Array to store the resulting string
	int input_val, char_width;
	
 	printf("Enter the minimum width of the string: ");
    scanf("%d", &char_width);
    printf("Enter an integer value: ");
    scanf("%d", &input_val);
	
	int_to_array(input_val, char_width, store_char);
	printf("String Output: %s\n", store_char);
	return 0;
}
