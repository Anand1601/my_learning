/*
Q> print all the permutations of 1 to n.
there are two different methods;

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
#define wl(t) int t; cin>>t; while(t--)
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

long long power(long long x, long long  y)
{
    int res = 1;  
    x = x % M; 
    if (x == 0) return 0;  
    while (y > 0)
    {
        if (y & 1)   res = (res*x) % M;
              y = y>>1;        x = (x*x) % M;  }
    return res;
}

void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();
int mark[100001];

void permutations1(vec &v,ll i,ll n)
{
    if(n==i)
    {
        print(v);
        return ;
    }

for(int j=1;j<=n;j++)
    if(mark[j]==0){
        v.push_back(j);
        mark[j]=1;
permutations1(v,i+1,n);
v.pop_back();
mark[j]=0;

}


}



void permutations2(vec &v,ll n,ll i)
{
    if(i==n)
    {
        print(v);
        return ;
    }

    for(int j=i;j<n;j++)
{
    swap(v[i],v[j]);
    permutations2(v,n,i+1);
    swap(v[i],v[j]);
}

}



int main() {
    krish;
//wl(t)
{
ll n;
cin>>n;
memset(mark,0,sizeof(mark));
vec v;
//permutations1(v,0,n);

for(int i=1;i<=n;i++)
v.push_back(i);

permutations2(v,n,0);

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