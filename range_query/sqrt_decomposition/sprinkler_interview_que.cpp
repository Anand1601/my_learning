/*
Q. Given an array of n elements. you have to answer some querries.
in each query 
you get (i,d);
find the sum of a[i]+a[i+d]+a[i+2d]+.. untill i+xd<=n;
constrains:
1<=n,q<=n;

INPUT:10 4
      1 2 3 4 5 6 7 8 9 10
      1 2 
      0 3
      2 3
      3 4

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
  //  wl(t)
{
ll n,q;
cin>>n>>q;
vec v(n);
for(ll &i:v)
cin>>i;
ll l,d;
l=sqrt(n);
std::vector<vec> ans(l+1,vec(n+1,0));

for(int i=l-1;i>=0;i--)
for(int j=n-1;j>=0;j--)
{
if(j+i+1<n)
  ans[i][j]=v[j]+ans[i][i+j+1];
else
ans[i][j]=v[j];
}

/*
// print the table formed for precompution

    for(int j=0;j<sqrt(n);j++)
     { for(int i=0;i<n;i++)
      cout<<ans[j][i]<<" ";
      cout<<endl;
}*/


while(q--){
cin>>l>>d;

if(d<=sqrt(n))
{
  cout<<ans[d-1][l]<<endl;
}
else
{ 
  ll cnt=0;
  for(int i=l;i<n;i+=d)
cnt+=v[i];
cout<<cnt<<endl;
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