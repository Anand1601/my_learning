#include <iostream>
using namespace std;

bool binary_re(int a[],int i,int j,int k)
{
    if(i>j)
    return false;
int m=(i+j)/2;
if(a[m]<k)
return binary_re(a,m+1,j,k);
else if(a[m]>k)
return binary_re(a,i,m-1,k);
else
return true;
}

bool binary_it(int a[],int n,int k)
{
int i=0,j=n-1;
while(i<=j)
{
    int m=(i+j)/2;
    if(a[m]<k)
    i=m+1;
    else if(a[m]>k)
    j=m-1;
    else
    return true;
}
return false;
}

int main()
{
 int n,k;
 cin>>n;
 int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cin>>k;
cout<<binary_it(a,n,k)<<endl;
cout<<binary_re(a,0,n-1,k);
}