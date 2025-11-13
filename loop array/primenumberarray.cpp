#include<iostream>
using namespace std;
int main()
{
int i, n, j;
 cout<< " How many numbers you want to take : ";
 cin>>n;
 int a[n];
 cout<< "Enter "<<n<< " Numbers : ";
 for(i=0; i<n; i++)
 {
     cin>>a[i];
 }

 for(i=0; i<n; i++)
 {
     bool isprime = true;
     for(j=2; j<=a[i]/2; j++)
     {
         if(a[i]%j==0)
         {
           isprime = false;
           break;
         }
     }
     if(isprime==true && a[i]>=2)
     {
         cout<< a[i]<<" is prime"<<endl;
     }
     else cout<< a[i]<< " is not prime"<<endl;
 }
 return 0;
}

