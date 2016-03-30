#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parse.h"
#define BOOLEAN int 
#define TRUE 1
#define FALSE 0
//change true and false to TRUE and FALSE****************************************************
extern char *buffer;
extern char *offence;
extern char *stars;
extern char *clean;

//what does strcat do?**************************************************************
//append them together

//print the error message********************************************
void newoffence(char *token,char *separate){
	offence = strcat(offence,stars);
	offence = strcat(offence,token);
	offence = strcat(offence,separate);
	offence = strcat(offence,buffer);
}
void addoffence(char *token,char *separate){
	offence = strcat(offence,token);
	offence = strcat(offence,separate);
} 
 
int myNumeric(char *Token){
	int i=0;
	if(strcasecmp(Token,"0") == 0)
  		{ return FALSE;}
	while (Token[i] != '\0'){
		if(!isdigit(Token[i])){
			return FALSE;
		}
	i++;
	}
	return TRUE;
	}

 
BOOLEAN validM(char *str){
	int i = 0;
	int count = 0;
	int lasti = 0;

	while(str[i]!= '\0' ){
		if ( str[i] == '"'  ){
			count++;	// counts the number of "
			lasti = i; 	// remembers position of last "
		}
		i++;
	}
	if (count < 2 ){
		offence = strcat(offence,stars);
		offence = strcat(offence,buffer);
	return FALSE;
	}
	str[lasti+1] = '@';
	//@ represent some not normal characters that the user probably not going to type
	char *tok = strsep(&buffer,"@");
	addoffence(tok," ");
	
	if ( lasti == ((int)strlen(str)-2)){
		addoffence(tok," ");
		return TRUE;
	}
	printf("entire string tok=%s\n",tok);
	printf("entire buffer=%s\n",buffer);

	if (hasNextToken() == FALSE ){
		addoffence(tok," ");
		return TRUE;
	 }
		tok = nextToken();		
 
		if (buffer == NULL || strcasecmp(tok,"") == 0 )	{	
			addoffence(tok," ");
			return TRUE;
		}
		newoffence(tok," ");
		return FALSE;
	}
 
	BOOLEAN list(char *Token){
	int i = 0;
	int count = 0;
	int send = 0;

	while(buffer[i]!= '\0'){
		if(buffer[i] == ','){
			count++; 
		}
		i++; 
	}  
	 
	if(count != 0 ){
		while(send != count )
	{ 
	Token = strsep(&buffer,",");
 
	if (!isValidCommand(Token)){
		newoffence(Token,",");	
		return FALSE;	
 	}	
	addoffence(Token,",");
	send++;
	}
	}	
 
	Token = nextToken();
	//addoffence(Token," ");

	if (!isValidCommand(Token))	{
		newoffence(Token," ");
		return FALSE;	
	}
	addoffence(Token," ");	
	Token = nextToken();
	if(strcasecmp(Token,"END") != 0 ){
//	offence = strcat(offence,stars);
		newoffence(Token," ");
		return FALSE;
	}
	addoffence(Token," ");	
	if (hasNextToken() == FALSE ) {return TRUE; }
	Token = nextToken();		

	if (Token == NULL || strcasecmp(Token,"") == 0 ){	
		return TRUE;
 	}
	newoffence(Token," ");
	return FALSE;
}



//int isValidCommand(char *token);
//Returns 1 if the token is one of the valid robot commands, otherwise it returns 0.
//command is atomic -- single word,not case sensitive
//Legal commands are: TAKEASTEP, LEFT, RIGHT,PICKUP, DROP, DETECTMARKER, TURNON, and TURNOFF.
				

//isValidCommand**************************************************************
int isValidCommand(char *token){
	if ( strcasecmp(token,"TAKEASTEP") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"LEFT") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"RIGHT") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"PICKUP") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"DROP") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"DETECTMARKER") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"TURNON") == 0 ) {
		return TRUE;
	}
	if ( strcasecmp(token,"TURNOFF") == 0 ) {
		return TRUE;
	}
	else{
		return FALSE; 
	}
}



//validCommand
//int main(int argc, char *argv[]) {
//	int result, errno;

//	if(argc < 3 || argc > 3) {
//		Usage(argv[0]);
//		exit(1);
//	}

	//Use system("cls") on windows
	//Use system("clear") on Unix/Linux
//	system("clear");

//	result = Search_in_File(argv[1], argv[2]);
//	if(result == -1) {
//		perror("Error");
//		printf("Error number = %d\n", errno);
//		exit(1);
//	}
//	return(0);
//}

//void Usage(char *filename) {
//	printf("Usage: %s <file> <string>\n", filename);
//	printf("%s version 1.0 \nCopyright(c) CodingUnit.com\n", filename);
//}

//int Search_in_File(char *fname) {
//	FILE *fp;
//	int line_num = 1;
//	int find_result = 0;
//	char temp[512];
//
 //	//str contains the elements we want to check
