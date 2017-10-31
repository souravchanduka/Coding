#include <bits/stdc++.h>
using namespace std;

string mul(string A, char x)
{
    string t="";
    int c=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        int m=c+(int)(x-'0')*(int)(A[i]-'0');
        t+=(char)((m%10) + '0');
        c=m/10;
    }
    if(c)
        t+=(char)(c + '0');
    reverse(t.begin(),t.end());
    return t;
}
string add(string A, string B)
{
    string a,b,c="";
    if(A.size()>=B.size())
    {
        a=A;b=B;
    }
    else
    {
        a=B;b=A;
    }
    if(b=="")
        return a;
    int ca=0;
    for(int i=b.size()-1;i>=0;i--)
    {
        int x=(int)(b[i]-'0') + (int)(a[i+a.size()-b.size()]-'0') + ca;
        c+=(char)((x%10) + '0');
        ca=x/10;
    }
    for(int i=a.size()-b.size()-1;i>=0;i--)
    {
        int x=ca+(int)(a[i]-'0');
        c+=(char)((x%10)+'0');
        ca=x/10;
    }
    if(ca)
        c+=(char)(ca + '0');
    reverse(c.begin(),c.end());
    return c;
}
int main()
{
    // static const int arr[]= {80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90};
    
    // vector <int> A (arr,arr+sizeof(arr)/sizeof(arr[0]));
    string A="99999",B="99999",x="",z="";
    for(int i=B.size()-1;i>=0;i--)
    {
        string m=mul(A,B[i]);
        m+=z;
        z+="0";
        x=add(x,m);
        cout<<"m "<<m<<endl<<"x "<<x<<endl;
    }
    return 0;
}