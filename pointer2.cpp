#include<iostream>
using namespace std;
int main(){
    int n= 5;
    int *ptr =&n;
    cout<<*ptr<<endl;
    * ptr = 10;
    cout<<*ptr<<endl;
    cout<<n;
 return 0;
}