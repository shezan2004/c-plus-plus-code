#include<iostream>
using namespace std;
int main ()
{
    int num,sum=0,power=1;
    cout<< "Enter a Decimal number : ";
    cin>>num;
    while(num>0)
    {
        int lastdigit=num%2;
        sum=sum+(lastdigit*power);
        power=power*10;
        num=num/2;
    }
    cout<< "Binary is : "<<sum;
    return 0;
}
