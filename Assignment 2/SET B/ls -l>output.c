#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>

void sfile(char const filename[]);

char *formatdate(char *str,time_t val)
{
	strftime(str,36,"%d,%m,%Y,%H,%M,%S",localtime(&val));
	return str;
}

int main()
{
	ssize_t read;
	char *buffer=0;
	size_t buf_size=0;
	printf("Enter name of file to check : ");
	read=getline(&buffer,&buf_size,stdin);
	if(read<=0)
	{
		printf("Getline Failed");
		exit(1);
	}
	if(buffer[read-1]=='\n')
		buffer[read-1]=0;

	int s=open(buffer,O_RDONLY);
	if(s==-1)
	{
		printf("File does not exist!");
		exit(1);
	}
	else
	{
		sfile(buffer);
	}
	free(buffer);
	return(0);
}

void sfile(char const filename[])
{
	struct stat sfile;
	char date[36];
	if(stat(filename,&sfile)==-1)
		printf("Error..Exiting");
	printf("\n");
	printf("Access Time :  %s\n",formatdate(date,sfile.st_atime));
	printf("Modify Time :  %s\n",formatdate(date,sfile.st_mtime));
	printf("Change Time :  %s\n",formatdate(date,sfile.st_ctime));

	printf("\n");
	//Accessing data members of stat stuct
	printf("File st_ino     : %d\n",sfile.st_ino);
	printf("File st_mode    : %o\n",sfile.st_mode);
	printf("File st_atime   : %s\n",formatdate(date,sfile.st_atime));
	printf("File st_uid     : %d\n",sfile.st_uid);
	printf("File st_blksize : %d\n",sfile.st_blksize);
	printf("File st_gid     : %d\n",sfile.st_gid);
	printf("File st_blocks  : %d\n",sfile.st_blocks);
	printf("File st_size    : %d\n",sfile.st_size);
	printf("File st_nlink   : %u\n",(unsigned)sfile.st_nlink);

	printf("\nFile Permission : User\n");
	printf((sfile.st_mode & S_IRUSR)?"r":"-");
	printf((sfile.st_mode & S_IWUSR)?"w":"-");
	printf((sfile.st_mode & S_IXUSR)?"x":"-");

	printf("\nFile Permission : Group\n");
        printf((sfile.st_mode & S_IRGRP)?"r":"-");
        printf((sfile.st_mode & S_IWGRP)?"w":"-");
        printf((sfile.st_mode & S_IXGRP)?"x":"-");
	
	printf("\nFile Permission : Other\n");
        printf((sfile.st_mode & S_IROTH)?"r":"-");
        printf((sfile.st_mode & S_IWOTH)?"w":"-");
        printf((sfile.st_mode & S_IXOTH)?"x":"-");
	printf("\n");
}














