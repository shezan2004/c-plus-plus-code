#include<iostream>
using namespace std;
int main ()
{
    int n,r,c;
    cout<< " Enter N :";
    cin>>n;
    for (r=n; r>=n;r++)
    {
        for(c=1; c<=n-r; c++)
        {
            cout<< " ";
        }
        for(c=1; c<=r; c++)
        {
            cout<< "*";
        }
        cout<< endl;
    }
    return 0;
}
