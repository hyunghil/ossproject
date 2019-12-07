#include<stdio.h>
#include<direct.h>
#include<errno.h>
#include<string.h>
#define MAX 1024
#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif


int mkdir( const char *zips){ // make dir
	char strFolderPath[] = { "D:\\CreateFolder"};

	int nResult = mkdir( str Folderpath );

	if( nResult = 0)
	{
		printf( " Successfully created a directory. \n");
	}
	else if( nResult = -1)
	{
		perror( " Failed to create directory  \n");
		printf( "errorno : $d, errno \n");
	}



int chdir( const char *zips){  //move dir 
	

	char strBuffer[_MAX_PATH] = {0,};
	char strChangeDir[_MAX_PATH] = { "C:\\Windows"};

	int nResult = chdir( strChangeDir);

	if( nResult == 0)
	{
		printf( " move zips directory  \n");
	}
	else if ( nResult == -1)
	{
		perror(" error can't move zipfile ");
	}
	return 0;
}

int retToken(char * ori[],char* ptr){  //char adress
        int i = 0;

	char* ptr = strtok(inp, ";");
	while(ptr !=NULL){
	ori[i] = ptr;
	ptr = strtok(NULL,";");
	i++;
	}
    return i;
}

	
int unzip(

int main(){

	FILE *fp; //file pointer
	int index, data;
	char* inp;
	int buf_size = MAX*MAX;
	char* ptr;
	char* ori[MAX];

	fp = fopen("temp1.txt","r");

	inp = malloc(buf_size);

	while(fgets(inp,buf_size,fp)){
	index = retToken(ori,inp);
	}

	for(data = 0; data < index; data++){
		printf("%s\n",ori[data]);
	}
	fclose(fp);
}


	
	

