#include <stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{ int counter,i,j,temp,res[10];
char *fname[argc],*temp2[argc];
printf("Unsorted files \n");
for(i=1;i<argc;i++)
{ int fd,of;
fd=open(argv[i],O_RDONLY);
of=lseek(fd,0,SEEK_END);
res[i]=of;
printf("%s\t%d\n",argv[i],of);
fname[i] = strdup(argv[i]);
}
for(i=1;i<argc;i++)
{ for(j=i+1;j<argc;j++)
{ if(res[i]>res[j])
{ temp=res[i];
res[i]=res[j];
res[j]=temp;
strcpy(temp2,fname[i]);
strcpy(fname[i],fname[j]);
strcpy(fname[j],temp2);
}
}
}
printf("Files in ascending order according to their sizes\n");
for(i=1;i<argc;i++)
{ printf(" %d %d %s\n",i,res[i],fname[i]);
}
return 0;

}
