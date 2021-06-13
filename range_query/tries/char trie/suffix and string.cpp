/*Q> you are given two type of queries.
1. insert string s in the list.
2. find the no. of strings having suffix as sx.

INPUT: 6
       1 str
       1 sssttr
       2 tr
       2 ttr
       1 tr
       2 tr

OUTPUT:2
       1
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
 
class node{
public: 
    ll cnt,end;
    map<char,node*> ma;
 node()
    {
cnt=0;
end=0;
    }
};

class trie{
node *root=new node;
public :

    void insert(string s)
    {
node *cur=root;
for(int i=0;i<s.size();i++)
{
    cur->cnt++;
    if(!cur->ma[s[i]])
        cur->ma[s[i]]=new node;
    cur=cur->ma[s[i]];

}

cur->cnt++;
cur->end++;

    }

int suffix_cnt(string s)
{

node *cur=root;
for(int i=0;i<s.size();i++)
{
if(!cur->ma[s[i]])
    return 0;
cur=cur->ma[s[i]];
}

return cur->cnt;
}

};

int main() {
    krish;
  //  wl(t)
{

int n,x;
string s;\
trie tr;
cin>>n;while(n--)
{
    cin>>x>>s;
    reverse(s.begin(),s.end());
    if(x==1)
        tr.insert(s);
    else
cout<<tr.suffix_cnt(s)<<endl;

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