#!/bin/sh

# To Generate random data for Huffman algorithm and ANS algorithm: 
g++ GenerateRandomData.cpp
./a.out

# compiling huffman program

g++ huffman.cpp

echo "Huffman aglorithm for meaningful data of size 6.3 MB : "
# executing huffman algorithm for meaningful data

./a.out MeaningfulData.txt

echo "Huffman aglorithm for random data of size 5.8 MB : "
# executing huffman algorithm for random data

./a.out RandDataHuff.txt
