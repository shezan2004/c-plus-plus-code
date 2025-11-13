#include<iostream>
using namespace std;
int main()
{
    int i,n,temp;
    cout<< "Enter a number : ";
    cin>>n;
    char hex[100];
    int length=0;
    temp=n;
    while(temp>0)
    {
        int last_digit= temp %16;
        if(last_digit<=9)
        {
           hex[length++]= last_digit + 48;
        }
         else
        {
            hex[length++]= last_digit + 55;
        }
        temp /=16;
    }
    for(i=length-1; i>=0; i--)
    {
        cout<< hex[i];
    }
}
