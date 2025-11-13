#include<iostream>
using namespace std;
int main ()
{
    int i, n;
    cout<< " Take Numbers : ";
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        int sum=0;
        for(int j=1; j<=a[i]/2; j++ )
        {
            if(a[i]%j==0)
            {
                sum= sum + j;

            }
        }
        if(a[i]==sum)
        {
            cout<<a[i]<< " is perfect number"<<endl;
        }
        else
        {
           cout<<a[i]<< " is not perfect number"<<endl;
        }
    }
}
