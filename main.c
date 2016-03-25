#include<stdio.h>
#include "syntax.h"
#include "parse.h"
#include <stdlib.h>
/*check it's .txt

Verify the filename passed is 4 characters or longer (if not, it's too short to have that extension), then do a strcmp (or stricmp to allow *.TXT, *.tXT etc., since Windows isn't case sensitive about this stuff) between the last four characters of the filename and ".txt". Note: On Windows, there is a PathFindExtension function that can do the heavy lifting of finding the beginning of the extension for a file for you.
*/


//check no space
//can contain path
//why there's ./a.out in the front??? should the user typed in ./a.out as well???

int checkFileName(char *str){
	
	char fileName[1000];
	//create an array to hold value of file name 

	printf("Enter file name: ");
	scanf("%s",fileName);

	int n = sizeof(fileName);

	int i = strcasecmp(fileName[n-1],t);
	int j = strcasecmp(fileName[n-2],x);
	int k = strcasecmp(fileName[n-3],t);
	int m = strcasecmp(fileName[n-4],'.');
	
	if(i==0 && j==0 && k==0 && m==0){
		return 1;
	//if ends with .txt return1
	} 				
	printf("Wrong format. File name should be a string with no space, the file name can be just the name of a file or the name of a file with a path. It should be a text file. ");
	exit(0);
	//return 0;
	//if not, terminate and display error message  

}







