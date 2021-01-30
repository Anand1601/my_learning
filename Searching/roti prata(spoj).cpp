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
 
 
//sort by second a pair
bool bysec(pri a,pri b)  {return (a.se<b.se);}
 
//sort by second in reverse order
bool bysecriv(pri a,pri b){return (a.se>b.se);}
 
//sort by first in reverse
bool byrev(pri a , pri b){return (a.fi>a.fi);}
//sort in reverse order
bool rev(int a ,int b){ return (a>b);}
 
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
 
void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();
 
ll check(vec &v,ll t)
{
ll cnt=0;
for(ll i:v)
cnt+=(sqrt(1+8*(t/i))-1)/2;
return cnt;
    
}
 
 
int main() {
    krish;
wl(t)
{
ll n,k;
cin>>k>>n;
vec v(n);
ll ma=0;
for(ll &i:v)
{
    cin>>i;
    if(ma<i)
    ma=i;
}
 
ll l=0,h=(k*ma*(k+1))/2;
ll ans=h;
while(l<=h)
{
    ll mi=(l+h)/2;
    ll y=check(v,mi);
    if(y>=k)
    ans=min(ans,mi),h=mi-1;
    else
    l=mi+1;
 
  }
 
cout<<ans<<endl;
 
}
  
 
// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
} 