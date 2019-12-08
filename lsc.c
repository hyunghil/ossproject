#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

int rmdirs(const char *path, int is_error_stop)
{
	DIR* dir_ptr = NULL;
	struct dirent *file =NULL;
		struct stat buf;
		char filename[1024];
	
	if((dir_ptr = opendir(path)) == NULL){
		return unlink(path);
	}
	
	while((file = readdir(dir_ptr)) != NULL) {
		if(strcmp(file ->d_name,".")==0 || strcmp(file->d_name,"..")==0)
		{
			continue;
		}
		sprintf(filename,"%s/%s",path,file->d_name);

		if(lstat(filename, &buf)==-1){
			continue;
		}
		if(S_ISDIR(buf.st_mode))
		{
			if(rmdirs(filename,is_error_stop) == -1 && is_error_stop)
			{
				return -1;
			}
		}
			else if(S_ISREG(buf.st_mode) || S_ISLNK(buf.st_mode)){
				if(unlink(filename)==-1&&is_error_stop){
					return -1;
				}
			}
		}
	
		closedir(dir_ptr);
		return rmdir(path);
}

int main()
{
	char val[256];
	char buf[256];	
	char un[256];
	char al[256];
	char al2[256];
	FILE *p1;
	FILE *p2;
	char acc1[128];
	char acc2[128];

		printf("Please enter the file you want to find : ");
		scanf("%s",val);
		sprintf(buf,"find %s",val);
		p1 = popen(buf,"r"); // Practice 'find val.*'
		fgets(acc1, 128,p1);	
		if(strncmp(acc1,"find:",5)!=0) // if it doesn't exist, take it to the next level
		{
					
			system("mkdir ZIP"); // make a derectory, name=ZIP
		       	sprintf(al,"unzip *.zip -d/home/ZIP");
			for(int i=0;i<10;i++){
			system(al); // unzipe *.zip
			}
			system("cd ZIP"); // Access in derectory ZIP
			
			
			p2 = popen(buf,"r"); // Practice 'find val.*'
			fgets(acc2,128,p2);
			if(strncmp(acc2,"find:",5)!=0)
			{
				printf("File not exist");
			}
			else
			{
				
				printf("Found: %s",acc2);
			}
			printf("Please enter the username /home/**** ");
			scanf("%s",un);
			sprintf(al2,"mv %s /home/%s/",val,un);
			system(al2); // move present derectory
		
		
		}
		else
		{

			printf("Found: %s",acc1);
		}

	return 0;
}
