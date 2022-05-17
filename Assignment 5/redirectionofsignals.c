#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
void sighup();
void sigint();
void sigquit();
void main()
{ int pid,file,n;
char command[80],t1[20],t2[20],t3[20],t4[20];
printf("NewShell$");
fflush(stdin);
fgets(command,80,stdin);
if ((pid = fork()) < 0)
{ perror("fork");
exit(1);
}
if (pid == 0)
{ signal(SIGHUP, sighup);
signal(SIGINT, sigint);
signal(SIGQUIT, sigquit);
for (;;) ;
}
else { /* parent */
printf("\nPARENT: sending SIGHUP\n\n");
kill(pid, SIGHUP);
sleep(5);
printf("\nPARENT: sending SIGINT\n\n");
kill(pid, SIGINT);
file = open("a.c", O_CREAT|O_WRONLY, S_IRWXU);
if(file){ dup2(file, 1); system(command); }
sleep(3);
printf("\nPARENT: sending SIGQUIT\n");
kill(pid, SIGQUIT);
sleep(5);
}
}
// sighup() function definition
void sighup()
{ signal(SIGHUP, sighup); /* reset signal */
printf("CHILD: I have received a SIGHUP\n");

}
// sigint() function definition
void sigint()
{ signal(SIGINT, sigint); /* reset signal */
printf("CHILD: I have received a SIGINT\n"); }

// sigquit() function definitions
void sigquit()
{ printf("\nParent killed child ..");
exit(0);
}
