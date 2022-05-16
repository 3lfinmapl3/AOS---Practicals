#include<stdio.h>
#include<unistd.h> //Contains Pipe,write and read, and fork() sys calls 
void main(){
    
    char buff[500];
    int fd1[2],fd2[2],flag,pid;
    
    //Setting up the pipes
    flag = pipe(fd1); // will return 0 on success and -1 on failure
    if(flag < 0){printf("Error While creating a Pipe"); return;}
    else{printf("Pipe1 Successfully Created !\n");}
    flag = pipe(fd2); // will return 0 on success and -1 on failure
    if(flag < 0){printf("Error While creating a Pipe"); return;}
    else{printf("Pipe2 Successfully Created !\n");}
    
    pid = fork();
    if(pid < 0){
        printf("Child Process cannot be created !");
        return;
    }
    else if (pid == 0){
        printf("-------Child Process--------");
        close(fd1[0]);
        close(fd2[1]);
        flag = write(fd1[1],"This message is from the child !", 70);
        if(flag < 0){printf("Error writing to pipe !");return;}
        else{printf("Write Successful !\n");}
        flag = read(fd2[0],buff,70);
        if(flag < 0){printf("Error writing to pipe !");return;}
        else{printf("Write Successful !\n");}
        printf("Printing Parent message from child: %s \n",buff);
    }
    else{
         printf("-------Parent Process--------");
        close(fd1[1]);
        close(fd2[0]);
        flag = write(fd2[1],"This message is from the Parent !", 70);
        if(flag < 0){printf("Error writing to pipe !");return;}
        else{printf("Write Successful !\n");}
        flag = read(fd1[0],buff,70);
        if(flag < 0){printf("Error writing to pipe !");return;}
        else{printf("Write Successful !\n");}
        printf("Printing child message from parent: %s \n ",buff);
        
    }
    
 
    
    return;
    
}
