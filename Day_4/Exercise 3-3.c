#include <stdio.h>
#include <ctype.h>
/******************************************************************************************
** Functions    : main,	expand,                                                           **
**                                                      	  						     ** 
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **      	           		     
**			                                                   			 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			:  converting escape sequences into the real characters                  **
*******************************************************************************************/
/* declire expand function*/
void expand(const char s1[], char s2[]);

/*main func*/
int main(void)
{
    const char s1[] = "a-z 1-5 A-D";
    char s2[1000];

    expand(s1, s2);
    printf("Expanded string: %s\n", s2);

    return 0;
}

void expand(const char s1[], char s2[])
{
    int i, j, k;

    i = j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0') {
            char start = s1[i - 1];
            char end = s1[i + 1];

            if ((islower(start) && islower(end)) || (isupper(start) && isupper(end)) || (isdigit(start) && isdigit(end))) {
                for (k = start + 1; k <= end; k++) {
                    s2[j++] = k;
                }
            } else {
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }

        i++;
    }

    s2[j] = '\0';
}
