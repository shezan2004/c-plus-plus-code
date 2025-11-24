#include<iostream>
using namespace std;
int sum(int a, int b){
    int c = a+b;
    return c;
}

int main(){
    int n1, n2;
    cout<< " enter 1st number : ";
    cin>>n1;
    cout<< " enter 2nd number : ";
    cin>>n2;
    cout<<"Sum : "<<sum(n1,n2);


    return 0;
}