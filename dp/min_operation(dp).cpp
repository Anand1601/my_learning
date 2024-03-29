/*Q> make n to 1 in minimum operation using any of these :
1) divide by 3 if possible
2) divide by 2 if possible
3) subtract 1 if n>1;

print min no. of operations
eg. input: 10
output : 3

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

ll fun(ll n,vec &dp)
{

    if(n==1)
        return dp[1]=0;

if(dp[n]!=-1)
    return dp[n];

ll x,y,z;

x=y=z=n;
if(n%2==0)
x=fun(n/2,dp);
if(n%3==0)
y=fun(n/3,dp);
if(n>1)
z=fun(n-1,dp);

return dp[n]=min({x,y,z})+1;

}

int main() {
    krish;
    wl(t)
{

ll n;
cin>>n;
vec dp(n+1,-1);
cout<<fun(n,dp)<<endl;

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}