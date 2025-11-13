#include<iostream>
using namespace std;
int main ()
{
    int a, b, c;
    cout<< " Enter 3 numbers : ";
    cin>>a>>b>>c;
    int smallest;
    if(a<b && a<c)
    {
       smallest=a;
    }
   else if(a>b && c>b)
    {
        smallest=b;
    }
    else
    {
       smallest=c;
    }
    if(smallest%2==0)
    {
        cout<< " The Smallest number is : "<<smallest<< " is even"<<endl;
    }
    else
     cout<< " The Smallest number is : "<<smallest<< " is odd"<<endl;
    return 0;
}
