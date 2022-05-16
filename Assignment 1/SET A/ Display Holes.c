#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    
    int fd,flag;
    char *str1 = "This File Demonstrates Holes";
    fd = creat("MyTextFile.txt",O_RDWR); // will return fd of the file specified
    
    
    //Changing file permission
    system("chmod 777 MyTextFile.txt");
    
    //write to file
    flag = write(fd,str1,28);
    if(flag < 0){
        printf("Error occured !");
        return 0;
    }
    else
    {
        printf("Successfully written\n");
    }
    
    //cursor moving to 30 spaces forward
    lseek(fd,70,SEEK_SET);
    flag = write(fd,str1,28);
    if(flag < 0){
        printf("Error occured !");
        return 0;
    }
    else
    {
        printf("Successfully written\n");
    }
    
    
    system("od -c MyTextFile.txt");
    return 0;
}
