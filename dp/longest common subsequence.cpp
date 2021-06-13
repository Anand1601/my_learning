/*Q> you are given two strings find the longest common
subsequence and any one if there are more than on.
INPUT: swdfskd
       dssedfkd
OUTPUT: 5
        sdfkd

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
// wl(t)
{
string s,sx;
cin>>s>>sx;
ll n=s.size()+1;
ll m=sx.size()+1;
vector<vec> v(n,vec(m));



for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
{
    if(i==0||j==0)
        v[i][j]=0;
    else
    {
if(s[i-1]==sx[j-1])
    v[i][j]=1+v[i-1][j-1];
else
    v[i][j]=max(v[i-1][j],v[i][j-1]);

    }
}
string ss="";

ll i=n-1,j=m-1;
while(i>0&&j>0)
{
    if(v[i][j]>v[i-1][j]&&v[i][j]>v[i][j-1])
        i--,j--,ss=s[i]+ss;
    else if(v[i][j-1]>v[i-1][j])
        j--;
    else
        i--;
}
/*
for(int i=0;i<n;i++){
for(int j=0;j<m;j++)
    cout<<v[i][j]<<" ";
cout<<endl;
}*/
cout<<v[n-1][m-1]<<endl;
cout<<ss<<endl;
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