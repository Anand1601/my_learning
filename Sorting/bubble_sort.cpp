#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl; 
}


void bubble_sort(int *a,int n)
{
    
    	for(int i=0;i<n;i++){
    	    bool st=true;    //-----for optimization -reduce time complexity
	for(int j=0;j<n-1;j++)
		if(a[j]>a[j+1])
		{
		    swap(a[j],a[j+1]);
		st=false;
		}
		if(st)
		break;
	
}
}



int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
bubble_sort(a,n);



	print(a,n);
}