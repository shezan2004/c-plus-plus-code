#include<iostream>
using namespace std;
int main()
{
    int i, n;
    cout<< " Enter A Number : ";
    cin>>n;
    int array[10]={0,0,0,0,0,0,0,0,0,0};
    while(n>0)
    {
      int rem = n%10;
       array[rem] +=1;
        n/=10;
    }
    for(i=0; i<=9; i++)
    {
        cout<<"The frequency of " <<i << " = "<<array[i]<<endl;
    }

}
