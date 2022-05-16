#include<sys/stat.h>
#include<stdio.h>

int main(int argc, char* argv[]){
  struct stat stat_buf;
  int flag = 0;

  if(argc > 2 || argc < 0){
    printf("Maximum of one argument required !");
    return 0;
  }

  if((stat(argv[1],&stat_buf)) != 0){
    printf("Error !");
    return 0;
  }
  printf("File %s is of %d bytes ",argv[1],stat_buf.st_size);
  return 0;
}
