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
#include<wchar.h>
#undef strpbrk

#define CHECKIN(X) (~(((X) & 0xFFFFFFFF00000000LL) && ((X) & 0x00000000FFFFFFFFLL)))
//#define MAGIC(X) (((X) - 0x0101010101010101L) & (~(X)) & 0x8080808080808080L)
#define MAGIC(X) (((X) - 0x0000000100000001LL) & (~(X)) & 0x8000000080000000LL)


/* Find the first occurrence in S of any character in ACCEPT.  */

wchar_t* 
wcspbrk (s, accept)
     register const wchar_t *s;
     register const wchar_t *accept;
{
        unsigned long mask = sizeof(unsigned long) - 1;
	wchar_t* remain;
	wchar_t* temp_start ;
	wchar_t  temp_char[2] = {L'1',L'2'};
	wchar_t* temp = temp_char;
	unsigned long xor_temp,s_temp;
	wchar_t s_char;
	unsigned long* longword_ptr;
	temp = temp + 1;
	*temp = L'\0';
	while(((unsigned long)accept & mask)!= 0)
	{
		temp--;
		if((*temp = *accept) == 0)
		{  temp++;   break;	}
	        accept++;
	}
    while (*s != L'\0')
    {
      s_char = (wchar_t)(*s);
      longword_ptr = (unsigned long *)accept;
      s_temp =(unsigned long)((((unsigned long)(s_char))<<32) | ((unsigned long)(s_char)));
      temp_start = temp;
      while((*temp_start) != L'\0')
      {
         if(*s == *temp_start++)
	 {
	         return  (wchar_t*)s;
	 }
      }
      while(!CHECKIN(*longword_ptr))    
	        {
                        xor_temp = (*longword_ptr)^s_temp;
			if(CHECKIN(xor_temp))
			{
			  //printf("%0x\n",*s);
			  //printf("%0x\n",xor_temp);
			  //printf("%0x\n",xor_temp>>32);
	                  return  (wchar_t*)s;
			}
			longword_ptr++;
		}
      remain = (wchar_t*)longword_ptr;   
      while((*remain)!=L'\0')
	  {
	    if(*remain++ == *s)
	    {
		  return (wchar_t*)s;
	    }
	  }
	  s++;
    }
  return NULL;
}
