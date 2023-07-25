#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>
#include <math.h>
#include <string.h> // for strlen()

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define SETVARIABLE 's' // signal that a variable is being assigned
#define GETVARIABLE 'g' // signal that a variable is being retrieved
#define ERRORSIGNAL ' ' // signal that an error occurred in getop
#define MAXVAL 100      // maximum depth of val stack
#define BUFSIZE 100     // buffer size for getch and ungetch
#define NUMVARS 27      // number of variables supported (a-z) plus the variable L for last printed

/**************************************************************************************
** Function Name: main, gives on the function header section   				  		 ** 
** Inputs		: 1. argc   -- The number of parameters provided to the main function**
**				: 2. argv   -- The pointer to the input string array of parameters   **
** Variable		: Describe on the comment line						 				 **
** Return		: = 0 	    -- Success 											     **
** 				: <	0	    -- Failed												 **
** Note			:Add a variable for the most recently printed value					 **
***************************************************************************************/


enum boolean {FALSE, TRUE};

int sp = 0;                      // next free stack position
double val[MAXVAL];              // value stack
char buf[BUFSIZE];               // buffer for ungetch
int bufp = 0;                    // next free position in buf
double varVals[NUMVARS] = {0.0}; // array to store the double values for variables. Supports variables a through z (lower case). Initial value is 0

//function header
int getop(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);
void printTop(void);
void duplicateTop(void);
void swapTopTwo(void);
void hints(void);
// reverse Polish calculator
// note: convert ((((-1 - 2) * (4 + -5)) / -3) % 5) * (-1 - -10) to -1 2 - 4 -5 + * -3 / 5 % -1 -10 - * for reverse Polish notation. -1 2 - 4 -5 + * -3 / 5 % -1 -10 - * == -9
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    char skipNextNewline = FALSE;
    hints();
    printf("\n");
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s)); // convert the string to type double and push it on the stack
                break;
            case SETVARIABLE:
                if (strlen(s) > 2 && s[1] == '=')
                {
                    int v = s[0];           // stores variable
                    int i = 1;              // start at 1 since while loop needed ++i for a few reasons
                    while (s[++i] != '\0')  // this removes the variable name= part of s e.g. if s == "a=123.45" after loop s == "123.45"
                    s[i - 2] = s[i];    // shifts chars two to the left by 2
                    s[i - 2] = '\0';        // since '\0' isn't copied, terminate string manually
                    varVals[v - 'a'] = atof(s); // convert string to double and store it in array
                }
                else
                    printf("error: set variable length too small or incorrectly formatted (%s)\n", s);

                skipNextNewline = TRUE;
                break;
            case GETVARIABLE:
                push(varVals[s[0] - 'a']);  // convert the variable name to stored value
                break;
            case '+':
                push(pop() + pop()); // pop last two digits to sum them and push the result on the stack
                break;
            case '*':
                push(pop() * pop()); // pop last two digits to multiply them and push the result on the stack
                break;
            case '-':
            /*
                Because + and * are commutative operators, the order in which the popped operands are combined is irrelevant, but for - and / the left and right operands
                must be distinguished. In push(pop() - pop());, the order in which the two calls of pop are evaluated is not defined. To guarantee the right order, it is
                necessary to pop the first value into a temporary variable. Hence op2 = pop() in - and / but not in + and *
            */
                op2 = pop();
                push(pop() - op2); // pop last two digits to subtract them in the correct order and push the result on the stack
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2); // pop last two digits to divide them in the correct order and push the result on the stack
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2)); // pop last two digits in the correct order to find the modulus and push the result on the stack
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':
                printTop();
                skipNextNewline = TRUE;
                break;
            case 'd':
                duplicateTop();
                skipNextNewline = TRUE;
                break;
            case 'w':
                swapTopTwo();
                skipNextNewline = TRUE;
                break;
            case '!':
            // sets next free stack position to zero (meaning the value stack is empty).
            // all of the original values are still there, but they will no longer be accessible by the current functions and they will be overwritten when new elements are stored
                sp = 0;
                skipNextNewline = TRUE;
                break;
            case 'L':
                push(varVals[NUMVARS - 1]); // adds the last printed value to the stop of the stack
                break;
            case '\n':
                if (skipNextNewline)
                    skipNextNewline = FALSE;
                else
                {
                    varVals[NUMVARS - 1] = pop(); // updates last printed value
                    printf("\t%.8g\n", varVals[NUMVARS - 1]); // get the final result
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL) // if value stack still has space, add f
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0) // if the next free stack position is greater than zero, return the highest level item from stack
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;
    char setVar = FALSE;
    i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t') // skip white space
        ;
    s[1] = '\0'; // terminate string in case input is not a number (s is expected to be a string throughout program)
    if (c >= 'a' && c <= 'z')
    {
        if ((s[++i] = c = getch()) == '=') // get next char and check if it was an equal symbol. Update s in case of error
            setVar = TRUE;
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            ungetch(c); // return the whitespace since it will be processed later
            return GETVARIABLE;
        }

        if (!(setVar && ((s[++i] = c = getch()) == '-' || isdigit(c))))
            return ERRORSIGNAL; // triggers an error and will display what is in s
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number. Probably an operator, so return it. Minus operator is a special case and is handled right before return NUMBER;
    if (c == '-' || isdigit(c)) // collect integer(s), if any, after first digit found or after minus symbol found
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part if period is found
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0'; // terminate string after digits were captured
    if (c != EOF)
        ungetch(c); // since we read to far, push the last read char back on the getch buffer. This buffer is read first before getting the next char from input
    if (i == 1 && s[0] == '-') // if s[0] == '-' && s[1] == '\0', return minus operator
        return '-';
    if (setVar)
        return SETVARIABLE;
    else if (c >= 'a' && c <= 'z')
        return ERRORSIGNAL; // if last char is a variable, throw error

    return NUMBER;
}

// get a (possibly pushed back) character
// checks to see if there are any chars in buffer. If there are, get those and return it. If not, call getchar() from stdio.h to get next char from input
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
// if bufp is less than BUFSIZE, there is room to store more chars to be read by getch next and it stores c and updates the index for it
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// prints the top element in the value stack
void printTop(void)
{
    if (sp > 0)
        printf("\t%.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

void duplicateTop(void)
{
    if (sp < MAXVAL) // only need to see if there is space for one more
        push(val[sp - 1]); // duplicates top item
    else
        printf("error: stack full, can't duplicate top element\n");
}

void swapTopTwo(void)
{   // if sp == 2, there are at least two elements stored
    if (sp > 1)
    {                               // <third> <second> <first>
        double first = pop();       // <third> <second>
        double second = pop();      // <third>
        push(first);                // <third> <first>
        push(second);               // <third> <first> <second>
    }
    else
        printf("error: can't swap top two, not enough elements\n");
}

void hints()
{
    printf("-> Enter equations in the form: \"1 1 + 2 5 + *\"\n");
    printf("-> Use \"a=1 press enter b=2 press enter c=3\" to store variables.\n");
    printf("-> Use \"a b c * *\" to use stored variables.\n");
    printf("-----------------------------------------------\n");
    printf(">>> Command Help:\n");
    printf(">>>     !:      Clear memory.\n");
    printf(">>>     p:      Print last character.\n");
    printf(">>>     s:      Swap last two characters.\n");
    printf(">>>     d:      Duplicate the last input.\n");
    printf(">>>     L:      Print variable list.\n");
}

