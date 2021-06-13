/*
Q:: you are given an array of N elements and Q queries.there are two type of 
queries [0 l r] (find the number of distinct element in the range L to R ) 
and [1 l a] replace the value at index l to a . 

Input : n=5,q = 7
a[] = {1, 1, 2, 1, 3}
0 0 4
0 1 3
1 1 4
0 1 4
1 3 2
0 1 3
0 2 3

Output :
3
2
4
2
1
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

	ll n,q,x,l,r;
	cin>>n>>q;
	vec v(n);   // array of numbers 
	
map<ll,ll>m;   // to make the array of next and pre index of no.
map<ll,set<ll>> ele;   // to get all the indices of a perticualr element
for(ll &i:v)
	cin>>i,m[i]=n+1;

for(int i=0;i<n;i++)
	ele[v[i]].insert(i);
// next arr which store the next occurance of an element 
// pre arr which store the previous occurrance of an element
std::vector<ll> next(n,n+1),pre(n,-1);

for(int i=n-1;i>=0;i--)
	next[i]=m[v[i]],m[v[i]]=i;

for(int i=0;i<n;i++)
	m[v[i]]=-1;
for(int i=0;i<n;i++)
pre[i]=m[v[i]],m[v[i]]=i;


ll b=sqrt(n);
ll s=(n+b-1)/b;
std::vector<vec> vx(s);
for(int i=0;i<n;i++)
vx[i/b].push_back(next[i]);

for(int i=0;i<s;i++)
sort(vx[i].begin(),vx[i].end());


while(q--)
{
	cin>>x;
	if(x==0)
	{
cin>>l>>r;

//left
ll end=(l/b)*b+b-1,cnt=0;
for(ll i=l;i<=end;i++)
	if(next[i]>r)
		cnt++;

	if(l/b!=r/b)
	{
		// right
ll str=(r/b)*b;
		for(ll i=str;i<=r;i++)
			if(next[i]>r)
				cnt++;
			//intermediate
			for(int i=l/b+1;i<r/b;i++)
cnt+=vx[i].end()-upper_bound(vx[i].begin(),vx[i].end(),r);
	}
cout<<cnt<<endl;
	}
	else
	{




cin>>l>>x;
if(v[l]==x)
continue;
//changes for removal of prev value


// itv - to change the element in vx array due to addition of new element(if possible).
auto itv=lower_bound(vx[l/b].begin(),vx[l/b].end(),next[l])-vx[l/b].begin();
// itv1 - to change the element in vx array due to removal of pre value(if possible).
auto itv1=lower_bound(vx[pre[l]/b].begin(),vx[pre[l]/b].end(),l)-vx[pre[l]/b].begin();
ll tep=pre[l];
if(pre[l]!=-1)
next[pre[l]]=next[l];
if(next[l]!=n+1)
pre[next[l]]=pre[l];

//changes for adding new value
set<ll> ::iterator it=ele[x].upper_bound(l);

ele[v[l]].erase(l);

v[l]=x;

if(it==ele[x].end())  //if upper_bound of l doesn't exist 
{	
	next[l]=n+1;

if(ele[x].size()==0)    // if the element is to be added ,not present in whole array befor.  
	pre[l]=-1;
else      // if present befor
{            
    it--;
pre[l]=*it;
next[*it]=l;
}
ele[x].insert(l);
}
else{
	next[l]=*it;
if(pre[*it]!=-1)
{
	next[pre[*it]]=l;
	next[l]=pre[*it];
}
else
pre[l]=-1;
pre[*it]=l;

ele[x].insert(l);
}

vx[l/b][itv]=next[l];      //chage value in the array from which the index l belongs.
vx[tep/b][itv1]=next[tep];  // change the value in array from where pre[l] belongs.

// we can use left or right shifting of element  and get the sorting by swap 
//in O(n) . 
sort(vx[tep/b].begin(),vx[tep/b].end());
sort(vx[l/b].begin(),vx[l/b].end());
	}
	
	
// use the below one to see how changes are occuring.
	/*
	
	cout<<"next"<<endl;
print(next);

cout<<"pre"<<endl;
print(pre);

cout<<"v"<<endl;
print(v);


cout<<"vx"<<endl;
for(int i=0;i<s;i++)
{
    for(int j=0;j<vx[i].size();j++)
    cout<<vx[i][j]<<" ";
    cout<<endl;
    
}

*/
		
}

}

// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}