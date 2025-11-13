#include<iostream>
using namespace std;
int main()
{
    int num,ans=0,power=1;
    cout<< " Enter a decimal number :";
    cin>>num;
    while(num>0)
    {
        int lg=num%2;
        ans=ans+(lg*power);
        power= power*10;
        num=num/2;
    }
    cout<< "Binary is : "<<ans;
    return 0;
}
