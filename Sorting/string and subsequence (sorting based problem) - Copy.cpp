/*
Q. you are given to string s(1<=|s|<=10^5) and t(1<=|t|<=26) contain only lowercase alphabates and t 
contains unique characters (no one is repeating) .print any permutation of s for which t is not a 
subsequence of string s. if there is no such permutation the print -1
*/

// solution 1
#include <bits/stdc++.h>

using namespace std;

int main() {
string s,t;
cin>>s>>t;
string x="";
int j=0,i=0;
bool st=false;
sort(s.begin(),s.end());
for( i=0;i<s.size()&&j<t.size();i++)
if(s[i]==t[j])
{
    x=s[i]+x;
    j++;
    st=true;
}
else
x+=s[i];
if(st&&t.size()==1)
{
    cout<<-1<<endl;
    continue;
}
while(i<s.size())
x+=s[i++];
    cout<<x<<endl;
}



//solution 2;
/*
if t is in sorted order then reverse sort s vice-varsa;
else sort in any order;
*/