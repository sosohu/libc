#!/bin/sh

gcc -o random_data random_data.c 
gcc -mabi=64 -o strpbrk corr_strpbrk.c ../../libc/libc_origin.a
gcc -mabi=64 -o new_strpbrk corr_strpbrk.c ../../libc/libc_us.a #-fprofile-arcs -ftest-coverage 
./random_data > input_data
echo "old maxlen=128(reallen from 0 to 1024):"
./strpbrk input_data 128 > output_origin
echo "new maxlen=128(reallen from 0 to 1024):"
./new_strpbrk input_data 128 > output_new
diff output_origin output_new
