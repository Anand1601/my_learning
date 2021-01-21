#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}

int upper_b(int a[],int n,int k)
{
	int l=0,h=n-1;
	int ans=-1;
	while(l<=h)
	{
		int m=(l+h)/2;
		if(a[m]>k)
			ans=m,h=m-1;
		else 
			l=m+1;

	}
	return ans;
}

int lower_b(int a[],int n,int k)
{
	int l=0,h=n-1;
	int ans=-1;
	while(l<=h)
	{
		int m=(l+h)/2;
		if(a[m]>=k)
			ans=m,h=m-1;
		else 
			l=m+1;

	}
	return ans;
}

int main()
{
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		cin>>k;

cout<<upper_b(a,n,k)<<endl;
cout<<lower_b(a,n,k)<<endl;
cout<<"using STL"<<endl;
cout<<upper_bound(a,a+n,k)-a<<endl;    //upper_bound(a,a+n,k) will return address only.
cout<<lower_bound(a,a+n,k)-a<<endl;
//u can use comparator to use it for vector of pair or for any other case//
cout<<"using comparator to apply binary search in reverse sorted array "<<endl;
sort(a,a+n,cmp);
cout<<upper_bound(a,a+n,k,cmp)-a<<endl;    //upper_bound(a,a+n,k) will return address only.
cout<<lower_bound(a,a+n,k,cmp)-a<<endl;

}