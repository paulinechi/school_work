#include<stdio.h>
#include "syntax.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h>
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

extern char *buffer;
extern char *offence;
extern char *stars;
extern char *clean;
//what is extern??**************************************************


//check filename
int main(int argc, char *argv[]){
	if (argv[1] == NULL ){
		printf("No filename or a valid path entered.\n");
		return 1;
	}
	if (argv[2] != NULL ){
		printf("Please only enter a filename or a valid path.\n");
		return 1;
	}


//check no space
//can contain path
//why there's ./a.out in the front??? should the user typed in ./a.out as well???


//using fopen to check file if valid, if return null it's invalid
int counter = 0;
FILE *file_ptr;
char line[300];
char *line_ptr;
line_ptr = line; 
file_ptr = fopen(argv[1] ,"rt");
//check if the file is readable 
 
if(file_ptr == NULL){
	printf("Please type in a valid file or path.\n");
	return 1;
}

char *ftoken;
fgets(line,299,file_ptr);
counter++;
while(!feof(file_ptr)){
	initBuffer(line_ptr);
	ftoken = nextToken(); 
	printf("Line %d \n",counter);
	
	//validCommend
	BOOLEAN VC = isValidCommand(ftoken);
	BOOLEAN VCcheck = TRUE;

 
	if(VC == TRUE){
		addoffence(ftoken," ");
		ftoken = nextToken();
		if (ftoken == NULL || strcasecmp(ftoken,"") == 0 ){
			VCcheck = TRUE;
			printf("		COMMAND VALID\n");
		}
		else {
			VCcheck = FALSE;
			newoffence(ftoken);
		}
	} 
	myrewind();
	if( VC == TRUE && VCcheck == FALSE){  
	//offence go to next line 
		printf("message prototype:\nShould be a valid command or expression.\n");
	}
	if (VC == FALSE){ 
	// call VE 
			
		BOOLEAN VE = isValidExpression(buffer);
		if(VE == FALSE ){
		//if ve true go to next line 
		// if ve is false print do offence and go to next line 

			printf("message prototype:\nOn Line %d: %s \nShould be a valid command or expression.\n",counter, offence);
		}
		// end of if ve is false 
		else{
			printf("		EXPRESSION VALID !\n");
		}
	}
	myrewind();
	printf("offence : %s\n",offence);
	fgets(line,299,file_ptr);
	counter++;
}
fclose(file_ptr);
}





