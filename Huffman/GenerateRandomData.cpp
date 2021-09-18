#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <fstream>
using namespace std;

int main () {
	srand(time(0)); //initialising random number generator
    ofstream File_HuffMan, File_tANS;
    File_HuffMan.open ("RandDataHuff.txt"); // 'RandDataHuff.txt' file has been created for storing random text for huffmann algorithm.
    File_tANS.open ("RandDataANS.txt");  // 'RandDataANS.txt' file has been created for storing random binary sequence for tANS algorithm.
    char ch;
    int num;

	for(int i=0;i<5000000;i++)  // '5000000' number has been decided by trial and error method, so as to get 5.5 MB of random data.
	{
		ch='a'+rand()%26; // generating a random no. and converting it to an alphabet
		File_HuffMan<<ch;  // writing the random alphabet in file 'RandDataHuff.txt'
		if(i%6 == 0)  
		File_HuffMan<<" ";
    }
     
    File_HuffMan.close();   
    
    for(int i=0;i<800000;i++)  // '800000' number has been decided by trial and error method, so as to get 5.5 MB of random data.
    {
    	ch='a'+rand()%26;  // // generating a random no. and converting it to an alphabet
    	string bin;
	num = int(ch);  // converting character into ASCII value
		
		// Converting ASCII value to binary
        while(num>0) 
        {
            (num % 2)?bin+='1':bin+='0';
            num/=2;
        }
        reverse(bin.begin(), bin.end());
       
	File_tANS<<bin<<" ";  // writing the binary conversion of random alphabet in file 'RandDataANS.txt'
    }
  
  File_tANS.close();   

  return 0;
}

