#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;   //----for_getting_execution_time
#define ll long long
#define fi first
#define se second
#define pri pair<int,int>
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

bool check(vec &v,ll c,ll m)
{
	ll pr=v[0],ans=1;

for(int i=1;i<v.size();i++)
	if(v[i]-pr>=m)
		pr=v[i],ans++;

	return (ans>=c);
}

int main() {
    krish;
ll n,c;

wl(t)
{
cin>>n>>c;
std::vector<ll> v(n);
for(ll &i:v)
	cin>>i;
sort(v.begin(), v.end());
ll l=0,h=2*v[n-1],ans=-1;
while(l<=h)
{
	ll m=(l+h)/2;
	if(check(v,c,m))
		ans=m,l=m+1;
	else
		h=m-1;
}
cout<<ans<<endl;
}
// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}