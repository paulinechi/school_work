#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
void myrewind();

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

	int i = 0; 	//initialize the array size to zero
		
	//while(!isspace(buffer + i))
	if((buffer!=NULL)&&(isspace(buffer + i))){
		char nextToken[i];
		int j;
		for(j = 0;j < i;j=j+1){
			nextToken[j] =*buffer;
			buffer+=1;
			bsize-=1;
		} 	
	}
	else if(buffer==NULL){
		arrToken = NULL;	
	}
	else{
		i+=1;
		//increase i so can point to the next element to check if it is space
	}	

	return arrToken;
   	//return NULL;
}


void myrewind(){
	initBuffer(safe);
}

