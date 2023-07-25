#include <stdio.h>
/*Macro Define to swap values of x and y*/
#define swap(type_s, x_val, y_val)  \
    {                               \
        type_s temp;                \
        temp = x_val;               \
        x_val = y_val;              \
        y_val = temp;               \
    };
/**************************************************************************************
** Function Name: main							 					  				 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: x_val		-- First value			                         	     **
** 				: y_val		-- Second value											 **
**				: type_s	-- 	Type of the variable								 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:Define a macro that interchanges two arguments of type				 **
***************************************************************************************/

// Main Function
int main(int argc, char *argv[])
{
    int x_val, y_val;
    printf("Enter X value: ");
    scanf("%d", &x_val); /* Input value of X*/
    printf("Enter Y value: ");
    scanf("%d", &y_val); /* Input value of Y*/

    printf("Before Swap:->\n\t\tX = %d\n\t\tY = %d\n", x_val, y_val);
    /*Swap the values using the swap macro*/
    swap(int, x_val, y_val);
    printf("After Swap:->\n\t\tX = %d\n\t\tY = %d\n", x_val, y_val);
}

