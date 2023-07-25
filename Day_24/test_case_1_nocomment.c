#include <stdio.h>
#include <string.h>

#define MAXLINE 100 

int getline(char line[], int maxline);
void remove_trailing_blanks(char line[], int length);


int main(int argc, char *argv[])
{
    int len; 
    char line[MAXLINE]; 

    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("Input: %s", line);
        printf("Input Length: %d\n", len - 1); 

        remove_trailing_blanks(line, len);

        if (line[0] != '\n')
        {
            printf("Output: %s", line);
            printf("Output Length: %d\n\n", len - 1 - (len - 1 - strlen(line))); 
        }
    }

    return 0;
}


int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}


void remove_trailing_blanks(char line[], int length)
{
    int i;

    
    for (i = length - 2; i >= 0; --i)
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            break;
        }
    }

    line[i + 1] = '\n'; 
    line[i + 2] = '\0'; 
}

