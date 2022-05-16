#include<stdio.h>
#include<unistd.h> //Contains Pipe,write and read functions
void main(){
    
    char buff[500];
    int fd[2],flag;
    
    flag = pipe(fd); // will return 0 on success and -1 on failure
    if(flag < 0){printf("Error While creating a Pipe"); return;}
    else{printf("Pipe Successfully Created !\n");}
    
    flag = write(fd[1],"This is convey that a message has been written and read from pipe !", 100); // will return number of bytes written on success and negative on failure
    if(flag < 0){printf("Error writing to pipe !");return;}
    else{printf("Write Successful !\n");}
    
    flag = read(fd[0],buff,100); // will return number of bytes read  on success and negative on failure
    if(flag < 0){printf("Error while reading from pipe !");return;}
    else{printf("Read Successful \n");}
    
    printf("Message read from Buffer : %s \n",buff);
    
    return;
    
}
