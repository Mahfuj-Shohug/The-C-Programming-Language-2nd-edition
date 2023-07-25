#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

#define MAXVAL 100  /* maximum depth of val stack */
/* Pushes a floating-point number onto the stack **************************************************
void push(double f);

/* Pops and returns the top value from the stack 
double pop(void);

/* Prints the top element of the stack 
void printTop(void);

/* Duplicates the top element of the stack 
void duplicateTop(void);

/* Swaps the top two elements of the stack 
void swapTopTwo(void);

/* Clears the stack 
void clearStack(void);

/* Retrieves a character from input 
int getch(void);

/* Pushes a character back onto the input 
void ungetch(int c);

/* Gets the next character or numeric operand
 * s: character array to store the operand or operator
 * Returns the type of the token: NUMBER for a number, or the character itself for an operator 
int getop(char s[]);

/* Performs the operation based on the operator
 * operator: the operator to perform the operation for 
void performOperation(char operator);
****************************************************************************************************/

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* Function prototypes */
int getch(void);
void ungetch(int c);
int getop(char s[]);
void performOperation(char operator);

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* Print the top element of the stack */
void printTop(void)
{
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp - 1]);
    else
        printf("Stack is empty\n");
}

/* Duplicate the top element of the stack */
void duplicateTop(void)
{
    if (sp > 0)
    {
        double top = val[sp - 1];
        push(top);
    }
    else
        printf("Stack is empty\n");
}

/* Swap the top two elements of the stack */
void swapTopTwo(void)
{
    if (sp >= 2)
    {
        double top = pop();
        double second = pop();
        push(top);
        push(second);
    }
    else
        printf("Stack has less than two elements\n");
}

/* Clear the stack */
void clearStack(void)
{
    sp = 0;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */

    if (c == '-')
    {
        if (isdigit(s[1] = c = getch()))
        {
            i = 1;
        }
        else
        {
            ungetch(c);
            return '-';
        }
    }
    else
    {
        i = 0;
    }

    if (isdigit(c)) /* collect integer part */
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') /* collect fraction part */
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/* performOperation: perform the operation based on the operator */
void performOperation(char operator)
{
    switch (operator)
    {
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            {
                double op2 = pop();
                push(pop() - op2);
            }
            break;
        case '/':
            {
                double op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
            }
            break;
        case '%':
            {
                double op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
            }
            break;
        case 's':   /* sin function */
            push(sin(pop()));
            break;
        case 'e':   /* exp function */
            push(exp(pop()));
            break;
        case 'p':   /* pow function */
            {
                double op2 = pop();
                push(pow(pop(), op2));
            }
            break;
        case 'l':
            push(log(pop()));
            break;
        case 'f':
            push(floor(pop()));
            break;
        case 't':
            printTop();
            break;
        case 'd':
            duplicateTop();
            break;
        case 'w':
            swapTopTwo();
            break;
        case 'c':
            clearStack();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %c\n", operator);
            break;
    }
}

/* Main function */
int main()
{
    int type;
    char s[MAXOP];
    printf("Input 's' for sin(top) \n");
    printf("Input 'p' for pow(top) \n");
    printf("Input 'l' for log(top) \n");
    printf("Input 'f' for floor(top) \n");
    printf("Input 't' for print top \n");
    printf("Input 'd' for duplicate \n");
    printf("Input 'w' for swap \n");
    printf("Input 'c' for clear all \n");
    while ((type = getop(s)) != EOF)
    {
        if (type == NUMBER)
            push(atof(s));
        else
            performOperation(s[0]);
    }

    return 0;
}

