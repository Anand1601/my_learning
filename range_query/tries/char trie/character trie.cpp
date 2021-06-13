/*
Q> you are given an array of string s and q querries. there
three type of querries. 
1. add string x to the list.
2. remove x from list if present.
3. find count of string s.

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
 
 class node{
 	public :
 	ll cnt,end;
 	map<char,node*> child;
 	node() : cnt(0),end(0){};

 };

class Btrie{
	node *root=new node;
public:
void insert(string &s)
{
node *cur=root;

for(int i=0;i<s.size();i++)
{
	cur->cnt++;
	if((cur->child).count(s[i])==0)
	cur->child[s[i]]=new node;

cur=cur->child[s[i]];
}

cur->cnt++;
cur->end++;

}


int find(string &s)
{
node *cur= root;
for(char c: s)
{
	if((cur->child).count(c)==0)
		return 0;

/*if(c==s[s.size()-1]&&(cur->child[c])->end<=0)
	return 0;*/
cur=cur->child[c];
}
return cur->end;
}

void erase(string s)
{

if(find(s)==0)
	return;

	node *cur=root;
for(int i=0;i<s.size();i++)
{
	cur->cnt--;
	cur=cur->child[s[i]];
}

cur->cnt--;
cur->end--;
}


void actual_erase(string s)
{
	if(find(s)==0)
		return;

	node *cur=root,*go;
	cur->cnt--;
	for(char c:s)
	{
		cur->child[c]->cnt--;
		if(c==s[s.size()-1])
			cur->child[c]->end--;
		 go=cur->child[c];
		 if(cur->child[c]->cnt==0)
		 cur->child.erase(c);

		if(cur!=root&&cur->cnt==0)
delete(cur);
	
cur=go;
	}

if(go->cnt==0)
	delete(go);

}



};


int main() {
    krish;
  //  wl(t)
{
ll n,m;
cin>>n>>m;
string s;

Btrie tr;

for(int i=0;i<n;i++){
	cin>>s;
tr.insert(s);
}
cout<<"queris "<<endl;
while(m--)
{
	cin>>n>>s;
	if(n==1)
		tr.insert(s);
	else if(n==2)
		cout<<tr.find(s)<<endl;
	else if(n==3)
		tr.erase(s);       //either use erase or actual_erase
else if(n==4)             
	tr.actual_erase(s);
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