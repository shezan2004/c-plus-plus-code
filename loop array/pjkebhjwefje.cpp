#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<< " take numbers : ";
    cin>>n;
    int a[n];
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        bool isprime = true;
        for(int j=2; j<=a[i]/2; j++)
        {
            if(a[i]%j==0)
            {
               isprime = false;
               break;
            }
        }
        if((isprime==true) && a[i]>=2)
        {
            cout<<a[i]<< "prime";
        }
        else
        {
            cout<<a[i]<< " Not prime.";
        }
    }
}
