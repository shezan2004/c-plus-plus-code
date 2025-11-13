#include<iostream>
using namespace std;
int main ()
{
    int a=0, b=0,c=1,n,i;
    cout<< " Enter any number : ";
    cin>>n;
    for(i=0; i<n; i++)
    {

        a=b;
        b=c;
        c= a+b;
        cout<<c<< " ";
    }
    return 0;
}
