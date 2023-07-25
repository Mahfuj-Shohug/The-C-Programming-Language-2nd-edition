#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	squeeze													       	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_str1[] 	-- arry of characters to inpuut and compare              **
** 				: input_str2	-- 2nd arry of characters to inpuut and compare       	 **
**															    						 **
**				: i,j,k		   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: deletes each character in
				input_str1 that matches any character in the string input_str2
                                														 **
*******************************************************************************************/

// squeeze function
void squeeze(char str1[], char str2[])
{
	int i, j, k, remove_char;
	
	for (i = j = 0; str1[i] != '\0'; i++)
	{
		remove_char = 0;
		
		for (k = 0; str2[k] != '\0'; k++)
		{
			if (str1[i] == str2[k])
			{
				remove_char = 1;
				break;
			}
		}
		
		if (!remove_char)
		{
			str1[j++] = str1[i];
		}
	}
	
	str1[j] = '\0';
}


/*main function*/
int main(int argc, char *argv[])
{
    char input_str1[100], input_str2[100];
    
    printf("Enter the input string 1: ");
    gets(input_str1);

    printf("Enter the input string 2: ");
    gets(input_str2);

    printf("Before squeeze: %s\n", input_str1);
    squeeze(input_str1, input_str2);
    printf("After squeeze: %s\n", input_str1);

    return 0;
}
