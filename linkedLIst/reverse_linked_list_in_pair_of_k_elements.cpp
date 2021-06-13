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
 	ll data;
 	node* next;
 	node(ll d)
 	{
 		data=d;
 		next=NULL;
 	}
 };

 class Linked_List{
 public: 
 	node *head;

 	Linked_List()
 	{
head=NULL;
 	}

 	void push_front(ll d)
 	{
node *new_node=new node(d);
new_node->next=head;
head=new_node;

 	}

void print_r(node* new_node)
{
	if(!new_node)
		return;
	cout<<new_node->data<<" ";
	print_r(new_node->next);
}

void print_rec()
 	{

node *new_node=head;
print_r(head);
cout<<endl;
 	}

node* rev_in_k(node *new_node,ll k)
{

    if(!new_node)
        return NULL;
    ll cnt=0;
    node* cur=new_node,*prev=NULL;
    while(cur&&cnt<k)
    {
node* new_no= cur->next;
cur->next=prev;
prev=cur;
cur=new_no;
cnt++;
    }
new_node->next=rev_in_k(cur,k);
return prev;

}



 };



int main() {
    krish;
  //  wl(t)
{
Linked_List l;
ll n,k;
cin>>n>>k;
vec v(n);
for(ll &i:v)
cin>>i;

for(int i=n-1;i>=0;i--)
l.push_front(v[i]);
l.print_rec();
node* new_head=l.rev_in_k(l.head,k);
l.head=new_head;
l.print_rec();

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}