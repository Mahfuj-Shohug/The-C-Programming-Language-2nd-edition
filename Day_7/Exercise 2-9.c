#include <stdio.h>

/******************************************************************************************
** Functions    : main, counting_bits, convart_binary					 			  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_num 	-- input a number					                     **
** 				: bits_count	-- Bits shift to right									 **				
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: count the number of 1 bits in an unsigned integer						 **                                					
*******************************************************************************************/

// Function to print the binary representation of a number
void convart_binary(unsigned int num)
{
	int binary[32], i, index = 0;
	
	if (num == 0)
	{
		printf("0");
		return;
	}
	
	// Convert the number to binary by repeated division by 2
	while (num > 0) 
	{
        binary[index++] = num % 2;  // Store the remainder (0 or 1)
        num /= 2;  // Divide the number by 2
    }
    // Print the binary representation by iterating in reverse order
    for (i = index - 1; i >= 0; i--) 
	{
        printf("%d", binary[i]);
    }
}

// Function to count the number of 1 bits in an unsigned integer
int counting_bits(unsigned int input_num)
{
	int bits_count = 0;  // Variable to store the count of 1 bits

    // Loop until x becomes 0
    while (input_num != 0) {
        input_num &= (input_num - 1);  // Delete the rightmost 1 bit in x
        bits_count++;  // Increment the count
    }

    return bits_count;  // Return the final count
}

/*main function*/
int main(int argc, char *argv[]) 
{
	unsigned int input_num;
	
	printf("Enter A Number:");
	scanf("%u", &input_num);
	
	printf("Your Input Number in Binary Bits: 0b");
	convart_binary(input_num);
	printf("\n\n");
	int num = counting_bits(input_num);
	printf("Then count number of 1 bits: %d", num);
}
