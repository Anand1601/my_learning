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
ll cl(ll a , ll b)
{
	return abs(a-b)*abs(a-b);
}

ll cal(ll a,ll b,ll c)
{
	return cl(a,b)+cl(b,c)+cl(c,a);
}

int main() {
    krish;
   
  ll nr,ng,nb,x;
wl(t){
	cin>>nr>>ng>>nb;

	std::vector<ll> v[3];
	for (int i = 0; i < nr; ++i)
	{
		cin>>x;
		v[0].push_back(x);
	}
	for (int i = 0; i < ng; ++i)
	{
		cin>>x;
		v[1].push_back(x);
	}
	for (int i = 0; i < nb; ++i)
	{                                           //v[0]--red
	                                            //v[1]--green
		cin>>x;                                 //v[3]--blue
		v[2].push_back(x);
	}

for (int i = 0; i < 3; ++i)
sort(v[i].begin(), v[i].end());
ll ans=inf;

for (int i = 0; i < 3; ++i)
{
	ll i2=(i+1)%3,i3=(i+2)%3;  //will give the indices of other two vectors
	for (int j = 0; j < v[i].size(); ++j)
	{
		ll x=lower_bound(v[i2].begin(), v[i2].end(),v[i][j])-v[i2].begin();
		ll y=upper_bound(v[i3].begin(), v[i3].end(),v[i][j])-v[i3].begin();
	y--;
		if(x<(v[i2].end()-v[i2].begin())and y>=0)
ans=min(ans,cal(v[i][j],v[i2][x],v[i3][y]));

 x=upper_bound(v[i2].begin(), v[i2].end(),v[i][j])-v[i2].begin();
		 y=lower_bound(v[i3].begin(), v[i3].end(),v[i][j])-v[i3].begin();
x--;
		if(y<(v[i3].end()-v[i3].begin())and x>=0)
ans=min(ans,cal(v[i][j],v[i2][x],v[i3][y]));
	}
}

cout<<ans<<endl;
}
  
// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}