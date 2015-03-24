#!/bin/sh

# mofaph@gmail.com

hello_file="hello.txt"
t_914="t9-14.txt"
out="t914"

# Create test file
printf "Hello, world\n" > $hello_file
cp $hello_file $t_914

# Compile and run
cc -Wall ex9-14.c t9-14.c -o $out
./$out

# Test the output
if cmp -s $hello_file $t_914; then
    printf "FAILED: 9.14\n"
fi

# Test done, delete all the generated files
rm -f $hello_file $t_914 $out

exit $?
