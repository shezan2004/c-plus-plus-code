#include<iostream>
using namespace std;
int  main()
{
    int r,n,c;
    cout<< " Enter a number : ";
    cin>>n;
    for(r=1; r<=n; r++)
    {
        for(c=1; c<=n-r; c++)
        {
            cout<< " ";
        }
        for(c=1; c<=2*r-1; c++)
        {
            cout<< "*";
        }
        cout<<endl;
    } for(r=n-1; r>=1; r--)
    {
        for(c=1; c<=n-r; c++)
        {
            cout<< " ";
        }
        for(c=1; c<=2*r-1; c++)
        {
            cout<< "*";
        }cout<<endl;
}
return 0; }
