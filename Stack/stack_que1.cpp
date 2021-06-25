/*
Q) your are given a n cars  permutation of 1 to n.
you have to remove it from right as 1, 2,....n.
for achiving this u also given an another stack where the car can 
weigth . print "YES" if it is possible to do so else print "NO".

eg.
input 1:
5
5 4 1 3 2
"NO"

input 2:
5
5 4 3 2 1
"YES"

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






int main() {
    krish;
//wl(t)
{
ll n,x;
cin>>n;
vec v(n);
stack<int> a,b;
for(int i=0;i<n;i++)
cin>>x,a.push(x);
bool st=true;

for(int i=1;i<=n;i++)
{

if(b.size()!=0&&b.top()==i)
{
    b.pop();
    continue;
}

while(a.size()!=0&&a.top()!=i)
    {
//cout<<a.top()<<" ";
b.push(a.top());
a.pop();
    }
  
if(a.size()!=0&&a.top()==i)
{
    a.pop();
    continue;
}

if(b.size()==0||b.top()!=i)
{
    st=false;
    break;
}
b.pop();


}

if(st)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;


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