#include <stdio.h>
#define MAX_SIZE 100
/******************************************************************************************
** Functions    : main															     	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_string[] -- arry of characters 				                     **
** 				: store_each_char-- each character read			          				 **
**				: input_string  -- 	Inputed string from user       						 **
**				: i			   	-- 	loop variable						 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: loop without using && or || condetional operator						 **
*******************************************************************************************/
/*main function*/
int main(int argc, char *argv[])
{
    char input_string[MAX_SIZE]; // Array to store the input string
    int i = 0;
    int store_each_char; // Variable to store each character read
	
	//loop to continue indefinitely until a certain condition is met
    while (1) {
        if (i >= MAX_SIZE - 1) {
            break; // If array is full, break out of the loop
        }

        store_each_char = getchar(); // Read a character from input

        if (store_each_char == '\n') 
		{
            break; // If newline character is encountered, break out of the loop
        }

        if (store_each_char == EOF) 
		{
            break;
        }

        input_string[i] = store_each_char; // Store the character in the array
        i++; 
    }

    input_string[i] = '\0'; // Add null for valid C string
    printf("Yout Input Is: %s\n", input_string); 
    return 0;
}
