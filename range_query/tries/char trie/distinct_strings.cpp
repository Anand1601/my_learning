/*Q> you are given three type of querries.
1.insert string x in list.
2.delete string x form list.(it is garantee that atleat one x present)
3. find the no. of distinct element currently present in the list.
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
public:

void insert(string s)
{
node *cur=root;
for(auto i: s)
{
    cur->cnt++;
    if(!cur->ma[i])
cur->ma[i]=new node;

cur=cur->ma[i];
}
cur->cnt++;
cur->end++;

}

void count(node *cur,ll &ct)
{
    if(cur->end>0)
        ct++;
    for(auto i:cur->ma)
    {
        count(i.se,ct);
    }
}


int distinct()
{
     node *cur=root;
ll ct=0;
count(cur,ct);
return ct;
}


void actual_erase(string s)
{


    node *cur=root,*go;
    cur->cnt--;
    for(char c:s)
    {
        cur->ma[c]->cnt--;
        if(c==s[s.size()-1])
            cur->ma[c]->end--;
         go=cur->ma[c];
         if(cur->ma[c]->cnt==0)
         cur->ma.erase(c);

        if(cur!=root&&cur->cnt==0)
delete(cur);
    
cur=go;
    }

if(go->cnt==0)
    delete(go);

}


};




int main() {
    krish;
  //  wl(t)
{
ll n,x;
cin>>n;
trie tr;

while(n--)
{
    cin>>x;
    if(x==3)
    {
        cout<<tr.distinct()<<endl;
        continue;
    }
    string s;
    cin>>s;

if(x==1)
    tr.insert(s);
else
    tr.actual_erase(s);

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