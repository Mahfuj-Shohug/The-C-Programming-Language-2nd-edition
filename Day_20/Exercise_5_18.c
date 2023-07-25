#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
enum { NAME, PARENS, BRACKETS };

int getch(void);
void ungetch(int c);
void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

int error_flag = 0; // Flag to track errors

/****************************************************
 * Function Name: main
 * Description: Entry point of the program.
 * (void) part specifies an empty parameter list.
 * Returns: 0 on successful execution.
 ****************************************************/
int main(void)
{
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        error_flag = 0; // Reset error flag for each declaration
        dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
            error_flag = 1; // Set error flag
        }
        if (!error_flag) { // Print output only if no error encountered
            printf("%s: %s %s\n", name, out, datatype);
        }
    }
    return 0;
}

/*****************************************
 * Function Name: dcl
 * Description: Parses a declarator.
 * Returns: None.
 *****************************************/
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ns++)
        ;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/********************************************
 * Function Name: dirdcl
 * Description: Parses a direct declarator.
 * Returns: None.
 ********************************************/
void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            error_flag = 1; // Set error flag
            while (gettoken() != ')' && tokentype != EOF)
                ;
        }
    } else if (tokentype == NAME) {
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
        error_flag = 1; // Set error flag
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/********************************************************
 * Function Name: gettoken
 * Description: Retrieves the next token from input.
 * Returns: The type of the token.
 ********************************************************/
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int c);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

/********************************************************
 * Function Name: getch
 * Description: Get a (possibly pushed back) character.
 * Returns: The next character from input.
 ********************************************************/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/**********************************************
 * Function Name: ungetch
 * Description: Push character back on input.
 * Parameters:
 *   - c: The character to be pushed back.
 * Returns: None.
 **********************************************/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

