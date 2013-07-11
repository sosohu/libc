/*********************************************************************************
 * Copyright (c) 2012 University of Science and Technology of China (PRC).
 * All rights reserved.
 *
 * This file is a part of Glibc ; before you use, modify and/or redistribute
 * it, you should get the permission from the Network Computing and
 * High-performance Algorithm Laboratory(http://lab508.ustc.edu.cn).
 *
 * Author(s)    : Hu Qinghai <sosohu@mail.ustc.edu.cn>
 *********************************************************************************/



#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
int main(int argc,char **argv)
{	
	FILE *fp,*fp1;
	int M=atoi(argv[1]);
	int Times=1000;
	char *des,*src,*result;
	struct timeval tpstart,tpend;
	float timeuse;
	int i,k=0;

	int N = atoi(argv[2]);
        int temp = N; 	
	fp = fopen(argv[3],"r");
	fp1 = fopen(argv[4],"r");

	 if(fp == NULL)
        {
                printf("error: no input file! \n");
                return -1;
        }
		
	des = malloc(N);
	src = malloc(M);
        
        for(i=0;i<N;i++)
	{
		fscanf(fp,"%d",&des[i]);
        }
	des[N-1]='\0';
        for(i=0;i<M;i++)
	{
		fscanf(fp1,"%d",&src[i]);
        }
	src[M-1]='\0';
	gettimeofday(&tpstart,NULL);
	for(k=0;k<Times;k++){
		result=strpbrk(src,des);
		}
	gettimeofday(&tpend,NULL);
	timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
	printf("%20.2f\n",timeuse);
	
	return 1;
}

