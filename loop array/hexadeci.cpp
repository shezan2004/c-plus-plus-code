#include<iostream>
using namespace std;
int main ()

{
    int i,n;
    cout<< " Take Numbers : ";
    cin>> n;
    char hex[50];
    int temp = n;
    int length= 0;
    while(temp>0)
    {
        int ld = temp%16;
        if(ld<=9)
        {
            hex[length++]= ld+48;

        }
        else{
            hex[length++]= ld +55;
        }
        temp /=16;
        }
        for(i=length-1; i>0;i--)
        {
            cout<<hex[i];
        }

}
