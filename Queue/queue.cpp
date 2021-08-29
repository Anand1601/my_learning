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
class queue_arr{
vec v;
int start=0,end=-1;
public:

    void push(int x)
    {
        if(end==-1)
            end=0;
            end++;
v.push_back(x);
    }

    void pop(){
        if(start==end)
        return ;
        start++;
    }

int size()
{
   
return max(end-start,0);
}

bool empty()
{
    if(end<=start)
        return true;

    return false;
}

void clear()
{
    v.clear();
    start=0;
    end=-1;
}

int back()
{
    if(start<end)
    return v[start];
return -1;
}
int front()
{
    if(start<end)
return v.back();
return -1;
}
};


int main() {
    krish;
//wl(t)
{

queue_arr s;
cout<<s.empty()<<endl;
s.push(5);
cout<<s.size()<<endl;
s.push(7);
cout<<s.size()<<endl;
cout<<s.empty()<<endl;

cout<<s.front()<<endl;
cout<<s.back()<<endl;
s.pop();
s.pop();
s.push(12);
cout<<s.size()<<endl;
cout<<s.empty()<<endl;
cout<<s.front()<<endl;
cout<<s.back()<<endl;

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