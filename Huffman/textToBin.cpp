#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
 
int main()
{
    ifstream readData;
    char read;
    ofstream writeData;
    int i,n,num;
    writeData.open("RandDataANSBin.txt"); 
    readData.open("RandDataANS.txt");
    while(readData.get(read))
    {
        num = int(read);
        string bin;
        while(num>0) 
        {
        	(num % 2)?bin+='1':bin+='0';
            num/=2;
        }
        reverse(bin.begin(), bin.end());  
        
  	    writeData<<bin<<" ";
    }

    readData.close();
    writeData.close();
    return 0;
}

