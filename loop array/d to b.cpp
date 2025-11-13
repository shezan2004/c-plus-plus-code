#include<iostream>
using namespace std;
int main()
{
    int i,num1,num2,n1,n2, rem=0;
    cout<< "Enter any number : ";
    cin>>num1>>num2;
    n1=num1;
    n2= num2;
    while(n2!=0)
    {
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    int lcd=(num1+num2)/n1;
    cout<< " GCD : "<<n1;
    cout<< "lCD : "<<lcd;




}
