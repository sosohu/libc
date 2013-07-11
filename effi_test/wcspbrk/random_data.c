#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <wchar.h>
#define N 65535

int main()
{
	long i;
	wchar_t data;
	struct timeval r_time;
	wchar_t ch;

	gettimeofday(&r_time, NULL);
	
	srand(1000000*(r_time.tv_sec)+r_time.tv_usec);
	//	input data of the destination buffer
	for(i = 0;i < N;i++)
	{
		ch = rand();
		if(!ch)	ch++;
		printf("%d ", ch);
	}
	// input data of the source buffer
	for(i = 0;i < N;i++)
	{
		ch = rand();
		if(!ch)	ch++;
		printf("%d ", ch);
	}

	return 0;
}

