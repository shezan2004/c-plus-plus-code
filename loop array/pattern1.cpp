#include<iostream>
using namespace std;
int main ()
{
    int r,c;
    for(r=1; r<=5; r++)
    {
        for(c=1; c<=5-r; c++)
        {
            cout<< " ";
        }
        for(c=1; c<=2*r-1; c++)
        {
            cout<<c;
        }
        cout<<endl;
    }
     for(r=5-1; r>0; r--)
    {
        for(c=1; c<=5-r; c++)
        {
            cout<< " ";
        }
        for(c=1; c<=2*r-1; c++)
        {
            cout<<c;
        }
        cout<<endl;
    }

}


