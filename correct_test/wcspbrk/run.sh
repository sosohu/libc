#!/bin/sh

gcc -o random_data random_data.c 
gcc -mabi=64 -o wcspbrk corr_wcspbrk.c ../../libc/libc_origin.a
gcc -mabi=64 -o new_wcspbrk corr_wcspbrk.c ../../libc/libc_us.a #-fprofile-arcs -ftest-coverage 
./random_data > input_data
echo "old maxlen=1024reallen from 0 to 1024):"
./wcspbrk input_data 512 > output_origin
echo "new maxlen=1024(reallen from 0 to 1024):"
./new_wcspbrk input_data 512 > output_new
diff output_origin output_new
