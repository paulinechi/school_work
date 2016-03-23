#include<stdio.h>

void intBuffer(char *inputLine);
//initialize the private parse.c buffer with the string passed in the parameter inputLine

BOOLEAN hasNextToken();
//This function returns a 1 if there are still more tokens in the string, otherwise it returns 0. For example, if this is a string "my name is Bob", then this string has 4 tokens.
#define BOOLEAN int
#define TRUE 1
#define FALSE 0
BOOLEAN x;
int y;
if (z == TRUE) ......
return FALSE;



char *nextToken();
//This function removes the first token from the buffer. The buffer is reduced in size since the token was removed. The removed token is returned to the caller. If the buffer is empty then this function returns NULL.


//void rewind();

