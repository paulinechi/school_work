#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


//step1

int main(){

	char *BackupSource = getenv("BackupSource");
	char *BackupDestination = getenv("BackupDestination");
	char *BackupTime = getenv("BackupTime");
//printf("22");
	if(BackupTime==NULL || BackupDestination==NULL || BackupSource==NULL){
		exit(1);
	}

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

//printf("testing");

while(1)
{
	rawtime=time(NULL);
	info=localtime(&rawtime);
	strftime(buffer, 499, "%H:%M", info);
	if(strcmp(buffer,BackupTime)!=0){
		sleep(60);
	}
	else{
		//testing purpose
		//printf("copying file...");

		//can ; works?? does it has to be on one line??
		system("cd $BackupSource; cp -r *.* $BackupDestination");
		//system(cp -r *.* BackupSource BackupDestination);



	}
}
	return 0;

//}


}
