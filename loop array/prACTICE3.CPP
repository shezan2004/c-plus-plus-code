#include<iostream>
using namespace std;
int main ()
{
    char ch;
    cout<< "Enter input(m,M or F,f) : ";
    cin>>ch;
    if( ch=='M' ||ch=='m' ||ch=='F' ||ch=='f' )
    {
        switch (ch)
        {
        case 'M':
        case 'm':
            cout<< "Male";
            break;
        case 'F ':
        case 'f' :
            cout<< "Female ";
            break;
        }

    }
    else
    {
        cout<< "Undefined; ";
    }
    return 0;
}
