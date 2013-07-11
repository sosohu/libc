/*********************************************************************************
 * Copyright (c) 2011 University of Science and Technology of China (PRC).
 * All rights reserved.
 *
 * This file is a part of Glibc ; before you use, modify and/or redistribute
 * it, you should get the permission from the Network Computing and
 * High-performance Algorithm Laboratory(http://lab508.ustc.edu.cn).
 *
 * Author(s)    : Yu shixiang <ysx053@mail.ustc.edu.cn>
 *********************************************************************************/



#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
int main(int argc,char **argv)
{	
	FILE *fp;
	int N=atoi(argv[1]);
	int Times=1000;
	char *des;
	struct timeval tpstart,tpend;
	float timeuse;
	int i,result,k=0;

	int offset = atoi(argv[2]);	
	fp = fopen(argv[4],"r");
	size_t maxlen = atoi(argv[3]);	

	 if(fp == NULL)
        {
                printf("error: no input file! \n");
                return -1;
        }

	des = malloc(N);

        for(i=0;i<N;i++){

		fscanf(fp,"%d",&des[i]);
                }
		des[N-1]='\0';
	gettimeofday(&tpstart,NULL);
	for(k=0;k<Times;k++){
		result=strnlen(des+offset,maxlen);
		}
	gettimeofday(&tpend,NULL);
	timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
	printf("%20.2f\n",timeuse);
	return 1;
}

