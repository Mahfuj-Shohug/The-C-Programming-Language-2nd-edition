#include <stdio.h>

/******************************************************************************************
** Functions    : main, conv_lower										 			  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_char 	-- input a character					                 **			
**				: convarted 	--convarted	character			 				 		 **
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: function to convert the character, and then prints the
				: converted character (Upper to Lower)									 **                                					
*******************************************************************************************/
/* function is convert char to lower case; ASCII only */
int conv_lower(int input_char)
{
    // Check if the character is an uppercase letter then return
    return (input_char >= 'A' && input_char <= 'Z') ? (input_char + 'a' - 'A') : input_char;
}

/*main function*/
int main(int argc, char *argv[]) 
{
	int input_char;
	
	printf("Enter A Uppercase Letter:");
	scanf("%c", &input_char);

	int convarted = conv_lower(input_char);
	printf("Converted character: %c", convarted);
	return 0;
}
