#include <stdio.h>

/******************************************************************************************
** Functions    : main, set_bits, convart_binary		 							  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: first_input 	-- input a number					                     **
** 				: second_input	-- rightmost nthbits of 2nd input		  				 **
**				: position, nth_bit --int type variable for position and bit  			 **
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: position set to the rightmost nthbits of second_input, leaving the other bits unchanged	 **                                					
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
unsigned int set_bits(unsigned int first_input, unsigned int second_input, int position, int nth_bit)
{
	unsigned int bit_mask = ((1 << nth_bit) - 1) << (position - nth_bit + 1);  // Create a bitmask to cover the desired bits in first_input
	unsigned int bits = (second_input & ((1 << nth_bit) - 1)) << (position - nth_bit + 1);  // Extract the rightmost nth_bit from second_input and align them
	return (first_input & ~ bit_mask) | bits;  // Clear the corresponding bits in first_input and set them with the extracted bits from second_input
}

/*main function*/
int main(int argc, char *argv[]) 
{
	unsigned int first_input, second_input;
	int position, nth_bit;
	
	printf("Enter First Number:");
	scanf("%u", &first_input);
	printf("Enter Second Number:");
	scanf("%u", &second_input);
	
	printf("Enter The Position:");
	scanf("%d", &position);
	printf("Enter The Nth Bits:");
	scanf("%d", &nth_bit);
	
	printf("Your 1st Input in Binary Bits: 0b");
	convart_binary(first_input);
	printf("\n");
	printf("Your 2nd Input in Binary Bits: 0b");
	convart_binary(second_input);
	printf("\n\n");
	
	unsigned int result = set_bits(first_input, second_input, position, nth_bit);
	printf("The Result On Decimal Value: %u\n", result);
	printf("The Result On Binary Value: 0b");
	convart_binary(result);
	
	return 0;
}
