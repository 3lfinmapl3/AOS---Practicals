#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){

  int fd,flag;

  if((fd = open("MyTextFile.txt",O_RDWR)) < 0){
    printf("Error while opening !");
    return 0;
  }
  printf("Sleeping for 15 secs..\n");
  sleep(15);
  printf("Waking up!\n");
  printf("closing file..\n");
  close(fd);
  return 0;
}
