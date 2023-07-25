#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000 //maximum array length
/******************************************************************************************
** Functions    : main,	escape, unescape, get_input                                      **
**                                                      	  						     ** 
** Inputs		: 1. argc       -- The number of parameters provided to the main function**
**				: 2. argv       -- The pointer to the input string array of parameters   **
** Variables	: s[] 	        -- arry for char value                                   **
** 				: t[]        	-- arry for the char value         	           		     **
**			                                                   			 				 **
** Return		: = 0 	        -- Success 											     **
** 				: <	0	        -- Failed												 **
** Note			:  converting escape sequences into the real characters                  **
*******************************************************************************************/

/*visible escape sequences*/
void escape(char s[], char t[])
{
  int i, j;
  for (i = j = 0; t[i] != '\0'; ++i, ++j)
  {
    switch (t[i])
    {
    case '\a':
      s[j++] = '\\';
      s[j] = 'a';
      break;

    case '\b':
      s[j++] = '\\';
      s[j] = 'b';
      break;

    case '\f':
      s[j++] = '\\';
      s[j] = 'f';
      break;

    case '\n':
      s[j++] = '\\';
      s[j] = 'n';
      break;

    case '\r':
      s[j++] = '\\';
      s[j] = 'r';
      break;

    case '\t':
      s[j++] = '\\';
      s[j] = 't';
      break;

    case '\v':
      s[j++] = '\\';
      s[j] = 'v';
      break;

    case '\\':
      s[j++] = '\\';
      s[j] = '\\';
      break;

    case '\?':
      s[j++] = '\\';
      s[j] = '?';
      break;

    case '\'':
      s[j++] = '\\';
      s[j] = '\'';
      break;

    case '\"':
      s[j++] = '\\';
      s[j] = '"';
      break;

    default:
      s[j] = t[i];
      break;
    }
  }

  if (t[i] == '\0')
  {
    s[j] = t[i];
  }
}

/*function for the other directio*/
void unescape(char s[], char t[])
{
  int i, j;
  for (i = j = 0; t[i] != '\0'; ++i, ++j)
  {
    switch (t[i])
    {
    case '\\':
      switch (t[++i])
      {
      case 'a':
        s[j] = '\a';
        break;

      case 'b':
        s[j] = '\b';
        break;

      case 'f':
        s[j] = '\f';
        break;

      case 'n':
        s[j] = '\n';
        break;

      case 'r':
        s[j] = '\r';
        break;

      case 't':
        s[j] = '\t';
        break;

      case 'v':
        s[j] = '\v';
        break;

      case '\\':
        s[j] = '\\';
        break;

      case '?':
        s[j] = '\?';
        break;

      case '\'':
        s[j] = '\'';
        break;

      case '"':
        s[j] = '\"';
        break;

      default:
        s[j++] = '\\';
        s[j] = t[i];
        break;
      }
      break;

    default:
      s[j] = t[i];
      break;
    }
  }

  if (t[i] == '\0')
  {
    s[j] = t[i];
  }
}

/*input char*/
int get_input(char line[], unsigned int limit)
{
  int i, c;
  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i++] = c;
  }

  line[i] = '\0'; // for null value

  return i;
}

/*main function*/
int main(int argc, char *argv[])
{
    char t[MAXLEN], s[MAXLEN];;
    
    get_input(t, MAXLEN);
    
    escape(s, t);
    printf("%s\n", s); // print  escape sequences into the real characters

    unescape(s, t);
    printf("%s", s); // remove escape sequences real characters and print
     
    return 0;
}   

