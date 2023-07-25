#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* Function headers */
/* push: push f onto value stack */
void push(double f);

/* pop: pop and return top value from stack */
double pop(void);

int getch(void); /* get a (possibly pushed-back) character */

void ungetch(int c); /* push character back on input */

/* getop: get next character or numeric operand */
int getop(char s[]);

/* performOperation: perform the operation based on the operator */
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

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
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
	printf("Enter some number with mathmetical sign: ");
    while ((type = getop(s)) != EOF)
    {
        if (type == NUMBER)
            push(atof(s));
        else
            performOperation(s[0]);
    }

    return 0;
}

