#include<iostream>
using namespace std;
int main(){

int a = 3;
int* b = &a;
cout<<" Adress Of A : "<<&a<<endl;
cout<< " Adress Of A : "<<b<<endl;
cout<< " Value of A : "<<*b<<endl;
int** c = &b;
cout<<" The Adress of b : "<<c<<endl;
cout<<"the value at Adress c : "<<*c<<endl;
cout<<"the value at Adress c : "<<**c<<endl;
    return 0; 
}