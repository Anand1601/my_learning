/*
Q. given an array of length n and q querries. there are two type of querries
 the first one is [0 l r ]- find the sum of l to r;
 the second one is [1 l r x]- add x to all the element form l to r includsive.
INPUT:8 6
       1 2 3 4 5 6 7 8
       0 1 3
       1 0 6 2 
       0 2 4
       0 0 3
       1 2 4 4 
       0 2 5
OUTPUT:9
       18
       18
       38

*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;   //----for_getting_execution_time
#define ll long long
#define fi first
#define se second
#define pri pair<ll,ll>
#define M 1000000007
#define pb(x) push_back(x)
#define mpr(x,y) make_pair(x,y)
#define wl(t) int t;cin>>t;while(t--)
#define krish ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
#define vec vector<ll> 
#define inf 3e18
#define ld long double

//sort by second a pair
bool bysec(pri a,pri b)  {return (a.se<b.se);}

//sort by second in reverse order
bool bysecriv(pri a,pri b){return (a.se>b.se);}

//sort by first in reverse
bool byrev(pri a , pri b){return (a.fi>a.fi);}
//sort in reverse order
bool rev(int a ,int b){ return (a>b);}

void print(vec a)
{
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();
 



int main() {
    krish;
  //  wl(t)
{
ll n,q;
cin>>n>>q;
vec a(n);
vec sum(n);

for(int i=0;i<n;i++)
    cin>>a[i];
sum[0]=a[0];
for(int i=1;i<n;i++)
sum[i]=a[i]+sum[i-1];

std::vector<vec> vx;
ll x,l,r;
ll b=sqrt(q);
vec update(n+1,0);
for(int qr=0;qr<q;qr++)
{
    cin>>x;
    if(x==0)
    {
cin>>l>>r;
ll cnt=0;
if(l>0)
cnt+=sum[r]-sum[l-1];
else
cnt+=sum[r];
for(vec i:vx)
    cnt+=max(0ll,min(r,i[1])-max(l,i[0])+1)*i[2];
cout<<cnt<<endl;
    }
    else
    {
        cin>>l>>r>>x;
        vx.push_back({l,r,x});
        update[l]+=x;
        update[r+1]=-x;
    }
    if((qr/b)*b+b-1==qr)
    {
        vx.clear();
        for(int i=1;i<=n;i++)
            update[i]+=update[i-1];
        for(int i=0;i<n;i++)
    a[i]+=update[i];
  for(int i=0;i<=n;i++)
    update[i]=0;
sum[0]=a[0];
for(int i=1;i<n;i++)
sum[i]=sum[i-1]+a[i];


    }
/*print(sum);
print(a);*/
}

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}