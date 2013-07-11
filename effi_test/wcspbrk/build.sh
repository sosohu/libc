#/bin/sh
echo $1

gcc -o random_data random_data.c
gcc -o count count.c 

gcc -mabi=64 -o wcspbrk_new eff_wcspbrk.c ../../libc/libc_us.a 
gcc -mabi=64 -o wcspbrk_origin eff_wcspbrk.c ../../libc/libc_origin.a 

newfunc=wcspbrk_new
oldfunc=wcspbrk_origin
src_len="64"
dst_len="64"
N="10"


echo "src_len: $src_len   dst_len: $dst_len"
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 > old
./$newfunc $src_len $dst_len input input1 > new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new
./random_data > input
./random_data > input1
./$oldfunc $src_len $dst_len input input1 >> old
./$newfunc $src_len $dst_len input input1 >> new




./count $N
