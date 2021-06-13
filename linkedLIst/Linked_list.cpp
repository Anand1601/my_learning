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
 	ll d;
 	node* next;
 	node(ll x)
 	{
d=x;
next=NULL;
 	}
 };

class Linked_list
{

public:
	node* start;
	node* end;

Linked_list()
{
	start=NULL;
	end=NULL;
}


void push_front(ll x)
{
	node *new_node=new node(x);
	if(!start)
		end=new_node;
		new_node->next=start;
		start=new_node;

}

void push_back(ll x)
{
	/*if(!start)
		start=new node(x);
	else
	{
		node *new_node;
		new_node=start;
		while(new_node->next!=NULL)
		new_node=new_node->next;
	new_node->next=new node(x);
	}*/

node *new_node=new node(x);
if(!start)
{
  start=new_node;
  end=new_node;
}

end->next=new_node;
end=new_node;
}

void push_after(ll x,node* ad)
{

	node* new_node=new node(x);
	if(!ad->next)
		end=new_node;
	new_node->next=ad->next;
    ad->next=new_node;


}


void pop_front()
{
if(!start)
	cout<<"INVALID"<<endl;
else
{
if(!start->next)
	end=NULL;

node *n=start;
start=start->next;
delete n;
}

}

void pop_back()
{
	if(!start)
		cout<<"INVALID"<<endl;
	else if(!start->next)
	{
		end=NULL;
		delete start;
		start=NULL;
	}
	else 
	{

node* temp1;
node *temp2;
temp1=start;
temp2=start->next;
while(temp2->next)
{
temp1=temp1->next;
temp2=temp2->next;

		}
		end=temp1;
		end->next=NULL;
		delete temp2;
}
}

void print_list()
{
node *n_node=start;
if(!start)
cout<<"Linked_list is empty"<<endl;
while(n_node)
	cout<<n_node->d<<" ",n_node=n_node->next;

cout<<endl;
}
void print_recurcively(node* s)
{
	if(!s)
		return;
	cout<<s->d<<" ";
	 print_recurcively(s->next);
}

void print_rec()
{
	print_recurcively(start);
	cout<<endl;
}

//revese linked list---------
void reverse()
{
	node *cur=start;
	node *prev=NULL;
	while(cur)
	{
		node *n_node=cur->next;
	cur->next=prev;
prev=cur;
cur=n_node;
}
swap(start , end);
}
};



int main() {
    krish;
  //  wl(t)
{

Linked_list v;
v.push_front(3);
v.push_front(4);
v.push_front(5);
v.print_list();
v.push_back(7);
v.print_rec();
v.reverse(); 
v.print_list();
v.push_after(11,v.start);
v.print_list();

v.pop_back();
v.pop_front();
v.print_rec();
v.pop_back();
//v.pop_back();
v.print_list();

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}


