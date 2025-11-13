#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "Enter any number : ";
    cin>>n;
    if(n>=0)
    {
        cout<< n<<" Positive number."<<endl;
        if(n%2==0)
        {
            cout<<n<< " is even number."<<endl;
        }
        else{
            cout<<n<< " is odd number."<<endl;
        }
    }

    else
    {
        cout<<n<< "Negative number."<<endl;
    }
    return 0; }
