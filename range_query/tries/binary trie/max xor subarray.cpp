//BINARY TRIES

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
/*
https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
*/
class node{
  public :
  node* child[2];
  node()
  {
    child[0]=NULL;
    child[1]=NULL;
  }
};

class trie{

public:
  node *root =new node;
void insert(ll n)
{
  node *cur=root;
for(int i=29;i>=0;i--)
{
ll b=(n>>i)&1;
if(cur->child[b]==NULL)
cur->child[b]=new node;
cur=cur->child[b];
}

}

};


int main() {
    krish;
  //  wl(t)
{
ll n,x;
cin>>n;
vec v(n);
trie tr;
for(int i=0;i<n;i++)
  cin>>v[i];

for(int i=1;i<n;i++)
v[i]^=v[i-1];

for(int i=0;i<n;i++){
  tr.insert(v[i]);
}
ll ans=0,cnt=0;
for(int i=0;i<n;i++)
{
x=v[i];
cnt=0;
  node *cur=tr.root;
for(int i=29;i>=0;i--)
{

ll b=(x>>i)&1;

if((cur->child[1-b])!=NULL){
  //cout<<i<<" . "<<1-b<<endl;
  cnt+=pow(2,i);
  cur=cur->child[1-b];
}
else{
cur=cur->child[b];
}
}
ans=max(cnt,ans);

}
cout<<ans<<endl;
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