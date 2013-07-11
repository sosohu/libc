#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv)
{
	FILE *oldfp, *newfp;
        int N = atoi(argv[1]);	
	float oldtime[100];
	float newtime[100];

	oldfp = fopen("old","r");
	newfp = fopen("new","r");
	
	int i;
	printf("time compare:old\\new\n");

	for(i=0;i<10;i++)
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

