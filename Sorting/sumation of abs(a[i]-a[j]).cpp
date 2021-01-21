/*
find ?[i=0,n-1]?[j=i+1,j<n](abs(a[i]-a[j])) in an efficient manner

solN= sort the array ,and each time add sum-ith element*no of element greater.

*/



#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
        cin>>n;
    int sum=0,s=0;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i],sum+=a[i];
    sort(a,a+n);
   
    for(int i=0;i<n;i++)
        s+=(sum-(a[i]*(n-1-i)));
    
    cout<<s<<endl;
}