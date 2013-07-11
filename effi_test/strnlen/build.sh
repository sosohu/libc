#/bin/sh
echo $1

gcc -o random_data random_data.c
gcc -o count count.c 

gcc -mabi=64 -o strnlen_new eff_strnlen.c ../../libc/libc_us.a 
gcc -mabi=64 -o strnlen_origin eff_strnlen.c ../../libc/libc_origin.a 

newfunc=strnlen_new
oldfunc=strnlen_origin

echo "random data produce ..."
./random_data > input

echo "aligned....(maxlen<reallen)"
echo "old C:"
./$oldfunc 64 0 32 input > old
./$oldfunc 128 0 64 input >> old
./$oldfunc 256 0 128 input >> old 
./$oldfunc 512 0 256 input  >> old
./$oldfunc 1024 0 512 input >> old
./$oldfunc 2048 0 1024 input >> old 
./$oldfunc 4096 0 2048 input >> old
./$oldfunc 8192 0 4096 input >> old
./$oldfunc 16384 0 8192 input >> old
./$oldfunc 32768 0 16384 input >> old 
./$oldfunc 65536 0 32768 input >> old 

#./$oldfunc 64 0 60 input > old
#./$oldfunc 128 0 120 input >> old
#./$oldfunc 256 0 250 input >> old 
#./$oldfunc 512 0 500 input  >> old
#./$oldfunc 1024 0 1020 input >> old
#./$oldfunc 2048 0 2040 input >> old 
#./$oldfunc 4096 0 4090 input >> old
#./$oldfunc 8192 0 8180 input >> old
#./$oldfunc 16384 0 16370 input >> old
#./$oldfunc 32768 0 32760 input >> old 
#./$oldfunc 65536 0 65530 input >> old 

echo "new C:" 
./$newfunc 64 0 32 input > new
./$newfunc 128 0 64 input >> new
./$newfunc 256 0 128 input >> new 
./$newfunc 512 0 256 input  >> new
./$newfunc 1024 0 512 input >> new
./$newfunc 2048 0 1024 input >> new 
./$newfunc 4096 0 2048 input >> new
./$newfunc 8192 0 4096 input >> new
./$newfunc 16384 0 8192 input >> new
./$newfunc 32768 0 16384 input >> new 
./$newfunc 65536 0 32768 input >> new 

#./$newfunc 64 0 60 input > new
#./$newfunc 128 0 120 input >> new
#./$newfunc 256 0 250 input >> new 
#./$newfunc 512 0 500 input  >> new
#./$newfunc 1024 0 1020 input >> new
#./$newfunc 2048 0 2040 input >> new 
#./$newfunc 4096 0 4090 input >> new
#./$newfunc 8192 0 8180 input >> new
#./$newfunc 16384 0 16370 input >> new
#./$newfunc 32768 0 32760 input >> new 
#./$newfunc 65536 0 65530 input >> new 


echo "aligned....(maxlen>reallen)"
echo "old C:"
./$oldfunc 64 0 128 input >> old
./$oldfunc 128 0 256 input >> old
./$oldfunc 256 0 512 input >> old 
./$oldfunc 512 0 1024 input  >> old
./$oldfunc 1024 0 2048 input >> old
./$oldfunc 2048 0 4096 input >> old 
./$oldfunc 4096 0 8192 input >> old
./$oldfunc 8192 0 16384 input >> old
./$oldfunc 16384 0 32768 input >> old
./$oldfunc 32768 0 65536 input >> old 
./$oldfunc 65536 0 100000 input >> old 


echo "new C:"
./$newfunc 64 0 128 input >> new
./$newfunc 128 0 256 input >> new
./$newfunc 256 0 512 input >> new 
./$newfunc 512 0 1024 input  >> new
./$newfunc 1024 0 2048 input >> new
./$newfunc 2048 0 4096 input >> new 
./$newfunc 4096 0 8192 input >> new
./$newfunc 8192 0 16384 input >> new
./$newfunc 16384 0 32768 input >> new
./$newfunc 32768 0 65536 input >> new 
./$newfunc 65536 0 100000 input >> new 


echo "unaligned....(maxlen<reallen)"
echo "old C:"
./$oldfunc 64 1 32 input >> old
./$oldfunc 128 1 64 input >> old
./$oldfunc 256 1 128 input >> old 
./$oldfunc 512 1 256 input  >> old
./$oldfunc 1024 1 512 input >> old
./$oldfunc 2048 1 1024 input >> old 
./$oldfunc 4096 1 2048 input >> old
./$oldfunc 8192 1 4096 input >> old
./$oldfunc 16384 1 8192 input >> old
./$oldfunc 32768 1 16384 input >> old 
./$oldfunc 65536 1 32768 input >> old 

#./$oldfunc 64 1 60 input >> old
#./$oldfunc 128 1 120 input >> old
#./$oldfunc 256 1 250 input >> old 
#./$oldfunc 512 1 500 input  >> old
#./$oldfunc 1024 1 1020 input >> old
#./$oldfunc 2048 1 2040 input >> old 
#./$oldfunc 4096 1 4090 input >> old
#./$oldfunc 8192 1 8180 input >> old
#./$oldfunc 16384 1 16370 input >> old
#./$oldfunc 32768 1 32760 input >> old 
#./$oldfunc 65536 1 65530 input >> old 

echo "new C:" 
./$newfunc 64 1 32 input >> new
./$newfunc 128 1 64 input >> new
./$newfunc 256 1 128 input >> new 
./$newfunc 512 1 256 input  >> new
./$newfunc 1024 1 512 input >> new
./$newfunc 2048 1 1024 input >> new 
./$newfunc 4096 1 2048 input >> new
./$newfunc 8192 1 4096 input >> new
./$newfunc 16384 1 8192 input >> new
./$newfunc 32768 1 16384 input >> new 
./$newfunc 65536 1 32768 input >> new 

#./$newfunc 64 1 60 input >> new
#./$newfunc 128 1 120 input >> new
#./$newfunc 256 1 250 input >> new 
#./$newfunc 512 1 500 input  >> new
#./$newfunc 1024 1 1020 input >> new
#./$newfunc 2048 1 2040 input >> new 
#./$newfunc 4096 1 4090 input >> new
#./$newfunc 8192 1 8180 input >> new
#./$newfunc 16384 1 16370 input >> new
#./$newfunc 32768 1 32760 input >> new 
#./$newfunc 65536 1 65530 input >> new 



echo "unaligned....(maxlen>reallen)"
echo "old C:"
./$oldfunc 64 1 128 input >> old
./$oldfunc 128 1 256 input >> old
./$oldfunc 256 1 512 input >> old 
./$oldfunc 512 1 1024 input  >> old
./$oldfunc 1024 1 2048 input >> old
./$oldfunc 2048 1 4096 input >> old 
./$oldfunc 4096 1 8192 input >> old
./$oldfunc 8192 1 16384 input >> old
./$oldfunc 16384 1 32768 input >> old
./$oldfunc 32768 1 65536 input >> old 
./$oldfunc 65536 1 100000 input >> old 


echo "new C:"
./$newfunc 64 1 128 input >> new
./$newfunc 128 1 256 input >> new
./$newfunc 256 1 512 input >> new 
./$newfunc 512 1 1024 input  >> new
./$newfunc 1024 1 2048 input >> new
./$newfunc 2048 1 4096 input >> new 
./$newfunc 4096 1 8192 input >> new
./$newfunc 8192 1 16384 input >> new
./$newfunc 16384 1 32768 input >> new
./$newfunc 32768 1 65536 input >> new 
./$newfunc 65536 1 100000 input >> new 




./count

