/*
Q> you are given an array of strings sort them
   lexicographically.

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
node* root=new node;

void sort_n(node *cur,string &s,vector<string> &ans)
{

    for(int i=0;i<cur->end;i++)
ans.push_back(s);
for(auto i:cur->ma)
{
s+=i.fi;
sort_n(i.se,s,ans);
s.pop_back();
}


}



public:

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


vector<string> sort()
{

node *cur=root;
string s="";
vector<string> ans;
sort_n(cur,s,ans);
return ans;
}


};



int main() {
    krish;
  //  wl(t)
{

ll n;
cin>>n;

vector<string> v(n);
trie tr;
for(int i=0;i<n;i++)
cin>>v[i],tr.insert(v[i]);

vector<string> st=tr.sort();

for(auto i: st)
    cout<<i<<" ";
cout<<endl;

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}


//some points to reṇmember
/*
-simple mod not work for -ve numbers;
*/