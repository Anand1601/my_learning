/*
Q. you are given k sorted arrays of length n each. make array of length k by 
taking 1 element from each array of lengths n, the find the min difference 
of max and min element of the array you made.

eg. n=3 k=3
    1 2 3
    4 5 6
    3 4 5
    
    output : 1 (one of the array is==[3,4,4])

*/

#include <bits/stdc++.h>
using namespace std;
int m=INT_MAX;
vector<int> merge(vector<int> v,int *a,int n )
{
    vector<int> b;
    int i=0,j=0;
while(i<n&&j<v.size())
{
    if(a[i]<=v[j])
    b.push_back(a[i]),i++,m=min(m,abs(a[i]-v[j]));
    else
b.push_back(v[j]),j++,m=min(m,abs(a[i]-v[j]));
}
while(i<n)
b.push_back(a[i]),i++;
while(j<v.size())
b.push_back(v[j]),j++;

return b;
}

int main() {
    int n,k;
 cin>>n>>k;
int *a=new int[n+1];
vector<int> v;
while(k--)
{
    for(int i=0;i<n;i++)
    cin>>a[i];
    v=merge(v,a,n);
}

cout<<m<<endl;
}