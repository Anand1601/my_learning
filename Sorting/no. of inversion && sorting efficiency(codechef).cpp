//lec-14

#include <iostream>
using namespace std;

void chal()
{cout<<"chal rha hun"<<endl;}



int merge(int *a,int l,int m,int h)
{
    int x=0;
    int b[h-l+1];
int i=0,j=m+1,k=0;
while(i<=m&&j<=h)
{
  // chal();

if(a[i]<=a[j])
b[k]=a[i],i++;
else
{
    x+=j-i;
  b[k]=a[j];
  j++;
}
k++;
}


while(i<=m)
{
    b[k]=a[i];
    i++,k++;
    
}
while(j<=h)
{
    b[k]=a[j];
    j++;
    k++;
}
for(int i=l;i<=h;i++)
a[i]=b[i];
//cout<<x<<endl;
return x;
    
}


int sort(int *a,int l,int h)
{
    int x=0;
    if(l>=h)
    return 0;

    int mi=(l+h)/2;
x+=sort(a,l,mi);
x+=sort(a,mi+1,h);
x+=merge(a,l,mi,h);
//cout<<x<<"---"<<endl;
return x;
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
 int x=sort(a,0,n-1);
 cout<<x<<endl;
}

