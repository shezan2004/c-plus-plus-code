
#include<iostream>
using namespace std;
int main ()
{
   int r=0, c=0,n;
   cout<<" Enter a number : " ;
   cin>>n;
   for(r=1; r<=n; r++)
   {
       for(c=1; c<=r; c++)
       {
           cout<<" ";
       }
        for(c=1; c<=r; c++)
       {
           cout<<c;
       }
       cout<<endl;
   }
return 0;
}
