#!/bin/bash
file=$1
if [[ $# -ne 1 ]]; then
        echo -e "\n num_args error: Enter the name of your .c file only\n"
        exit
fi

gcc -Wall -c $file      #complie only one single file with -c flag it will produce an object file: $file.o
gcc -Wall -o linked *.o #link each .o file to an executable 'linked.o"
./linked                #run it :)

echo -e "\n in case of segmentation fault or SIGSEGV please google and use GDB debuger\n"


