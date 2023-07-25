#include <stdio.h>
#include <string.h>

#define BUFSIZE 5 //set buffer size
/**************************************************************************************
** Function Name: main, getInput, getch, ungetch, ungets   					  		 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: buf[BUFSIZE]	-- Global variable		                             **
** 				: low_temp	-- lowest value of tempture 0							 **
**				: s[]	 	-- 	inputed string										 **
**				: i,		-- 	loop variable 						 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:ungets(s) that will push back an entire string onto the input		 **
***************************************************************************************/

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

// Function to get user input and store it in a string
void getInput(char s[])
{
    int i = 0;
    printf("Enter any string: ");
    while ((s[i] = getchar()) != '\n')
	{
        i++;
    }
    s[i] = '\0'; // Null-terminate the input string
}

// Function to get a (possibly pushed-back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Function to push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
	{
        printf("ungetch: too many characters\n");
    } else
	{
        buf[bufp++] = c;
        printf("%c\n", c);
    }
}

// Function to push an entire string onto the input
void ungets(const char* s)
{
    size_t len = strlen(s);
    printf("Before ungetch: \n");
    while (len > 0)
	{
        ungetch(s[--len]);
    }
}

int main(int argc, char *argv[])
{
    char s[BUFSIZE];
    getInput(s); // Get user input and store it in string s
    ungets(s); // Push the string s onto the input
    int c;
    printf("After ungetch:\n");
    while ((c = getch()) != EOF)
	{
        printf("%c", c); // Print characters retrieved from the input
    }
    return 0;
}
