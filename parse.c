#include<stdio.h>
#include<string.h>
#include<stlib.h>
#define BOOLEAN int
#define true 1
#define false 0

char *buffer;
int bsize;
char *safe;


void initBuffer(char *inputLine);
//initialize the private parse.c buffer with the string passed in the parameter inputLine
BOOLEAN hasNextToken();
//This function returns a 1 if there are still more tokens in the string, otherwise it returns 0. For example, if this is a string "my name is Bob", then this string has 4 tokens
char *nextToken();
void rewind();

void initBuffer(char *inputLine){
	int len = strlen(inputLine);
	buffer = (char *)malloc(len + 1);
	strcpy(buffer,inputLine);
 
	safe = inputLine;
	//safe = (char *)malloc(len + 1);
	//strcpy(safe,inputLine);
}

BOOLEAN hasNextToken(){
	bsize = strlen(buffer);
	if((char)buffer[0]=='\0'){
		return 0;
	}
	else{
		return 1;
	}
}




//seperate into tokens
char *nextToken(){
	int line_num = 1;
	char *arrToken; 
	FILE *fp;
	char temp[512];
		

   	//how to input file content line by line?
   	//what is const char s[2]??
   	//char str[80] = ;
   	//const char s[2] = "-";


   	/* get the first token */
   	token = strtok(str, s);

   	/* walk through other tokens */
   	while( token != NULL ){
 
	
      	//	printf( " %s\n", token );
      	//	print is just for checking/debugging
		token = strtok(NULL, s);

	//return the array contain the tokens
	return 
   	}
	//do we need to increase the line number?
	//line_num++;
   	return NULL;
}


void rewind()
{
	initBuffer(safe);
}

