#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
enum { NAME, PARENS, BRACKETS };

int getch(void);
void ungetch(int c);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];


/***************************************************
 * Function Name: main
 * Description: Converts word description to a declaration and prints the output.
 * Variables: type - type of token
 *            paren_flag - flag to indicate if parentheses are present
 *            temp - temporary string for constructing the output
 ****************************************************/
int main(void)
{
    int type, paren_flag = 0;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);

        while ((type = gettoken()) != '\n')
        {
            if (paren_flag)
            {
                if (type == PARENS || type == BRACKETS)
                {
                    sprintf(temp, "(*%s)", out);
                    strcpy(out, temp);
                }
                else
                {
                    sprintf(temp, "*%s", out);
                    strcpy(out, temp);
                }
                paren_flag = 0;
            }
            if (type == PARENS || type == BRACKETS)
            {
                strcat(out, token);
            }
            else if (type == '*')
            {
                paren_flag = 1;
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("Error: Invalid input at %s\n", token);
                break;
            }
        }

        printf("Update Output: %s\n", out);
    }

    return 0;
}


/***************************************************
 * Function Name: gettoken
 * Description: Skips blanks and tabs, then finds the next token in the input.
 * Variables: c - current character
 *            p - pointer to the token string
 ****************************************************/
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
}


/***************************************************
 * Function Name: getch
 * Description: Gets the next character from input or the buffer
 * Variables: None
 ****************************************************/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/***************************************************
 * Function Name: ungetch
 * Description: Pushes character back onto input or the buffer
 * Variables: c - character to be pushed back
 ****************************************************/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("Error: ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

