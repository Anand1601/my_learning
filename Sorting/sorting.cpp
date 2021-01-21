#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl; 
}

void insertion_sort(int *a,int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		while(j>=0&&a[j+1]<a[j])
			swap(a[j+1],a[j]),j--;

	}
}


void bubble_sort(int *a,int n)
{
    
    	for(int i=0;i<n;i++){
    	    bool st=true;    //for optimization
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
//bubble_sort(a,n);
//selection_sort(a,n);
//insertion_sort(a,n);


	print(a,n);
}