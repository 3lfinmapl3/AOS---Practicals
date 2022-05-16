#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>


int main(){

  int flag = 0;
  struct tm *dirtime;
  struct stat stats;
  DIR *dir;
  struct dirent *dirp;
  int month;

  printf("Enter month  1-12 :\t");
  scanf("%d",&month);
  month--;

  dir = opendir(".");
  if(dir){
    while((dirp = readdir(dir))!=NULL ){
      if(stat(dirp->d_name,&stats)==0){
        dirtime = gmtime(&stats.st_ctime);
        if(dirtime->tm_mon == month){

          printf("File : %s \t Time : %d-%d-%d\n",dirp->d_name, dirtime->tm_mday,dirtime->tm_mon+1,dirtime->tm_year+1900);
          
        }
        
      }
    }
    if(dirp==NULL){
      printf("No more files to display in this month !");
    }
  }
  else{
    printf("Error!");
  }

  return 0;  
}
