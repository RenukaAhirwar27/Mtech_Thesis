#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<utility>
#include<tr1/unordered_map>
using namespace std;

typedef pair<int,int> PAIR;
vector<struct node*> subtree;
std::tr1::unordered_map<int,char> mp; 
std::tr1::unordered_map<char,int> mp_freq; // A map to store the frequency of occurrence of each alphabet

struct node
{
	int data;
	node *left;
	node *right;
	
	node(int value) 
    { 
        data = value; 
        left = NULL; 
        right = NULL; 
    } 
};

// Function to print the huffman code of each character which is occuring in our i/p data,
// by assigning 0 when we're going left and 1 when we're going right from a node.
// The code of a particular character is found by traversing Huffman tree from 
// root till the leaf node of that particular character.
void HuffmanCode(struct node* root, string s)
{
    if (root == NULL)
        return;

    if (root->left)
        HuffmanCode(root->left, s + "0");
  
    if (root->right)
        HuffmanCode(root->right, s + "1");
 
    if (root->left==NULL && root->right==NULL)
    {
        cout<<mp[root->data]<<" : "<<s<<"\n";
        HuffmanCode(root->left, s + "0");
        HuffmanCode(root->right, s + "1");
    }
}

// Function to print inorder traversal of Huffman tree.
void printInorder(struct node* root) 
{ 
    if (root == NULL) 
        return; 
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
} 

// Function to insert nodes in a Huffman tree. Top two elements of min heap(Min priority queue) 
// is given to function and new nodes are created for each of them if they are leaf nodes.
// An internal node is created having left and right child as the two nodes which are created, 
// and the value of this internal node is equal to sum of values of left and right nodes.
struct node* insert(struct node* root ,int data1, int data2, int isleafLeft, int isleafRight)
{
	if(root != NULL)
	subtree.push_back(root);
	
	root = new node(data1 + data2);
	
	if(isleafLeft)
	root->left=new node(data1);
	else 
	{
		root->left = subtree[0];
		subtree.erase(subtree.begin());
	}
		
	if(isleafRight)
	root->right=new node(data2);
	else 
	{
		root->right = subtree[0];
		subtree.erase(subtree.begin());
	}
	return root;
}

int main(int argc,char* argv[])
{
	int n,frequency,z,i,frequency_Right,frequency_Left,isleafLeft,isleafRight;
	char alphabet,c,read;
	struct node* root = NULL;
	ifstream myFile;
	priority_queue<PAIR,vector<PAIR>,greater<PAIR> > Q;
	//cout<<"Enter the no. of distinct characters occuring:\n";
	//cin>>n;

        for(int i=0;i<26;i++) 
	{
	    c='a'+i;
	    mp_freq[c]=0;
	}

        //for(auto i:mp_freq)
    	//cout<<int(i.first)<<" "<<i.second<<endl;
	//cout<<mp_freq.size()<<endl;
        //myFile.open("RandDataHuff.txt");
        myFile.open(argv[1]);
    
     //Calculating the frequency of occurrence of various alphabets.
     while(myFile.get(read))
     {
     if(mp_freq.find(read) != mp_freq.end())
       mp_freq[read]++;      
      }
  	
     myFile.close(); 
        
        //for(auto i:mp_freq)
    	//cout<<i.first<<" "<<i.second<<endl;
        //cout<<mp_freq.size()<<endl; 

    	for(auto i:mp_freq)
    	mp[i.second]=i.first;
        /*
	for(auto i:mp)
    	cout<<i.first<<" "<<i.second<<endl;
        cout<<mp.size()<<endl;
	for(i=0;i<n;i++)
        {
    	cout<<"Enter "<<i+1<<"st character and its frequency: ";
    	cin>>alphabet>>frequency;
    	mp[frequency]=alphabet;
    	Q.push(make_pair(frequency,1));
	}  */
	
	for(auto j:mp)
	Q.push(make_pair(j.first,1));
	
	while(!Q.empty())
	{
		frequency_Left = Q.top().first;
		isleafLeft=Q.top().second;
		Q.pop();
		frequency_Right = Q.top().first;
		isleafRight=Q.top().second;
		Q.pop();
		
		root=insert(root,frequency_Left,frequency_Right,isleafLeft,isleafRight);
		z=frequency_Left+frequency_Right;
		Q.push(make_pair(z,0));
		if(Q.size()==1)
		Q.pop();
		
	}
	//cout<<"\nInorder Traversal of Huffman Tree: \n"; 
	//printInorder(root);
	//cout<<"\n";
	cout<<"\nHuffman Codes for each alphabet are:\n";
	HuffmanCode(root,"");
        cout<<"\n\n";
	return 0;
}  
