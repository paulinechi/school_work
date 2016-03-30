#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

char *buffer;
int bsize;
char *safe;
char *offence;
char *stars = "***";
char *clean;


//initialize the private parse.c buffer with the string passed in the parameter inputLine
//This function returns a 1 if there are still more tokens in the string, otherwise it returns 0. For example, if this is a string "my name is Bob", then this string has 4 tokens

void clear(){
	offence[0]='\0';
}

void initBuffer(char *inputLine){
	int len = strlen(inputLine);
	buffer = (char *)malloc(len);
	strcpy(buffer,inputLine);
 
	//safe = inputLine;
	safe = (char *)malloc(len);
	strcpy(safe,inputLine);

	offence = (char *)malloc(len + 20);
        strcpy(offence,"\0");
	
	clean = (char *)malloc(len + 20);
        strcpy(clean,offence); 

}

BOOLEAN hasNextToken(){
	bsize = strlen(buffer);
	if((char)buffer[0]=='\0'){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

//seperate into tokens
char *nextToken(){

	if(hasNextToken()){
		char *ignore = " !.\r\n\0";
		//
		char *first;
		first = strsep(&buffer,ignore);
		return first;
	}
	else{
		return NULL;
	}
}

//use pointer to seperate tokens, not as efficient as former one so remove this method 
//	int line_num = 1;
//	char *arrToken; 
//	FILE *fp;
//	char temp[512];	

//	int i = 0; 	//initialize the array size to zero
		
	//while(!isspace(buffer + i))
//	if((buffer!=NULL)&&(isspace(buffer + i))){
//		char nextToken[i];
//		int j;
//		for(j = 0;j < i;j=j+1){
//			nextToken[j] =*buffer;
//			buffer+=1;
//			bsize-=1;
//		} 	
//	}
//	else if(buffer==NULL){
//		arrToken = NULL;	
//	}
//	else{
//		i+=1;
		//increase i so can point to the next element to check if it is space
//	}	

//	return arrToken;
   	//return NULL;
//}


void myrewind(){
	strcpy(buffer,safe);
}


