#include<stdio.h>
#include<stdlib.h>

void functionA()
{
	printf("this is function A\n");
}
void functionB()
{
	printf("this is function B\n");
}
int main()
{
	if((atexit(functionA)!=0)||(atexit(functionB)!=0))
		printf("cant register atexit");
	atexit(functionA);
	atexit(functionB);
	printf("starting main program...\n");
	printf("exiting main program...\n");
	return(0);
}
