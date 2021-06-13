/*
Q. you are given an array of n elements and q queries. there are two type of 
queries the first one is [0 l r]-print the range sum and the second one is 
[1 l r a d] -> add the AP formed by the first element 'a' and the difference 
'd' for eg. v[l]+a,v[l]+a+d,v[l]+a+2d,..... and soon.

INPUT: 8 6
       1 2 3 4 5 6 7 8
       0 1 3
       1 0 6 2 3
       0 2 4
       0 0 3
       1 2 4 4 2
       0 2 5
OUTPUT: 9
       45
       36
       86

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

vec v(n);
for(ll &i:v)
cin>>i;

ll b=sqrt(n);
ll s=(n+b-1)/b;
vec vx(s,0);
for(int i=0;i<n;i++)
    vx[i/b]+=(v[i]);
ll x,l,r,d;
vec lazy_a(s,0);
vec lazy_d(s,0);
while(q--)
{

cin>>x;
if(x==0)
{
cin>>l>>r;
ll cnt=0;
//left part
ll end=(l/b)*b+b-1;
for(int i=l;i<=min(r,end);i++)
    cnt+=v[i]+lazy_a[i/b]+lazy_d[i/b]*(i-(l/b)*b);
//cout<<"befor"<<cnt<<endl;
if(l/b!=r/b)
{
    ll str=(r/b)*b;
for(int i=str;i<=r;i++)
    cnt+=v[i]+lazy_a[i/b]+lazy_d[i/b]*(i-(r/b)*b);

for(int i=l/b+1;i<r/b;i++)
    cnt+=vx[i]+lazy_a[i]*b+lazy_d[i]*((b-1)*b)/2;;
}
cout<<cnt<<endl;
}
else
{
cin>>l>>r>>x>>d;
// left;
ll end=(l/b)*b+b-1;
for(int i=l;i<=min(r,end);i++)
    v[i]+=x,x+=d;
if(l/b!=r/b)
{
    for(int i=l/b+1;i<r/b;i++)
        lazy_a[i]=x,lazy_d[i]=d,x+=d*((b-1)*b)/2+d;


    for(int i=(r/b)*b;i<=r;i++)
          v[i]+=x,x+=d;
           
}

}

}




}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}