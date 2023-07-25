#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/*************************************************************************************
 * Function: getInput																**
 * -------------------																**
 * Reads user input from the console and removes the trailing newline character.	**
 *																					**
 * input: The character array to store the user input.								**
 * size: The size of the input array.												**
 ************************************************************************************/
void getInput(char input[], int size) {
    fgets(input, size, stdin);

    // Remove the trailing newline character from the input
    size_t input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n')
        input[input_length - 1] = '\0';
}

/********************************************************************************************
 * Function: atof																		   **
 * -------------------																	   **
 * Converts a string representing a number in scientific notation to a floating-point value.*
 *																						   **
 * s: The input string to convert.														   **
 *																						   **
 * returns: The converted floating-point value.											   **
 *******************************************************************************************/
double atof(const char s[]) {
    double val, power;
    int i, sign, exp_sign, exp_val;

    // Skip leading white space characters
    for (i = 0; isspace((unsigned char)s[i]); i++)
        ;

    // Determine the sign of the number
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Process the integer part of the number
    for (val = 0.0; isdigit((unsigned char)s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Process the fraction part of the number
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit((unsigned char)s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // Process the exponent part of the number
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;

        for (exp_val = 0; isdigit((unsigned char)s[i]); i++)
            exp_val = 10 * exp_val + (s[i] - '0');

        // Adjust the value based on the exponent
        if (exp_sign == 1)
            val *= pow(10, exp_val);
        else
            val /= pow(10, exp_val);
    }

    // Calculate the final value by dividing the integer part by the power of 10
    return sign * val / power;
}

/***********************************
 * Function: main				  **
 * -------------------			  **
 * The entry point of the program.**
 **********************************/
int main() {
    char input[100];
    double result;

    printf("Enter a number in scientific notation: ");
    getInput(input, sizeof(input));
    result = atof(input);
    printf("Parsed value: %f\n", result);

    return 0;
}

