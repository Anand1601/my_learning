#include <bits/stdc++.h>

using namespace std;

int main() {

int n,m,k;
cin>>n>>m>>k;
int a[n+1];
int b[m+1];

for(int i=0;i<n;i++)
cin>>a[i];
for(int j=0;j<m;j++)
cin>>b[j];

sort(a,a+n);
sort(b,b+m);
int i=0,j=0;
int cnt=0;
while(i<n&&j<m)
{

if(abs(a[i]-b[j])<=k)
cnt++,i++,j++;
else if(a[i]>b[j])
j++;
else
i++;
    
}
cout<<cnt<<endl;
}