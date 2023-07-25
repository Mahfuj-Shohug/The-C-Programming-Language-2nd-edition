#include <stdio.h>
#include <string.h>
/******************************************************************************************
** Functions    : main,	reverse_char, int_to_array						    			 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: str[] 	-- arry of characters 					                     **
** 																   						 **
**				: i,j		   	-- 	loop variable						 				 **
**				: char_width	-- Minimum width of the string							 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: reverse the order of characters in the input string and 				 **
**				: print the reversed string.											 **                               						 **
*******************************************************************************************/

/* function for reverse the order of characters*/
void fun(char str[]) {
  char m;
  int i, j;

  // Reversing the order of characters in the string
  for (i = 0, j = strlen(str); i < j; i++, j--)
  {
    m = str[i];
    str[i] = str[j - 1];
    str[j - 1] = m;
  }
  // Printing the reversed string
  printf("Backward line is: %s\n", str);
}

/*Main function*/
int main(int argc, char *argv[])
{
  char line[100];
  printf("Enter line:");
  gets(line);
  fun(line);
  return 0;
}
