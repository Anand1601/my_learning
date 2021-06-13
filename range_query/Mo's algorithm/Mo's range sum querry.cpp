/*
MO'S ALGORITHMS (without update)
Q> you are given an array of n elements and q querries. in each querry
 you have to find the sum of elements b/w the range l to r.

 INPUT: 7 5
        2 3 5 2 6 7 7
        2 4
        1 3
        3 6
        2 5
        1 5

OUTPUT: 13
        10
        22
        20
        23
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



class querry{
public: 
    ll l,r,idx;
    querry(ll lf,ll rt, ll id)
    {
        l=lf;
        r=rt;
        idx=id;
    }
} ;

bool cmp(querry a, querry b)
{
 return a.r<b.r;   
}


int main() {
    krish;
 // wl(t)
{
ll n,q;
cin>>n>>q;

vec v(n);
vec cnt(q,-1);
for(ll &i:v)
    cin>>i;

ll  b=sqrt(n);
ll s=(n+b-1)/b;
//int timer=0;

std::vector<vector<querry>> qrr(s);
for(ll i=0;i<q;i++)
{
    ll lt,rt;
    cin>>lt>>rt;
qrr[lt/b].push_back(querry(lt,rt,i));
}


for(int i=0;i<s;i++)
sort(qrr[i].begin(),qrr[i].end(),cmp);



ll ans=v[0];

ll lf=0,rt=0;

for(auto &i:qrr)
    for(auto &ix:i)
    {
while(lf>ix.l)
   ans+=v[--lf];
while(rt<ix.r)
    ans+=v[++rt];
while(lf<ix.l)
    ans-=v[lf++];
while(rt>ix.r)
    ans-=v[rt--];

cnt[ix.idx]=ans;
}

print(cnt);


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