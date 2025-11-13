#include<iostream>
using namespace std;
int main ()
{
    int i,n;
    cout<< " How many character you Want to take : " ;
    cin>>n;
    char a[n];
    for( i= 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
      if( a[i]=='a' ||  a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]== 'A' || a[i]== 'E' || a[i]== 'I' || a[i]== 'O' || a[i]== 'U' )
      {
          cout<< a[i] << " Is Vowel "<<endl;
      }
    }



}
