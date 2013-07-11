#include <stdlib.h>
#include <stdio.h>
#define N  11

int main()
{
	FILE *oldfp, *newfp;
	
	float oldtime[N];
	float newtime[N];

	oldfp = fopen("old","r");
	newfp = fopen("new","r");
	
	int i;
	printf("aligned ....(maxlen<reallen)\n");

	for(i=0;i<N;i++)
	{
		fscanf(oldfp,"%f",&oldtime[i]);
		fscanf(newfp,"%f",&newtime[i]);
		
	}


	for(i=0;i<N;i++)
	{
		printf("old :%20.2f ,new:%20.2f per=%10.5f \n",oldtime[i],newtime[i],(double)(oldtime[i] - newtime[i])/oldtime[i]);

	}	

	printf("aligned ....(maxlen>reallen)\n");

	for(i=0;i<N;i++)
	{
		fscanf(oldfp,"%f",&oldtime[i]);
		fscanf(newfp,"%f",&newtime[i]);
		
	}


	for(i=0;i<N;i++)
	{
		printf("old :%20.2f ,new:%20.2f per=%10.5f \n",oldtime[i],newtime[i],(double)(oldtime[i] - newtime[i])/oldtime[i]);

	}	

	printf("unaligned....(maxlen<reallen)\n");
	for(i=0;i<N;i++)
	{
		fscanf(oldfp,"%f",&oldtime[i]);
		fscanf(newfp,"%f",&newtime[i]);
		
	}


	for(i=0;i<N;i++)
	{
		printf("old :%20.2f ,new:%20.2f per=%10.5f \n",oldtime[i],newtime[i],(double)(oldtime[i] - newtime[i])/oldtime[i]);

	}	

	printf("unaligned....(maxlen>reallen)\n");
	for(i=0;i<N;i++)
	{
		fscanf(oldfp,"%f",&oldtime[i]);
		fscanf(newfp,"%f",&newtime[i]);
		
	}


	for(i=0;i<N;i++)
	{
		printf("old :%20.2f ,new:%20.2f per=%10.5f \n",oldtime[i],newtime[i],(double)(oldtime[i] - newtime[i])/oldtime[i]);

	}	



	return 0;
}