//	//if doesn't find a match, return the line number
//	char *commands[] = {"TAKEASTEP","LEFT","RIGHT","PICKUP","DROP","DETECTMARKER","TURNON","TURNOFF"}
//	
//	//gcc users
//	if((fp = fopen(fname, "r")) == NULL) {
//		return(-1);
//	}

	//Visual Studio users
	//if((fopen_s(&fp, fname, "r")) != NULL) {
	//	return(-1);
	


	//most func done in while
	//strcasecmp() in string.h compare two string incasesensitive

	//only read one line per time and start from the first time??
	//does it goes to another line automatically???
//	while(fgets(temp, 512, fp) != NULL) {
	//	if((strstr(temp, str)) != NULL) {
//		if((strcasecmp(temp,str))!= NULL){
//			printf("A match found on line: %d\n", line_num);
//			printf("\n%s\n", temp);
//			find_result++;
//		}
//		line_num++;
//	}

	//display the line number of the offending line
	//echo the offending line
	//indicating where the error is using a marker(***before the offence)
	//display error message describing what the program expecting on a new line
	//for every line in the file

//	if(find_result == 0) {
//		printf("\nSorry, couldn't find a match.\n");
//	}
	
	//Close the file if still open.
//	if(fp) {
//		fclose(fp);
//	}
  // 	return(0);
//	}
//return 1 if token is one of the valid robot commands, otherwise return 0



//int isValidExpression(char *expression);
//Returns 1 if the expression agrees with one of the legal robot expressions,
//otherwise it returns 0.

//int Search_in_File(char *fname, char *str) {
//validExpression
//	FILE *fp;
//	int line_num = 1;
//	int find_result = 0;
//	char temp[512];
	//gcc users
	//if((fp = fopen(fname, "r")) == NULL) {
	//	return(-1);
	//}

	//Visual Studio users
//	if((fopen_s(&fp, fname, "r")) != NULL) {
//		return(-1);
//	}					

//*************************************************************************************
//1 check if starts with repeat/while/say
//if not, return 0,exit
int isValidExpression(char *expression){

char *Token = nextToken();
if (strcasecmp(Token,"REPEAT") == 0){
addoffence(Token," ");
Token = nextToken();
	if(myNumeric(Token)){
	//what's myNumberic??????????????????????????
 	addoffence(Token," ");
	Token = nextToken();
	if(strcasecmp(Token,"TIMES") == 0){
		addoffence(Token," ");
		return list(Token);
	}
	newoffence(Token," ")," ";
	//*******************why??***************************************************************
	return FALSE;
	}
	newoffence(Token," ");
	return FALSE;
}

else if (strcasecmp(Token,"WHILE")==0){
	addoffence(Token," ");
	Token = nextToken();
	if(strcasecmp(Token,"NOT")==0){
		addoffence(Token," ");
		Token = nextToken();
		if(strcasecmp(Token,"DETECTMARKER")==0){
			addoffence(Token," ");
			Token = nextToken();
				if(strcasecmp(Token,"DO")==0){
				addoffence(Token," ");
 	                    	return list(Token);
				}
		newoffence(Token," ");
		return FALSE;	
		}
 	newoffence(Token," ");
	return FALSE;	
	}
newoffence(Token," ");
return FALSE;	
}


//			Token = nextToken();
//		while(strcasecmp(Token,"END") != 0){
//			if(!isValidCommand(Token)){
//				return false;
//				//false or FALSE???????????????????????
//			}
//			//add check for int n**************************
//			if(hasNextToken() == false){
//				return false;
//			}
//		Token = nextToken();
//		}
//		if (hasNextToken() == false){
//			return true;
//		}
//		Token = nextToken();
//		if(Token == NULL || strcasecmp(Token,"") == 0){
//			return true;
//		}
//	}
//}
//return false;
//}
//**********************************************************************************
//check for while

//else if(strcasecmp(Token,"WHILE") == 0){
//Token = nextToken();
//	if(strcasecmp(Token,"NOT") == 0){
//	Token = nextToken();
//		if(strcasecmp(Token,"DETECTMARKER") == 0){
//		Token = nextToken();
//		
//		while(strcasecmp(Token,"END") != 0){
//			if(!isValidCommand(Token)){
//				return false;
//			}
//			if(hasNextToken() == FALSE){
//				return false;
//			}
//		Token = nextToken();
//		}
//		if (hasNextToken() == false){
//			return true;
//		}
//		Token = nextToken();
//		if(Token == NULL || strcasecmp(Token,"") == 0){
//			return true;
//		}
//		}
//	}
//}
			

//2 if starts with repeat
//check if format is REPEAT n TIMES comma-seperated-list-of-commands END
//if not, return 0,exit
//check token

//2 if starts with while
//check if format is WHILE NOT c DO comma-separated-list-of-commands END
//if not, return 0,exit

//2 if starts with say
//check if format is SAY "message"
//ignore whatever is inside the " "
//if not, return 0,exi
else if ( strcasecmp(Token,"SAY") == 0 ){
	addoffence(Token," "); 
	if (Token == NULL || strcasecmp(Token,"") == 0 ){
		newoffence(Token," ");
		return FALSE;
	}
	BOOLEAN VM = validM(buffer);
	if (VM){
		 return TRUE;
	}

	else{
	return FALSE;
	}
}
newoffence(Token," ");
return FALSE;
}
 






