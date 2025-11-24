#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<" Enter a Number : ";
cin>>a;

int arry[10]={10,15,45,25,6,1,100,65,99,100};

int c;


for(int i= 0; i<10; i++){
    if(a==arry[i]){
        c = i;
    }
}
cout<<c;
return 0;
}