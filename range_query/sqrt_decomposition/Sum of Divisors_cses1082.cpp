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
#define MOD(x,y)           while(x>=y)x-=y; while(x<0)x+=y;
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
// wl(t)
{
ll n;
cin>>n;
ll ans=0;

ll b=sqrt(n);
for(ll fr=1;fr<sqrt(n)+1;fr++)
{
    ll l=(n/(fr+1)),r=n/fr;
b=l;

l%=M;
r%=M;
l=((l*(l+1))/2)%M;
r=((r*(r+1))/2)%M;
   
    
   ll temp=r-l+M;
   temp*=fr;
   temp%=M;
  // cout<<fr<<" " <<l<<" "<<r<<endl;
  // cout<<temp<<endl;
   
ans=(ans+temp)%M;
}

for(ll i=1;i<=b;i++)
{
  ll x=i*(n/i);
ans=(ans+x)%M;

}

cout<<ans<<endl;

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}
