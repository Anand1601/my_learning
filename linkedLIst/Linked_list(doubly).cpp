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
    ll d;
node *next;
node *pre;
node(ll x)
{
    d=x;
    next=NULL;
    pre=NULL;
}

 };

class Linked_List
{
    public:
node *start,*end;
ll size;

Linked_List()
{
    start=NULL;
    end=NULL;
    size=0;
}


void push_front(ll x)
{
    node *new_node=new node(x);
    if(!start){
        start=new_node;
        end=new_node;
    }
    else
    {
       new_node->next=start;
       start->pre=new_node;
       start=new_node;
    }
    size++;
}

void push_back(ll x)
{
   node *new_node=new node(x);
   if(!start)
   {
    start=new_node;
    end=new_node;
   }
   else
   {
    new_node->pre=end;
    end->next=new_node;
    end=new_node;
   }
   size++;
}

void push_after(node *cur,ll x)
{
node *new_node=new node(x);
    if(cur==end){
        cur->next=new_node;
        new_node->pre=cur;
        end=new_node;
    }else
    {
    cur->next->pre=new_node;
    new_node->next=cur->next;
    cur->next=new_node;
    new_node->pre=cur;
}
size++;
}

void pop_front()
{
    if(!start)
    return;
    if(!start->next)
    {
        end=NULL;
        delete start;
        start=NULL;
    }
    else
    {
node* cur=start;
start->next->pre=NULL;
start=start->next;
delete cur;
    }
    size--;
}

void pop_back()
{
    if(!start)
        return ;
    if(!start->next)
    {
         end=NULL;
        delete start;
        start=NULL;

    }
    else
    {
       node* cur=end;
end->pre->next=NULL;
end=end->pre;
delete cur;
    }
}


void printlist()
{
    node* cur=start;
    while(cur)
        cout<<cur->d<<" ",cur=cur->next;
    cout<<endl;
}

void reverse()
{
    node* cur=start;
    while(cur)
    {
swap(cur->next,cur->pre);
cur=cur->pre;
    }
    swap(start,end);
}



};


int main() {
    krish;
  //  wl(t)
{

Linked_List l;
l.push_front(5);
l.push_back(4);
l.push_front(3);
l.printlist();
l.reverse();
l.printlist();
l.pop_front();
l.printlist();
l.pop_back();
l.printlist();

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}