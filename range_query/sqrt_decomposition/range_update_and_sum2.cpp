/*Q> RANGE UPDATE AND SUM
you are given an array of n element and q querries. there are two type
of querries -
1. [0,l,r] find the sum of l to r;
2. [1,l,r,x ] replace all the element b/w l to r by x;

constrains:
1<=n,q<=1e6
1<=a[i],x<=1e9;

INPUT: 10 4
       1 2 3 4 5  6 7 8 9 10
       0 1 4
       1 2 4 2    //1 2 2 2 2 6 7 8 9 10
       0 1 4
       0 3 5
OUTPUT:
       14
       8
       10


SOLUTION: taking lazy,sum and other arrays;
There can be to differnet approach to solve;
solve1:
we can take two different  arrays of time lazy_time[],arr_time.
and check which one is the latest update and do the queries .
solve2:
we can simply update the left and right part of array every time 
and make the laze[of_this_block] equal to 0. and in this way we can 
insure that the lazy always contains the latest update.


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
 
 solve1(){

  ll n,q;
  cin>>n>>q;
vec v(n);
for(ll &i:v)
cin>>i;

ll b=sqrt(n);
ll s=(n+b-1)/b;
vec sum(s,0);
for(int i=0;i<n;i++)
sum[i/b]+=v[i];

vec lazy(s,0);
ll x,l,r;
vec lazy_t(s,-2);
vec arr_t(n,-1);


for(int qr=0;qr<q;qr++)
{
  cin>>x;
  if(x==0)
  {
cin>>l>>r;
// left part
ll cnt=0;
for(int i=l;i<=min((l/b)*b+b-1,r);i++)
  if(lazy_t[i/b]>arr_t[i])
    cnt+=lazy[i/b];
  else
    cnt+=v[i];

//cout<<"0 "<<cnt<<endl;

if(l/b!=r/b)
{
  // right part
  for(int i=(r/b)*b;i<=r;i++)
      if(lazy_t[i/b]>arr_t[i])
    cnt+=lazy[i/b];
  else
    cnt+=v[i];

//cout<<"1 "<<cnt<<endl;


for(int i=l/b+1;i<r/b;i++)
  cnt+=sum[i];

}
cout<<cnt<<endl;
  }
  else
  {
cin>>l>>r>>x;

//left part
for(int i=l;i<=min((l/b)*b+b-1,n);i++){
  if(lazy_t[i/b]>arr_t[i])
    sum[i/b]-=lazy[i/b]+x;
else
  sum[i/b]-=v[i]+x;
v[i]=x;
arr_t[i]=qr;
}

if(l/b!=r/b)
{
  // right 
  for(int i=(r/b)*b;i<=r;i++){
     if(lazy_t[i/b]>arr_t[i])
    sum[i/b]-=lazy[i/b]+x;
else
  sum[i/b]-=v[i]+x;
v[i]=x;
arr_t[i]=qr;
}

for(int i=l/b+1;i<r/b;i++)
  sum[i]=x*b,lazy[i]=x,lazy_t[i]=qr;

}


  }
}


 }




solve2()
{
  ll n,q;
  cin>>n>>q;
vec v(n);
for(ll &i:v)
cin>>i;

ll b=sqrt(n);
ll s=(n+b-1)/b;
vec sum(s,0);
for(int i=0;i<n;i++)
sum[i/b]+=v[i];

vec lazy(s,0);
ll x,l,r;
while(q--)
{
  cin>>x;
  if(x==0)
  {
cin>>l>>r;
// left part
ll end=(l/b)*b+b-1;
ll cnt=0;
for(int i=l;i<=min(r,end);i++)
if(lazy[i/b])
cnt+=lazy[i/b];
else
cnt+=v[i];

if(l/b!=r/b)
{
  for(int i=(r/b)*b;i<=r;i++)
    if(lazy[i/b])
cnt+=lazy[i/b];
else
cnt+=v[i];

for(int i=l/b+1;i<r/b;i++)
  cnt+=sum[i];

}

cout<<cnt<<endl;
  }
  else
  {

cin>>l>>r>>x;

// left part block
for(int i=(l/b)*b;i<=min((l/b)*b+b-1,n);i++)
  if(i<l&&lazy[i/b])
    v[i]=lazy[i/b];
  else if(i>=l){
    if(lazy[i/b])
    sum[i/b]-=lazy[i/b]+x;
  else
    sum[i/b]-=v[i]+x;
  v[i]=x;

  }
  lazy[l/b]=0;

if(l/b!=r/b)
{
  // right part block
  for(int i=(r/b)*b;i<=min((r/b)*b+b-1,n);i++)
    if(i>r&&lazy[i/b])
    v[i]=lazy[i/b];
  else if(i<=r){
    if(lazy[i/b])
    sum[i/b]-=lazy[i/b]+x;
  else
    sum[i/b]-=v[i]+x;
  v[i]=x;

  }
  lazy[r/b]=0;

  for(int i=l/b+1;i<r/b;i++)
lazy[i]=x,sum[i]=x*b;
}


  }
}


}

int main() {
    krish;
  //  wl(t)
{

  solve1();
 // solve2();

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}


//some points to remember
/*
-simple mod not work for -ve numbers;
*/