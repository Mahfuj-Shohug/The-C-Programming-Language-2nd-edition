#include <stdio.h>

/******************************************************************************************
** Functions    : main, bit_count, convart_binary,right_rotated 		 			  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: input_num 	-- input a number					                     **
** 				: right_bits, left_bits	-- Bits shift to right							 **
**				: nth_bit 		--int type variable for  bit 				 			 **
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: the value of the integer x rotated
				: to the right by n positions.											 **                                					
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

// counting the bit according to the input
int bit_count(unsigned int input_num)
{
	unsigned int num_bits = 0;
	while (input_num > 0)
    {
        input_num = input_num >> 1;
        num_bits++;
    }
    return num_bits;
}
// Function to set specific bits in first input using the rightmost nth bits of second value
unsigned int right_rotated(unsigned int input_num, int nth_bit)
{
	unsigned int num_bits = bit_count(input_num);
	unsigned int right_bits = input_num >> nth_bit; // Shift the rightmost nth_bits to the right
	unsigned int letf_bits = input_num & ((1 << nth_bit) - 1) << (num_bits - nth_bit); // Shift the remaining bits to the left
	return right_bits | letf_bits;   // Combine the two parts using bitwise OR
}

/*main function*/
int main(int argc, char *argv[]) 
{
	unsigned int input_num;
	int nth_bit;
	
	printf("Enter A Number:");
	scanf("%u", &input_num);
	
	printf("Enter The Nth Bits:");
	scanf("%d", &nth_bit);
	
	printf("Your Input Number in Binary Bits: 0b");
	convart_binary(input_num);
	printf("\n\n");
	
	unsigned int result = right_rotated(input_num, nth_bit);
	printf("The Result On Decimal Value: %u\n", result);
	printf("The Result On Binary Value: 0b");
	convart_binary(result);
	
	return 0;
}
