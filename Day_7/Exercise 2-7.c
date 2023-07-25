#include <stdio.h>

/******************************************************************************************
** Functions    : main, invert, convart_binary			 							  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_num 	-- input a number					                     **
** 				: bit_mask		-- bitmask to cover the desired bits of inputs num  	 **
**				: position, nth_bit --int type variable for position and bit  			 **
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: inverted (1 changed into 0 and vice versa), leaving the others unchanged**                                					
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

// Function to set specific bits in first input using the rightmost nth bits of second value
unsigned int invert(unsigned int input_num, int position, int nth_bit)
{
	unsigned int bit_mask = ((1 << nth_bit) - 1) << (position - nth_bit + 1); // Create a bitmask to cover the desired bits in first_input
	return input_num ^ bit_mask;  // Perform bitwise XOR operation to invert the bits
}

/*main function*/
int main(int argc, char *argv[]) 
{
	unsigned int input_num;
	int position, nth_bit;
	
	printf("Enter A Number:");
	scanf("%u", &input_num);
	
	printf("Enter The Position:");
	scanf("%d", &position);
	printf("Enter The Nth Bits:");
	scanf("%d", &nth_bit);
	
	printf("Your Input Number in Binary Bits: 0b");
	convart_binary(input_num);
	printf("\n\n");
	
	unsigned int result = invert(input_num, position, nth_bit);
	printf("The Result On Decimal Value: %u\n", result);
	printf("The Result On Binary Value: 0b");
	convart_binary(result);
	
	return 0;
}
