/*Q. there are n jobs . a job takes t[i] time to be completed & has a deadline
 of d[i] . minimize the maximum lateness for the jobs.
 1. intinal time is zero;
 2. lateness = max(0,f[i]-d[i]) where f[i] is the finish time for ith job.
 3. one's you start a job u can't swith to the other without completing it.
 eg.
 n=2;
 d=[2,5];
 t=[2,1];
 ans=0;

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
    //wl(t)
{
    ll n;
    cin>>n;
 std::vector<pri> v(n);
 for(int i=0;i<n;i++)
 	cin>>v[i].fi;
 for(int i=0;i<n;i++)
 	cin>>v[i].se;

sort(v.begin(), v.end());
ll cnt=0,last=0;

for(int i=0;i<n;i++)
{
	cnt+=max(0ll,last+v[i].se-v[i].fi);
	last+=v[i].se;
}

cout<<cnt<<endl;
}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}