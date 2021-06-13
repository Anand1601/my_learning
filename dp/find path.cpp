/*Q> you are given an NxM grid. you can move either
right or down but there are obastacles at some cell
u can't go from them. find the no. of way to go form
cell (1,1) to (n,m).
INPUT: 5 5 5
       1 3
       2 5
       3 3
       4 1
       5 2
OUTPUT: 15

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
// wl(t)
{
ll n,m,k,x,y;
cin>>n>>m>>k;
vector<vec> v(n,vec(m,-1));
for(int i=0;i<k;i++)
{
    cin>>x>>y;
v[x-1][y-1]=0;
}

for(int i=n-1;i>=0;i--)
    for(int j=m-1;j>=0;j--)
if(i==n-1&&j==m-1)
v[i][j]=1;
else if(v[i][j]!=0)
{
v[i][j]=0;
if(i<n-1)
v[i][j]+=v[i+1][j];
if(j<m-1)
v[i][j]+=v[i][j+1];
}


cout<<v[0][0]<<endl;

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