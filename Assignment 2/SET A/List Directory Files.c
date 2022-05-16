#include<stdio.h>
#include<dirent.h>

int main(){

  struct dirent *dirp;
  DIR *dir;
  int i=0;
  dir = opendir(".");
  if(dir){
    while((dirp = readdir(dir))!=NULL){
      printf("%s\n",dirp->d_name);
      i ++ ;
    }
    printf("Number of files : %d",i);
  }
  else{
    printf("Error\n");
  }
  
  return 0;
}
