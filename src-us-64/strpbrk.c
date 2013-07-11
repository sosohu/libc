/*********************************************************************************
 * Copyright (c) 2012 University of Science and Technology of China (PRC).
 * All rights reserved.
 *
 * This file is a part of Glibc ; before you use, modify and/or redistribute
 * it, you should get the permission from the Network Computing and 
 * High-performance Algorithm Laboratory(http://lab508.ustc.edu.cn).
 *
 * Author(s)	: Hu Qinghai<sosohu@mail.ustc.edu.cn>
 *********************************************************************************/


#include<string.h>
#undef strpbrk

#define CHECKIN(X) ((((X) + 0x7EFEFEFEFEFEFEFFL)^(~(X))) & 0x8101010101010100L)
#define MAGIC(X) (((X) - 0x0101010101010101L) & (~(X)) & 0x8080808080808080L)


/* Find the first occurrence in S of any character in ACCEPT.  */

char* 
strpbrk (s, accept)
     const char *s;
     const char *accept;
{
        unsigned long mask = sizeof(unsigned long) - 1;
	char* remain;
	char* temp_start ;
	char  temp_char[8] = "12345678";
	char* temp = temp_char;
	unsigned long xor_temp,s_temp;
	unsigned char s_char;
	unsigned long* longword_ptr;
	temp = temp + 7;
	*temp = '\0';
	while(((unsigned long)accept & mask)!= 0)
	{
		temp--;
		if((*temp = *accept) == 0)
		{  temp++;   break;	}
	        accept++;
	}
    while (*s != '\0')
    {
      s_char = (unsigned char)(*s);
      longword_ptr = (unsigned long *)accept;
      s_temp =(unsigned long)((((unsigned long)(s_char))<<8) | ((unsigned long)(s_char)));
      s_temp |= (s_temp<<16);
      s_temp |= (s_temp<<32);
      temp_start = temp;
      while((*temp_start) != '\0')
      {
         if(*s == *temp_start++)
	         return  (char*)s;
      }
      while(!MAGIC(*longword_ptr))    
	        {
                        xor_temp = (*longword_ptr)^s_temp;
                        if((xor_temp & 0xFF00000000000000)==0x8000000000000000)
	                  xor_temp = xor_temp + 0x0100000000000000;
			if(CHECKIN(xor_temp))
			{
	                  return  (char*)s;
			}
			longword_ptr++;
		}
      remain = (char*)longword_ptr;   
      while((*remain)!='\0')
	  {
	    if(*remain++ == *s)
	    {
		  return (char*)s;
	    }
	  }
	  s++;
    }
  return NULL;
}
