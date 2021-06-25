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
long long power(long long x, long long  y)
{
    int res = 1;  
    x = x % M; 
    if (x == 0) return 0;  
    while (y > 0)
    {
        if (y & 1)   res = (res*x) % M;
              y = y>>1;        x = (x*x) % M;
          }
    return res;
}


void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();

class Stack_ar{
 int s[1000],si=0;
public :
void push(int n)
{
    if(si>=1000)
        cout<<"stack is already full"<<endl;
else
s[si++]=n;
}
void pop()
{
if(si==0)
    cout<<"stack is already empty"<<endl;
else
si--;
}
int top()
{
    if(si==0)
        return -1;
return s[si-1];
}
void empty()
{
if(si==0)
    cout<<"stack is empty"<<endl;
else
    cout<<"stack is not empty"<<endl;
} 
int size()
{
return si;
}
void clear()
{
si=0;
}

};

class node{
public:
    int d;
    node* next;
node(): d(0),next(NULL) {}

};

class Stack_lnk{
    node* head;
int si=0;
public:
    Stack_lnk() : head(NULL){}
void push(int n){
node* nd=new node;
nd->d=n;
nd->next=head;
head=nd;

//cout<<nd->d<<endl;
si++;
}

void pop()
{
    if(!si)
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    node* nd=head;
    head=head->next;
   
    delete nd;
    si--;
}

void empty()
{
if(!si)
    cout<<"stack is empty"<<endl;
else
    cout<<"stack is not empty"<<endl;
} 

int size()
{
return si;
}

int top()
{
    if(si)
    return head->d;
cout<<"stack is empty"<<endl;
return -1;
}

void clear()
{
    node* nd=head;
    while(head!=NULL)
{
    nd=head;
head=head->next;
delete nd;

}
si=0;

}

};
//similarly u can impelement it using vector



int main() {
    krish;



//wl(t)
{

Stack_lnk s;

s.push(1);
s.push(7);
s.push(8);
s.empty();
cout<<s.top()<<endl;
cout<<s.size()<<endl;
s.pop();
cout<<s.top()<<endl;
cout<<s.size()<<endl;
s.clear();
cout<<s.top()<<endl;



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