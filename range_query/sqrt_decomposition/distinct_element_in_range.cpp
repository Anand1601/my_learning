/*
Q::you are given an array of N elements and Q queries.in each query
find the number of distinct element in the range L to R .
Input : a[] = {1, 1, 2, 1, 3}
        q = 3
        0 4
        1 3
        2 4
Output :3
        2
        3
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

    ll n,q,l,r;
    cin>>n;
    vec v(n);
map<ll,ll> ma;
    for(ll &i:v){
        cin>>i;
        ma[i]=n+1;
    }

  vec next(n,n+1);

for(int i=n-1;i>=0;i--)
{
    next[i]=ma[v[i]];
    ma[v[i]]=i;
}

    ll b=sqrt(n);
ll s=(n+b-1)/b;

std::vector<vec> vx(s);

for(int i=0;i<n;i++)
    vx[i/b].push_back(next[i]);

//chal();
for(int i=0;i<s;i++)
    sort(vx[i].begin(),vx[i].end());



cin>>q;
while(q--)
{
cin>>l>>r;

// left
ll end=(l/b)*b+b-1;
ll cnt=0;
for(int i=l;i<=min(end,r);i++ )
    if(next[i]>r)
        cnt++;

    if(l/b!=r/b)
    {
        //right part
        for(int i=(r/b)*b;i<=r;i++)
            if(next[i]>r)
                cnt++;
// intermediate
            for(int i=l/b+1;i<r/b;i++)
        cnt+=vx[i].end()-upper_bound(vx[i].begin(),vx[i].end(),r);
    }
cout<<cnt<<endl;

}



}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}