#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl; 
}


void selection_sort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int x=i;
        for(int j=i+1;j<n;j++)
        if(a[x]>a[j])
        x=j;
         swap(a[x],a[i]);
   
    }
}


int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

selection_sort(a,n);



	print(a,n);
}