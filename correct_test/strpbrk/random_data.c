#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define N 1024

int main()
{
	int i;
	char data;
	struct timeval r_time;
	char ch;

	gettimeofday(&r_time, NULL);
	
	srand(1000000*(r_time.tv_sec)+r_time.tv_usec);
	//	input data of the destination buffer
	for(i = 0;i < N;i++)
	{
		ch = rand()%0x100;
		if(!ch)	ch++;
		printf("%d ", ch);
	}
	printf("\n");
	// input data of the source buffer
	for(i = 0;i < N;i++)
	{
		ch = rand()%0x100;
		if(!ch)	ch++;
		printf("%d ", ch);
	}

	return 0;
}

