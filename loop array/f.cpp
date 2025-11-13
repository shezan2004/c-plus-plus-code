#include<iostream>
using namespace std;
int main ()
{
    int n,i ,sum=1;
    cout<< " Number : ";
    cin>>n;
    for(i=1; i<=10; i++)
    {
       sum = sum *i;
    }
    cout<<n<< " X "<< i<< "="<<sum;

    return 0;
}
