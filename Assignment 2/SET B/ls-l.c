#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid;
	pid=fork();
	if(pid<0)
	{
		//fail
		printf("fork failed");
		exit(-1);
	}
	else if(pid==0)
	{
		//child is executing
		execlp("/bin/ls","ls","-l",NULL);
	}
	else
	{
		//parent is executing
		wait(NULL);
		printf("Child Complete");
		exit(0);
	}
}
