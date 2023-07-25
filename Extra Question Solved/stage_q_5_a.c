#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void GetMemory(char **p)
{
	*p = (char *)malloc(100);
}
void Test(void) 
{
	char *str = NULL;
	GetMemory(&str);	
	strcpy(str, "hello world");
	printf("%s\n", str);
}
int main()
{
	Test();
	return 0;
}
