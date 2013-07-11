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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

#undef N
#define N 1024

int main(int argc, char **argv)
{
	int i,bsize;
	wchar_t* src=(wchar_t *)malloc(N*sizeof(wchar_t));
	wchar_t* dst=(wchar_t *)malloc(N*sizeof(wchar_t));
        wchar_t* temp_src;
	wchar_t* temp_dst;
	wchar_t temp_a,temp_b;
	wchar_t* ret;
	FILE *fp;
	int maxlen =  atoi(argv[2]);
	//file read
	fp = fopen(argv[1], "r");	
	if(fp == NULL)
	{
		printf("error: no input file! \n");
		return -1;
	}
	//initialization
	for(i = 0;i < N;i++)
	{
		fscanf(fp, "%d", &dst[i]);
	}
	for(i = 0;i < N;i++)
	{
		fscanf(fp, "%d", &src[i]);
	}

        for(bsize = 0; bsize < N - maxlen; bsize++)
	{
	    temp_src = src;
	    temp_dst = dst;
	    temp_a = temp_src[bsize+maxlen];
	    temp_b = temp_dst[bsize+maxlen];
	    temp_src[bsize+maxlen] = L'\0';
	    temp_dst[bsize+maxlen] = L'\0';
	    ret = wcspbrk(temp_src+bsize,temp_dst+bsize);
	    src[bsize+maxlen] = temp_a;
	    dst[bsize+maxlen] = temp_b;
	    if(ret == NULL)
		    printf("No exist the one ");
	    else
	    printf("%d ",*ret);
	}
    return 0;
}

