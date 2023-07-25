#include <stdio.h>

int main()
{
	char *array3[2] = {"awk", "AWK"};
	char **p3 = array3;
	
	printf("Address of array3: %d\n", array3);
	printf("Address of array3 + 1: %d\n", array3 + 1);
	printf("Address of &array3 + 1: %d\n", &array3 + 1);
	printf("Address of &array3[0] + 1: %d\n", &array3[0] + 1);
	printf("Address of p3 + 1: %d\n", p3 + 1);
	printf("Address of *p3: %d\n", *p3);
	printf("Address of *p3 + 1: %d\n", *p3 + 1);
	printf("Address of **p3: %d\n", **p3);
	printf("Address of **p3 + 1: %d\n", **p3 + 1);

}
