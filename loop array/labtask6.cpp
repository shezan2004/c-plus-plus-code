#include<iostream>
using namespace std;
int main(){
int i,num,fact=1;
cout<<"Enter a number: ";
cin>>num;
for(i=1;i<=num;i++){
    fact=fact*i;
}
cout<<"Factorial of "<<num<<" num is : "<<fact;
return 0;
}
