#include<iostream>
using namespace std;
int main ()
{
    int i, n;
    cout<< " Enter  the number of elements : ";
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int ln= a[0];
    int sl = INT16_MIN;
    for(i=1; i<n; i++)
    {
        if(a[i] >ln )
        {
            ln = a[i];
        }
    }
    for(i=1; i<n; i++)
    {
        if(( a[i]>sl) && a[i] !=ln )
        {
            sl = a[i];
        }
    }
    cout<< " Largest Number is : "<<ln<<endl;
    cout<< "Second largest number is : "<<sl<<endl;
}
