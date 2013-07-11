/*********************************************************************************
 * Copyright (c) 2011 University of Science and Technology of China (PRC).
 * All rights reserved.
 *
 * This file is a part of Glibc ; before you use, modify and/or redistribute
 * it, you should get the permission from the Network Computing and
 * High-performance Algorithm Laboratory(http://lab508.ustc.edu.cn).
 *
 * Author(s)    : Yu Shixiang <ysx053@mail.ustc.edu.cn>
 *********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#undef N
#define N 1024

int main(int argc, char **argv)
{
	int bsize;
	int i,m,n;
	int ret;
	char *dst=(char *)malloc(N*sizeof(char));
	char *dst1=(char *)malloc(N*sizeof(char));
	FILE *fp;
	int maxlen;
	

	fp = fopen(argv[1], "r");	
	if(fp == NULL)
	{
		printf("error: no input file! \n");
		return -1;
	}

	maxlen=atoi(argv[2]);

	//initialization
	for(i = 0;i < N;i++)
	{
		fscanf(fp, "%d", &dst[i]);
		dst1[i] = dst[i];
	}


	for(bsize = 0; bsize < 256;bsize++)
	{
		/* every buffer size 0~256 */
			for(m = 0; m < 8;m++)
			/* every start address of dest 4n+x, x=0~3 */
				{
					dst[m+bsize] = '\0';
					ret = strnlen(dst+m,maxlen);

					printf("%d ", ret);

					for(i = 0;i < N;i++)
						printf("%d ", dst[i]);
					for(i = 0;i < N;i++)
					{
						dst[i] = dst1[i];
					}

				}
	}
	return 0;
}

