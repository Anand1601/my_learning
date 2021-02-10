/* find such x so that f(x)=n
where f(1234)=1234+123+12+1=1370;
input : n;
output: x;
*/

#include<iostream>
using namespace std;
int f(int mid)
{
    int sum=0;
    
    while(mid>0){
    sum+=mid;
    mid/=10;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
int l=0,r=n;
int ans=-1;
while(l<r)
{
    int mid=(l+r)/2;
    
    if(f(mid)>n)
    r=mid-1;
    else if(f(mid)<n)
    l=mid+1;
    else{
    ans=mid;

        break;
    }
        
    }
    cout<<ans<<endl;
}