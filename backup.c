#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//step1
int backup(){
				  	   	
	char *BackupSource = getenv("BackupSource");
	char *BackupDestination = getenv("BackupDestination");
	char *BackupTime = getenv("BackupTime");

	time_t rawtime;
	struct tm *info;
	char buffer[500];

//	time( &rawtime );
//	info = localtime( &rawtime );
//	printf("Current local time and date: %s", asctime(info));

//	return(0);


//step 2
// $./a.out &

//step 3
//the backup algorithm
//while(loop forever)
while(1)
{
	rawtime=time(NULL);
	info=localtime(&rawtime);
	strftime(buffer, 499, "%H:%M", info);
	if(strcmp(buffer,BackupTime)!=0){
		sleep(60);
	}
	else{
		system("cd $BackupSource; cp * $BackupDestination");
	}
}
	return 0;

}
