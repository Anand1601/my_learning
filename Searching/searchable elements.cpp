/*
find the no. of element definetly searchable in unsorted array of unique no.s using binary search. 
in O(n);
--soluton-- 
condition for seachable
1. all the no. on the left is less than a[i]
2. all the no. on the right is greater then a[i];

*/

#include <iostream>
using namespace std;



int main()
{
 int n,k;
 cin>>n;
 int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int lp[n];             //left prifix array
int rp[n];              //right prifix array

 lp[0]=a[0];
 rp[n-1]=a[n-1];
 for(int i=1;i<n;i++)
 lp[i]=max(lp[i-1],a[i]);
 for(int j=n-2;j>=0;j--)
 rp[j]=min(rp[j+1],a[j]);
 
int cnt=0;
for(int i=0;i<n;i++)
if(a[i]<=rp[i]&&a[i]>=lp[i])
cnt++;
cout<<cnt<<endl;

}