#include<iostream>
using namespace std;



int main ()
{
    int luckyNumber[5];
    for(int i=0; i<5; i++)
    {
        cout<< "Number : ";
        cin>>luckyNumber[i];
    }
    for(int i=0; i<5; i++)
    {
        cout<<*(luckyNumber + i)<< " ";
    }






    /*cout<<luckyNumber<<endl;
    cout<<&luckyNumber[0]<<endl;
    cout<<luckyNumber[2]<<endl;
    cout<<*(luckyNumbers +2);<<endl */


     return 0;

}
