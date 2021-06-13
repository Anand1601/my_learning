Q> you are given two type of querries.
1. insert string s into the list/datastructure.
2. find if string sx can be formed by concatenating


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
    map<char,node*> child;
 node()
    {
cnt=0;
end=0;
    }
};

class fwr_trie{
node* root=new node;
public:

    void insert(string s)
    {
node *cur=root;
for(int i=0;i<s.size();i++)
{
    cur->cnt++;
    if(!cur->child[s[i]])
        cur->child[s[i]]=new node;
    cur=cur->child[s[i]];

}

cur->cnt++;
cur->end++;

    }

    int find(string &s)
{
node *cur= root;
for(char c: s)
{
    if((cur->child).count(c)==0)
        return 0;
cur=cur->child[c];
}
return cur->end;
}

};

class bwr_trie{
node *root=new node;

public:
        void insert(string s)
    {
node *cur=root;
for(int i=0;i<s.size();i++)
{
    cur->cnt++;
    if(!cur->child[s[i]])
        cur->child[s[i]]=new node;
    cur=cur->child[s[i]];

}

cur->cnt++;
cur->end++;

    }

    int find(string &s)
{
node *cur= root;
for(char c: s)
{
    if((cur->child).count(c)==0)
        return 0;
cur=cur->child[c];
}
return cur->end;
}


};


int main() {
    krish;
  //  wl(t)
{
int n,x;
string s;
cin>>n;
fwr_trie trf;
bwr_trie trb;
while(n--)
{
cin>>x>>s;
if(x==1)
{
trf.insert(s);
string sx="";
for(int i=s.size()-1;i>=0;i--)
sx+=s[i];
trb.insert(sx);
}
else
{
vec f(s.size(),0);
vec b(s.size(),0);
string sx="";

for(int i=0;i<s.size();i++)
{
    sx+=s[i];
    f[i]=trf.find(sx);
}

sx="";
for(int i=s.size()-1;i>=0;i--)
{
sx+=s[i];
b[i]=trb.find(sx);
}

if(s.substr(0,s.size()/2)==s.substr(s.size()/2,s.size()/2))
{
    if(b[s.size()/2]>1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    continue;
}

bool st=false;
for(int i=0;i<b.size()-1;i++)
    if(f[i]>0&&b[i+1]>0){
        st=true;
        break;
}

if(st)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;


}


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