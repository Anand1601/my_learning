#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pri pair<int,int>
#define M 1000000007
#define pb(x) push_back(x)
#define mpr(x,y) make_pair(x,y)
#define fr(i,n) for(auto i=0;i<n;i++)
#define ifor(i,s,n) for(auto i=s;i<n;i++)
#define rfor(i,n) for(auto i=n-1;i>=0;i--)
#define wl(t) int t,cin>>t,while(t--)
#define krish ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
#define vec vector<ll> 
//sort by second a pair
bool bysec(pri a,pri b)  {return (a.se<b.se);}

//sort by second in reverse order
bool bysecriv(pri a,pri b){return (a.se>b.se);}

//sort by first in reverse
bool byrev(pri a , pri b){return (a.fi>a.fi);}
//sort in reverse order
bool rev(int a ,int b){ return (a>b);}

// print the array
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

//status
void chal(){cout<<"chal rha hun"<<endl;}



//-------------------------------------------solve here---------------------------------//
int ma=0;
int n;
void merge(int *a,int l,int r,int m)
{
    int b[r-l+1];
    int k=0;
    int i=l,j=m+1;

    for(;i<=m&&j<=r;k++)
    {
        
        if(a[i]<=a[j])
        b[k]=a[i],i++;
        else b[k]=a[j],j++;
        
    }
  
    while(i<=m)
    b[k++]=a[i++];
    while(j<=r)
    b[k++]=a[j++];
    
  
    for(int i=0;i<k;i++)
    a[i+l]=b[i];
}


void opti_merge(int *a,int l,int r,int m)
{

    int i=l,j=m+1;
int k=l;
//cout<<l<<" "<<m<<" "<<r<<endl;
    for(;i<=m&&j<=r&&k<=r;k++)
    {
        if(a[i]%ma<=a[j]%ma)
        a[k]+=((a[i]%ma)*ma),i++;
        else a[k]+=((a[j]%ma)*ma),j++;
        
    }
     
 
    while(i<=m)
    a[k++]+=(a[i++]%ma)*ma;
    while(j<=r)
    a[k++]+=(a[j++]%ma)*ma;
    
 
    for(int i=l;i<=r;i++)
    a[i]/=ma;
    
}

void merge_sort(int *a,int l, int r)
{
 if(l>=r)
 return;
 int mid=(l+r)/2;
 merge_sort(a,l,mid);
 merge_sort(a,mid+1,r);
 //------------------------space complexity O(n)---------------------//
 //merge(a,l,r,mid);  
 //-----------------space comlexity O(1)------------------------//
 opti_merge(a,l,r,mid);   
   
}



int main() {
    krish;
    //solve
    
    cin>>n;
    int *a=new int[n];
    fr(i,n){
    cin>>a[i];
    if(ma<a[i])ma=a[i];
    }
    ma++;
    merge_sort(a,0,n-1);
    print(a,n);
    
    return 0;
}