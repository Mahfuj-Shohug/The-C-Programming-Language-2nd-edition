#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
/******************************************************************************************
** Functions    : main,	print_signed_range, print_unsigned_range, int_to_array_updated ,
				: print_variable_ranges, direct_computation							  	 **
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: type_name 	-- variable type name 				                     **
** 				: min_value		-- variable type minimum value		      				 **
**				: max_value	    -- variable type maximum value   						 **
**																		 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: print the ranges of different variable types for standard headers		 **                                					
*******************************************************************************************/

// Function to print the signed range
void print_signed_range(const char* type_name, long long min_value, long long max_value) 
{
    printf("Range of signed %s: %lld to %lld\n", type_name, min_value, max_value);
}

// Function to print the unsigned range
void print_unsigned_range(const char* type_name, long long min_value, long long max_value) 
{
    printf("Range of %s: 0 to %llu\n\n", type_name, max_value);
}

// Function to print the ranges of different variable types for standard headers
void print_variable_ranges() 
{
    // Ranges for char types
    print_signed_range("char", CHAR_MIN, CHAR_MAX);
    print_unsigned_range("unsigned char", 0, UCHAR_MAX);

    // Ranges for short types
    print_signed_range("short", SHRT_MIN, SHRT_MAX);
    print_unsigned_range("unsigned short", 0, USHRT_MAX);

    // Ranges for int types
    print_signed_range("int", INT_MIN, INT_MAX);
    print_unsigned_range("unsigned int", 0, UINT_MAX);
    
	// Range for long types
	print_signed_range("long", LONG_MIN, LONG_MAX);
    print_unsigned_range("unsigned long", 0, ULONG_MAX);

    // Ranges for long types
    print_signed_range("long Long", LLONG_MIN, LLONG_MAX);
    print_unsigned_range("unsigned long Long", 0, ULLONG_MAX);

    // Range for floating-point type
    printf("Range of float: %E to %E\n", FLT_MIN, FLT_MAX);
    // Range for double type
    printf("Range of double: %E to %E\n", DBL_MIN, DBL_MAX);
}
//Function to print the ranges of different variable types for direct computation 
void direct_computation(const char* type_name, int size)
{
	// all equation of signed and unsigned variable range ex 2^(n-1) is 1LL << (n-1) 
	long long min_value = -(1LL << (size - 1));
    long long max_value = (1LL << (size - 1)) - 1;
    long long unsigned_maxi = (1ULL << size) - 1;
    print_signed_range(type_name, min_value, max_value);
    print_unsigned_range(type_name, 0, unsigned_maxi);
}
/*main function*/
int main(int argc, char *argv[]) 
{
	// Call the function to print variable ranges for standard headers method
	printf("variable ranges for standard headers method\n");
    print_variable_ranges();
    printf("\n******************************************\n");
    
	//Compute the size of variable using bits = byte * 8 formula for calculating direct computation
	int char_size = sizeof(char) * 8;
	int short_size = sizeof(short) * 8;
	int int_size = sizeof(int) * 8;
	int long_size = sizeof(long) * 8;
	int float_size = sizeof(float) * 8;
	int double_size = sizeof(double) * 8;
	int long_long_size = sizeof(long long) * 8;
	
	// show variable size
	printf("\n\nThe size of char variable is : %d bits", char_size);
	printf("\nThe size of short variable is : %d bits", short_size);
	printf("\nThe size of int variable is : %d bits", int_size);
	printf("\nThe size of float variable is : %d bits", float_size);
	printf("\nThe size of double variable is : %d bits", double_size);
	printf("\nThe size of long variable is : %d bits", long_size);
	printf("\nThe size of long long variable is : %d bits", long_long_size);
	
	//Show variable rnage
	printf("\n\nvariable ranges using direct computation method\n");
    direct_computation("char", char_size);
    direct_computation("short", short_size);
    direct_computation("int", int_size);
    direct_computation("long", long_size);
    return 0;
}
