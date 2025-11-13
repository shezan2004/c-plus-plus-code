
#include<iostream>
using namespace std;
int main ()
{
    int n, i;
    cout<< "Enter Number of elements : ";
    cin>>n;
    int a[n];
    cout<< "Enter " << n << " Numbers : ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        if(a[i]%2==0)
        {
            cout<< a[i]<< " Odd number. "<<endl;
        }
        else
        {
            cout<< a[i]<< " Even number. "<<endl;
        }

    }
    return 0;
}
