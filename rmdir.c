#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int rmdirs(const char *path, int is_error_stop)
{
	    DIR *  dir_ptr      = NULL;
	    struct dirent *file = NULL;
	    struct stat   buf;
	    char   filename[1024];

			 // 압축 파일 해제 목록을 읽을 디렉토리명으로 DIR *를 return 받는다. 

           if((dir_ptr = opendir(path)) == NULL) {
				    		/* path가 디렉토리가 아니라면 삭제하고 종료합니다. */
				    		return unlink(path);
						    }
			 /* 디렉토리의 처음부터 파일 또는 디렉토리명을 순서대로 한개씩 읽습니다. */ 
			    while((file = readdir(dir_ptr)) != NULL) { 

			 if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) { 
							          continue;  }
            // READDIR read되는 파일명 중에 현재 DIR를 나타네는 . 도 포함되어 있으므로  
	    // 무한loop에 빠지지 않으려면 파일명이 . 이면 skip한다. 
	             
	                     sprintf(filename, "%s/%s", path, file->d_name); 
	                             /* 파일의 속성(파일의 유형, 크기, 생성/변경 시간 등을 얻기 위하여 */ 
	                               
	                      if(lstat(filename, &buf) == -1) { 
	                                                    continue; } 
			        if(S_ISDIR(buf.st_mode)) 
					 {  /* 검색된 파일이 DIR 이면 조건문, 재귀함수로 하위 DIR를 다시 검색 */
							 
				           if(rmdirs(filename, is_error_stop) == -1 && is_error_stop)
				           { return -1; }
					  }	 
				 else if(S_ISREG(buf.st_mode) || S_ISLNK(buf.st_mode)) { // 일반파일 또는 symbolic link 이면 
					 if(unlink(filename) == -1 && is_error_stop) { 
						                  return -1; 
								              } 
					  } 

                                }
			              /* open된 directory 정보를 close */ 
			              closedir(dir_ptr); 

				      return rmdir(path); 
				       } 
 
 
                       int main(int argc, char *argv[]) 

                      	 { 
		      return rmdirs("./backup", 1); /* 디렉토리 하위의 모든 파일 및 디렉토리를 삭제합니다.*/

		       } 

 
          
            

								            
