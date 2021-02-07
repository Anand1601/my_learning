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

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();


vec get_subset(vec v)
{
    
    vec vx;
    for(int i=0;i<pow(2,v.size());i++)
    {
     int j=i,k=0;
     ll sum=0;
     while(j>0)
     {
         if(j%2)
         {
             sum+=v[k];
         }
         j>>=1;
         k++;
     }
    vx.push_back(sum); 
    }
    return vx;
}


int main() {
    krish;
//wl(t)
{

ll n,a,b;
cin>>n>>a>>b;
vec v(n);
for(ll &i:v)
cin>>i;

vec l(v.begin(),v.begin()+n/2);
vec r(v.begin()+n/2,v.end());

vec lf=get_subset(l);
vec rt=get_subset(r);

sort(rt.begin(),rt.end());
ll cnt=0;
for(int i=0;i<lf.size();i++)
{
cnt+=upper_bound(rt.begin(),rt.end(),b-lf[i])-lower_bound(rt.begin(),rt.end(),a-lf[i]);

}

cout<<cnt<<endl;
}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}