#include <iostream>
using namespace std;

int main ()
{
    int a[100],i,n;
    cout<< "How Many Numbers :";
    cin>>n;
    cout<< "enter numbers :";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int max = a[0];
    for(i=1; i<n; i++)
    {
        if(a[i]<max)
        {
            max=a[i];
        }
    }
    cout<<max;
    return 0;

}
