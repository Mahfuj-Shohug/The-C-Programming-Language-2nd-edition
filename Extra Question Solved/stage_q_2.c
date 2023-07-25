#include <stdio.h>
int main(int argc, char *argv[])
{
    char*s = "hello";
    char ch='a';
	
    printf( "sizeof(char) = %u\n", sizeof( char));
    printf( "sizeof(char*)= %u\n", sizeof( char*));
	
    printf( "sizeof('a') = %u\n", sizeof( 'a'));
    printf( "sizeof(ch) = %u\n", sizeof(ch));

    printf( "sizeof(*s+0) = %u\n", sizeof(*s+ 0));
    printf( "sizeof(*s) = %u\n", sizeof(*s));
    printf( "sizeof(s) = %u\n", sizeof(s));
    
    return	0;
}

