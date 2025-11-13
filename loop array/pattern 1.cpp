#include<iostream>
using namespace std;
 int main ()
 {
     int n,i,j;
     cout<< "Enter N : ";
     cin>>n;
     for(i=1; i<=n; i++)
     {
        for(j=1;j<=n-i; i++)
        {
            cout<< " ";
        }
        for(j=1; j<=i; i++)
        {
            cout<<j;
        }cout<< endl;
     }
     for(i=n-1; i>0; i--)
     {
        for(j=1;j<=n-i; i++)
        {
            cout<< " ";
        }
        for(j=1; j<=i; i++)
        {
            cout<< j;
        }cout<< endl;
     }

     return 0;
 }
