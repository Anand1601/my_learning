//apply binary search on array 

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;   //----for_getting_execution_time
#define ll long long
#define fi first
#define se second
#define pri pair<int,int>
#define M 1000000007
#define pb(x) push_back(x)
#define mpr(x,y) make_pair(x,y)
#define wl(t) int t;cin>>t;while(t--)
#define krish ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
#define vec vector<ll> 
#define inf 3e18


//sort by second a pair
bool bysec(pri a,pri b)  {return (a.se<b.se);}

//sort by second in reverse order
bool bysecriv(pri a,pri b){return (a.se>b.se);}

//sort by first in reverse
bool byrev(pri a , pri b){return (a.fi>a.fi);}
//sort in reverse order
bool rev(int a ,int b){ return (a>b);}

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

void chal(){cout<<"chal rha hun"<<endl;}
//-------------------------------------------solve here---------------------------------//
//auto stt=high_resolution_clock::now();

int findPivot(vec &arr, int low, int high)
{
	if (high < low)
		return -1;
	if (high == low)
		return low;

	int mid = (low + high) / 2;
	if (mid < high && arr[mid + 1] < arr[mid]) 
	{
		return mid;
	}
	if (mid > low && arr[mid] < arr[mid - 1])
	{
		return mid - 1;
	}
	if (arr[low] > arr[mid])
	{
		return findPivot(arr, low, mid - 1);
	}
	else
	{
		return findPivot(arr, mid + 1, high);
	}
}

int main() {
    krish;
    wl(t){
    int n,k;
cin>>n>>k;
vec v(n);
for(int i=0;i<n;i++)
cin>>v[i];

int i=findPivot(v,0,n-1);
 if(k>=v[0])
cout<<binary_search(v.begin(), v.begin()+i+1,k);
 	else
cout<<binary_search(v.begin()+i+2, v.end(),k);
       cout<<endl;
    }
// auto en=high_resolution_clock::now();
// auto diff=duration_cast<microseconds>(en-stt);
// cout<<diff.count()<<endl;
    return 0;
}