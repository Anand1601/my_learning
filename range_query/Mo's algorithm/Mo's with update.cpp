/*
MO'S ALGORITHMS 
https://cses.fi/problemset/task/1648/
Dynamic Range Sum Queries

similarly u can do for query of addition of x at index i which
 is more simpller then this que 1648
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
auto stt=high_resolution_clock::now();
ll b;


class querry{
public: 
    ll l,r,idx,tm;
    querry(ll lf,ll rt, ll id,ll t)
    {
        l=lf;
        r=rt;
        idx=id;
        tm=t;
    }
} ;

bool cmp(querry aa, querry ba)
{
 return (aa.l/b<ba.l/b) or (aa.l/b==ba.l/b and aa.r/b<ba.r/b) or
 (aa.l/b==ba.l/b and aa.r/b==ba.r/b and aa.tm<ba.tm);   
}


int main() {
    krish;
 // wl(t)
{
ll n,q;
cin>>n>>q;
vec v(n);
for(ll &i:v)
    cin>>i;
  b=sqrt(n);
//ll s=(n+b-1)/b;
int timer=-1,tx=0;

std::vector<querry> qrr;
std::vector<pri> update;
for(ll i=0;i<q;i++)
{
    ll lt,rt,x;
cin>>x>>lt>>rt;
lt--;
rt--;
if(x==2)
qrr.push_back(querry(lt,rt,tx,timer)),tx++;
else
update.push_back({lt,rt+1}),timer++;
}

sort(qrr.begin(),qrr.end(),cmp);

vec cnt(qrr.size(),-1);
//cout<<qrr.size()<<endl;
ll ans=v[0];

ll lf=0,rt=0,ut=-1;

for(auto &ix:qrr){

while(ut<ix.tm){ut++;
    if(lf<=update[ut].fi and rt>=update[ut].fi)
        ans-=v[update[ut].fi],ans+=update[ut].se;
    swap(v[update[ut].fi],update[ut].se);
}

//cout<<"a"<<ut<<" "<<ix.tm<<endl;
while(ut>ix.tm){
 //   cout<<ut<<endl;
 if(lf<=update[ut].fi and rt>=update[ut].fi)
        ans-=v[update[ut].fi],ans+=update[ut].se;
    swap(v[update[ut].fi],update[ut].se);
    ut--;

}

//cout<<"b"<<endl;
while(lf>ix.l)
   ans+=v[--lf];


while(rt<ix.r)
    ans+=v[++rt];

while(lf<ix.l)
    ans-=v[lf++];


while(rt>ix.r)
    ans-=v[rt--];



cnt[ix.idx]=ans;
//cout<<ans<<endl;
//chal();

}

print(cnt);


}
/*auto en=high_resolution_clock::now();
 auto diff=duration_cast<microseconds>(en-stt);
 cout<<diff.count()<<endl;*/
    return 0;
}


//some points to remember
/*
-simple mod not work for -ve numbers;
*/