/*
Q. you are given an array a containing n numbers and q querries. the querries 
are either [0 l r] -( find the sum of element [l,r]) or 
[1 l r x]-(add x from l to r inclusive).
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

vec sum(s,0);
vec lazy(s,0);

for(int i=0;i<n;i++)
sum[i/b]+=v[i];

ll x,l,r;
while(q--)
{
	cin>>x;
	if(x==0)
	{
		ll cnt=0;
cin>>l>>r;
// left
ll end=(l/b)*b+b-1;
for(int i=l;i<=min(r,end);i++)
cnt+=v[i]+lazy[l/b];

if(l/b!=r/b)
{
	// right
	ll str=(r/b)*b;
	for(int i=str;i<=r;i++)
cnt+=v[i]+lazy[r/b];

for(int i=l/b+1;i<r/b;i++)
	cnt+=sum[i]+lazy[i]*b;

}
cout<<cnt<<endl;

	}
	else
	{
		cin>>l>>r>>x;
// left
		ll end=(l/b)*b+b-1;

		for(int i=l;i<=min(r,end);i++)
			v[i]+=x;
		if(l/b!=r/b)
		{
			//right
			ll str=(r/b)*b;
for(int i=str;i<=r;i++)
	v[i]+=x;
// intermediate
for(int i=l/b+1;i<r/b;i++)
lazy[i]+=x;
		}

	}
}



}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}