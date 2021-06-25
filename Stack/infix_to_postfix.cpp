/*
Q) you are given an infix notation (with gaps b/w different expressions)
every string is single digit ans stop taking input when 0 incounter. 
now convert this to postfix.	
 input: x * y / ( 5 * z ) + 2
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
#define wl(t) int t; cin>>t; while(t--)
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

int fun(string x)
{
    if(x=="*"||x=="/")
        return 1;
    return 2;
}

int main() {
    krish;
//wl(t)
{

vector<string> s;

string ans;
cin>>ans;
while(ans!="0")
{
    s.push_back(ans);
    cin>>ans;
}
ans="";
stack<string> sx;

for(int i=0;i<s.size();i++){
if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/"&&s[i]!="("&&s[i]!=")")
ans+=s[i];    
else if(s[i]==")")
{
while(sx.top()!="(")
{
    ans+=sx.top();
    sx.pop();
}
sx.pop();
}
else
{
    if(sx.empty()||s[i]=="("){
        sx.push(s[i]);
        continue;
    }

while(sx.size()!=0&&sx.top()!="("&&fun(sx.top())<=fun(s[i]))
    ans+=sx.top(),   sx.pop();
sx.push(s[i]);
}
cout<<ans<<endl;
}
while(!sx.empty())
    ans+=sx.top(),sx.pop();
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