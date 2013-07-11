

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main()
{
        int i;
        char data;
        struct timeval r_time;
        char ch;

        gettimeofday(&r_time, NULL);

        srand(1000000*(r_time.tv_sec)+r_time.tv_usec);
       for(i = 0;i < 100000;i++)
        {
                ch = rand()%0x100;
                if(!ch) ch++;
                printf("%d ", ch);
        }

        return 0;
}

