#include<stdio.h>
#include<sys/times.h>
#include<stdlib.h>
#include<unistd.h>
static void pr_times(clock_t real,struct tms *tmsstart,struct tms *tmsend)
{
  static long clktck = 0;
  if(clktck == 0)
  if((clktck = sysconf(_SC_CLK_TCK))<0)
      printf("sysconf error");
  printf("%ld\n",clktck);
  printf("real=%7.2f\n",(real/(double)clktck));
  printf("CU END=%7.2f\n",tmsend->tms_cutime);
  printf("CU START=%7.2f\n",tmsstart->tms_cutime);
  printf("Cs END=%7.2f\n",tmsend->tms_cstime);
  printf("Cs START=%7.2f\n",tmsstart->tms_cstime);
  printf("Child spent %7.2f time in user mode\n",(tmsend->tms_cutime-tmsstart->tms_cutime)/(double)clktck);
  printf("Child spent %7.2f time in kernel mode\n",(tmsend->tms_cstime-tmsstart->tms_cstime)/(double)clktck);
}
 int main()
{
  int n,i;
  printf("How many children processes:-");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
       struct tms tmsstart,tmsend;
       clock_t start,end;
       if(fork()==0)
       {
         if((start == times(&tmsstart))==-1)
            printf("time error");
         if((end == times(&tmsend))==-1)
            printf("time error");

	 static long clktck=0;
	 if(clktck == 0)
  	 if((clktck = sysconf(_SC_CLK_TCK))<0)
      	 	printf("sysconf error");
      	 printf("[child %d]pid %d from [parent]pid %d\n",i,getpid(),getppid());
      	 printf("User CPU time,END=%7.2f\n",&tmsend.tms_cutime);
      	 printf("User CPU time,START=%7.2f\n",&tmsstart.tms_cutime);
      	 printf("System(Kernel)CPU time,END=%7.2f\n",&tmsend.tms_cstime);
     	 printf("System(Kernel)CPU time,START=%7.2f\n",&tmsstart.tms_cstime);
     	 printf("Child spent %7.2f time in user mode\n",(tmsend.tms_cutime-tmsstart.tms_cutime)/(double)clktck);
      	 printf("Child spent %7.2f time in kernel mode\n",(tmsend.tms_cstime-tmsstart.tms_cstime)/(double)clktck);
    
      	 exit(0);
      }
 }
 for(i=0;i<n;i++)
 {
   wait(NULL);
 }
}
