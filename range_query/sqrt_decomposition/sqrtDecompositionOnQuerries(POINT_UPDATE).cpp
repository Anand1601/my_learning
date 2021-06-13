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
vec a(n);
for(int i=0;i<n;i++)
cin>>v[i],a[i]=v[i];


for(int i=1;i<n;i++)
v[i]+=v[i-1];
ll b=sqrt(q);
ll x,l,r,ans;

vector<vec> vx;

for(int qr=0;qr<q;qr++)
{
cin>>x;
if(x==0)
{
cin>>l>>r;
if(l>0)
 ans=v[r]-v[l-1];
else
	ans=v[r];

for(auto i:vx)
	if(l<=i[0]&&r>=i[0])
		ans=ans-a[i[0]]+i[1];

cout<<ans<<endl;
}
else
{
	cin>>l>>x;
	vx.push_back({l,x});

}

if((qr/b)*b+b-1==qr)
{
    for(auto i:vx)
    a[i[0]]=i[1];
    
vx.clear();
v[0]=a[0];
for(int i=1;i<n;i++)
v[i]=v[i-1]+a[i];
}


}

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}