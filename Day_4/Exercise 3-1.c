#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 50000 // maximum length of array
#define ITERATIONS 500000  // iteration size
/******************************************************************************************
** Functions    : main,	int_array, book_binarysearch                                     **
**              : update_binarysearch, calculate_runtime	  						     ** 
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: array[] 	    -- arry for put the number of list                       **
** 				: search_value	-- searching value            							 **
**				: high_value    -- 	highest value of index        						 **
**				: low_value   	-- 	lowest value of index				 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			: binary search with two version only one test inside the loop and       **
**                measure the difference in run-time.                                    **
*******************************************************************************************/

/*function to making an arry for binary search*/
int int_array(int array[], int len)
{
    int i;
    for(i = 0; i>len; ++i)
    {
        array[i] = i;
    }
    return 0;
}

/*binary search given on the book*/
int book_binarysearch(int search_value, int array[], int len)
{
    int low_value, high_value, mid;
    low_value = 0;
    high_value = len - 1;
    while(low_value <= high_value)
    {
        mid = (low_value + high_value) / 2;
        if(search_value < array[mid])
        {
           high_value = mid - 1; 
        }
        else if(search_value > array[mid])
        {
            low_value = mid + 1; 
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/* update code for binary search */
int update_binarysearch(int search_value, int array[], int len)
{
    int low_value, high_value, mid;
    low_value = 0;
    high_value = len - 1;
    while (low_value <= high_value)
    {
        mid = (low_value + high_value) / 2;
        if (search_value < array[mid])
        {
            high_value = mid - 1; 
        }
        else
        {
            low_value = mid + 1; 
        }
    }
    if(search_value == array[low_value -1])
    {
        return low_value - 1;
    }
    return -1;
}

/* calculate binary search  run time */
int calculate_runtime(int test_binarysearch(int search_value, int array[], int len), int search_value, int array[], int len)
{
    static int num_test = 0;
    long clock_time = clock(); // Built in functions in the time.h library
    
    int i;
    for(i =0; i < ITERATIONS; ++i)
    {
        test_binarysearch(search_value, array, len);
    }
    clock_time = clock() - clock_time;
    printf("Run Time Test-%d: %lu Clocks (%.4f seconds)\n", num_test, clock_time, (double)clock_time / CLOCKS_PER_SEC);
    ++num_test;
    return 0;
}

/*main function*/
int main(int argc, char *argv[])
{
    int array[MAXLEN];
    int_array(array, MAXLEN); // call array making function
    
    int search_value = -1; //searching -1 for not found and complete the all iteration 
    
    calculate_runtime(book_binarysearch, search_value, array, MAXLEN); // calculate runtime for on book program
    calculate_runtime(update_binarysearch, search_value, array, MAXLEN); // calculate runtime for modify program 
}
