#include<iostream>
using namespace std;
int main()
{
    int num,sum=0,temp,r;
    cout<< "Input a number :";
    cin>>num;
    temp=num;
    while(temp!=0)
    {
        r=temp%10;
        sum=sum + r;
        temp = temp/10;
    }
    cout<< "The sum of digits of "<<num<<" is: "<<sum;
    return 0;
}
