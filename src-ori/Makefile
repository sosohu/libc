all:strnlen strpbrk strspn wcsnlen wcspbrk

CFLAGS=-O3 -mabi=64 -c
CC=gcc
CLIB=../libc/libc_origin.a
AR=ar cr

strnlen:strnlen.o
	$(CC) $(CFLAGS) strnlen.c
strpbrk:strpbrk.o
	$(CC) $(CFLAGS) strpbrk.c
	$(AR) $(CLIB) strpbrk.o
strspn:strspn.o
	$(CC) $(CFLAGS) strspn.c
wcslen:wcslen.o
	$(CC) $(CFLAGS) wcslen.c
wcspbrk:wcspbrk.o
	$(CC) $(CFLAGS) wcspbrk.c
	$(AR) $(CLIB) wcspbrk.o

clean:
	-rm *.o *~
