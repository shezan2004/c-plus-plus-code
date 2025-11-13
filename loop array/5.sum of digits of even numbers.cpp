#include<iostream>
using namespace std;
int main()
{
    int num1,num2,sum=0,temp,i;
    cout<< "First number :";
    cin>>num1;
    cout<< "Second number :";
    cin>>num2;
    if(num1>num2)
    {
        temp=num1;
        num1=num2;
        num2=temp;

    }
    for(i=num1+1; i<num2; i++)
    { if(i%2==0)
    {
        sum=sum+i;
    }
    }


    cout<< "The sum of even numbers between "<<num1<<" and "<<num2<<" is :"<<sum;
    return 0;
}

