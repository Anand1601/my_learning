#include<bits/stdc++.h>

using namespace std;

int partition(int a[],int n,int l,int h,int pvt)
{
    int i,j;
    i=l,j=l;
    
for(;i<n;i++)
if(a[i]<=pvt)
swap(a[i],a[j]),j++;

return j-1;

}

int quick_select(int a[],int n,int l, int h,int k)
{
    if(l>h)
    return -1;
    int pvt=a[h];
    int p=partition(a,n,l,h,pvt);
    if(p==k-1)
    return a[p];
    else if(p>k-1)
    return quick_select(a,n,l,p-1,k);
    return quick_select(a,n,p+1,h,k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
cout<<quick_select(a,n,0,n-1,k);
}