This is implementation of tANS(a variant of ANS, tabled ANS) done by Yann Collet. 
The original repository is https://github.com/Cyan4973/FiniteStateEntropy

To run the code execute following commands:-
1) gcc probaGenerator.c
2) make CFLAGS="-march=native -ofast" LDFLAGS="-flto"

3) For compressing meaningful data: 

   For compression use command : ./fse -f MeaningfulDataANS.bin tmp1  (compressed data will be stored in tmp1 file)
   For de-compression use command : ./fse -df tmp1 result1  (compressed data from tmp1 will be decompressed and will be stored in result1 file)

4) For compressing random data: 

   For compression use command : ./fse -f RandomDataANS.bin tmp2  (compressed data will be stored in tmp2 file)
   For de-compression use command : ./fse -df tmp2 result2  (compressed data from tmp2 will be decompressed and will be stored in result2 file) 

