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





int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

insertion_sort(a,n);


	print(a,n);
}