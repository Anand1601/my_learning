/*
## BINARY TRIE
Q> you are given an array of n integers and m querries.
   there are 3 type of queeries 
   1 . inset the element x in array.
   2 . delete the element x from x.
   3 . check if the element x present or not in array.

INPUT: 8
       1 2 3 4 4 5 6 9 
       9
       3 8
       1 8
       3 8
       2 4
       3 4
       2 4
       3 4
       2 9
       3 9

OUTPUT: 0
        1
        1
        0
        0    

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
 
class node{
	public :
	node* nd[2];
ll arr[2];

node()
{
	nd[0]=NULL;
	nd[1]=NULL;
	arr[0]=0;
	arr[1]=0;
}

};


class binarry_trie{
	node* root=new node ;
public:

void insert(ll n)
{
	node *cur=root;
for(int i=29;i>=0;i--)
{
	ll b=(n>>i)&1;
if(cur->nd[b]==NULL)
	cur->nd[b]=new node;

cur->arr[b]++;
cur=cur->nd[b];
}

}
void remove(ll n)
{
  node *cur=root;
std::vector<node*> v;
for(int i=29;i>=0;i--)
{
	ll b=(n>>i)&1;
cur->arr[b]--;
node *go_to=cur->nd[b];
if(cur->arr[b]==0)
{
cur->nd[b]=NULL;
v.push_back(go_to);
}
cur=go_to;
}

for(int i=0;i<v.size();i++)
	delete v[i];
}


bool find(ll n)
{

node *cur=root;

for(int i=29;i>=0;i--)
{
	ll b=(n>>i)&1;
	if(cur->nd[b]==NULL)
		return false;
	cur=cur->nd[b];
}

return true;

}

};


int main() {
    krish;
  //  wl(t)
{

ll n ,x;
cin>>n;
binarry_trie tr;
for(int i=0;i<n;i++)
{
	cin>>x;
tr.insert(x);
}
cin>>x;
ll y,z;
while(x--){
cin>>y>>z;
if(y==1)
tr.insert(z);
else if(y==2)
tr.remove(z);
else
cout<<tr.find(z)<<endl;
}


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