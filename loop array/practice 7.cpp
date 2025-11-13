#include<iostream>
using namespace std;
int main ()
{
    int n,i;
    cout<< " Enter any number : ";
    cin>>n;
    for(i=1; i<=10; i++)
    {
        cout<<i<< " x "<< n<< " = " <<n*i<<endl;
    }

    return 0;
}
