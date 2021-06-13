/*
Q> you are given a number n. in one step you can 
subtract one of its digits form it. u have to make 
it zero in minimum steps.
INPUT: 50
OUTPUT: 10
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
 
vec fun(ll n)
{
    vec vx;
    while(n)
    {
        vx.push_back(n%10);
        n/=10;
    }
    return vx;
}


int main() {
    krish;
ll n;
//wl(t)
{
cin>>n;
vec dp(n+1,0);
dp[0]=0;
for(int i=1;i<=9;i++)
dp[i]=1;

vec v;

for(int i=10;i<=n;i++)
{
    v=fun(i);

/*  cout<<i<<endl;
    print(v);*/
    ll x=inf;
    for(auto c:v)
    if(i-c>=0&&c!=0){
x=min(x,dp[i-c]+1);
    }
    dp[i]=x;
}
//print(dp);
cout<<dp[n]<<endl;
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