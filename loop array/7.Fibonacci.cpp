#include<iostream>
using namespace std;
int main(){
  int a=0,b=0,c=1,i,n;
  cout<< "your input is : ";
  cin>>n;
  cout<< "Fibonacci Series : ";
  for(i=0;i<n; i++)
  {
      cout<<c<< " ";
      a=b;
      b=c;
      c=a+b;
  }


    return 0;
}
