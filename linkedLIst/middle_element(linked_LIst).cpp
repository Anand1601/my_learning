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
class node {
public:
	ll data;
	node * next;

	node (ll d)
	{
		data=d;
		next=NULL;
	}
} ;


class Linked_list{
	 public:
	 node *head;

	 Linked_list()
	 {
head=NULL;
	}

void push_front(ll d)
{
	node* new_nod=new node(d);
	
		new_nod->next=head;
		head=new_nod;
}

void print_iter()
{
	node* cur=head;
	while(cur)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}

ll middle_element()
{
	node* fast=head,*cur,*prev;
	cur=head,prev=NULL;
	while(fast && fast->next)
	{
prev=cur;
cur=cur->next;
fast=fast->next->next;

	}
if(!fast)
	return (prev->data+cur->data)/2;
return cur->data;

}



};


int main() {
    krish;
  //  wl(t)
{
Linked_list l;
l.push_front(5);
//l.print_iter();
l.push_front(6);
l.push_front(9);

l.print_iter();
cout<<l.middle_element()<<endl;
l.push_front(3);
l.print_iter();
cout<<l.middle_element()<<endl;
}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}