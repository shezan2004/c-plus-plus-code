#include<iostream>
using namespace std;
int main ()
{
    int i;
    int a[5];
    for(i=0; i<5; i++)
    {
        cin>>a[i];
    }
    int fn= a[0];
    int sn = INT16_MIN;
    int ln = INT16_MIN;
    for(i=1;i<5; i++)
    {
        if(a[i]>fn)
        {
            fn = a[i];
        }
    }
    cout<<fn<<endl;
    for(i=1;i<5; i++)
    {
        if((a[i]>sn) && (a[i]!=fn))
        {
            sn = a[i];
        }
    }
    cout<<sn<<endl;
    for(i=1;i<5; i++)
    {
        if((a[i]>ln) && (a[i]!=fn) && (a[i]!=sn))
        {
            ln= a[i];
        }
    }
    cout<<ln<<endl;
}
