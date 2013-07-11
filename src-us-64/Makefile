all:strnlen strpbrk  strspn wcsnlen wcspbrk

CFLAGS=-O3 -mabi=64 -c
CC=gcc
CLIB=../libc/libc_us.a
AR=ar cr

strnlen:strnlen.o
	$(CC) $(CFLAGS) strnlen.c
strpbrk:strpbrk.o
	$(CC) $(CFLAGS) strpbrk.c
	$(AR) $(CLIB) strpbrk.o
wcspbrk:wcspbrk.o
	$(CC) $(CFLAGS) wcspbrk.c
	$(AR) $(CLIB) wcspbrk.o
strspn:strspn.o
	$(CC) $(CFLAGS) strspn.c
wcslen:wcslen.o
	$(CC) $(CFLAGS) wcslen.c

clean:
	-rm *.o *~
