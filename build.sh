# CTest Program
gcc ./source/ctest.c -o ./build/ctest

# Asssertions Library
gcc -c ./source/assertions.c -Wall -fPIC -o ./build/assertions.o
gcc -shared -o ./build/libassert.so ./build/assertions.o
rm ./build/assertions.o
