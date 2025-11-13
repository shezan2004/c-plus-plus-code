#include<iostream>
using namespace std;
int main()
{
    int num1,num2,rem=0,n1,n2;
    cout<< "Input the first number: ";
    cin>>num1;
    cout<< "Input the second number: ";
    cin>>num2;
    n1=num1;
    n2=num2;
    while(n2!=0)
    {
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    cout<< "The Greatest Common Divisor : "<<n1;
    return 0;
}

