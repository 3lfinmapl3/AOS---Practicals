#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	DIR *d;
	struct dirent *dir; 
	struct stat stats;
	struct tm dt;
	int count=0;
	int month;

        printf("Enter a month : \n");
        scanf("%d",&month);
	
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{	
			if(stat(dir->d_name,&stats)==0)
			{
				dt=*(gmtime(&stats.st_ctime));
				if(dt.tm_mon==month)
				{
					printf("\n%s created on : %d|%d|%d on time %d:%d:%d\n",dir->d_name,dt.tm_mday,dt.tm_mon,dt.tm_year+1900,dt.tm_hour,dt.tm_min,dt.tm_sec);
				}
			}
			count++;
		}
		closedir(d);
		if(count==0)
			printf("No file found\n");
	}
	else
		printf("Error");
	return(0);
}
