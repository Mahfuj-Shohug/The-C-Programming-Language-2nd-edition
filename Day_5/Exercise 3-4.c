#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	reverse_char, int_to_array_book, int_to_array_updated       	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: store_char[] 	-- arry of characters 				                     **
** 				: temp_char		-- Temporary characters store           				 **
**				: input_val	    -- 	Inputed value from user       						 **
**				: i,j		   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: Modify it to print that value correctly, regardless of the machine on  **
**				  which it runs.                                 						 **
*******************************************************************************************/
/*Function to reverse the characters in a string */
void reverse_char(char store_char[])
{
	int i, j;
	char temp_char;
	// Swap characters from the beginning and end of the string
	for (i = 0, j = strlen(store_char) - 1; i < j; i++, j--)
	{
		temp_char = store_char[i];
		store_char[i] = store_char[j];
		store_char[j] = temp_char;
	}
}

/*Function to convert an integer to string which on given the book */
void int_to_array_book(int input_val, char store_char[])
{
	int sign, i;
	if ((sign = input_val) < 0) // record sign for negative
	{
		input_val = -input_val; //make the input value positive
	}
	//printf("%d ",sign);
	i = 0; // do while loop initialization
	do
	{	
		store_char[i++] = (input_val % 10) + '0'; // Convert int value to absolute and convert to char
	} while ((input_val /= 10) > 0);
	
	if (sign < 0)
	{
		store_char[i++] = '-'; //Add "-" to the string if the input value is negative
	}
	store_char[i] = '\0'; //// Add null terminator to mark the end of the string
	
	reverse_char(store_char); // char go for reverse 
}

/*Function to convert an integer to string modified code */
void int_to_array_updated(int input_val, char store_char[])
{
	int sign = input_val, i = 0;
	
	do
	{
		store_char[i++] = abs(input_val % 10) + '0'; // Convert int value to absolute and convert to char
		input_val /= 10;
	}while (input_val != 0);
	
	if (sign < 0)
	{
		store_char[i++] = '-'; //assign "-" on the string for negative value
	}
	
	store_char[i] = '\0';
	reverse_char(store_char);
}

/*main function*/
int main(int argc, char *argv[])
{
	int input_val;
	char store_char[100] = ""; // Array to store the resulting string
	printf("Enter An Interger Value: ");
	scanf("%d", &input_val);
	
	int_to_array_book(input_val, store_char);
	printf("String Output (Book Code): %s\n", store_char); //book output
	
	int_to_array_updated(input_val, store_char);
	printf("String Output (Updated Code): %s\n", store_char); //update code output
	return 0;
}
