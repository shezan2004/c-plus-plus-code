#include<iostream>
using namespace std;
void evenNumber(int a, int b){
    cout<<"Even Number : ";
   for(int i=a; i<=b; i++){
    if(i%2==0){
        cout<<i<<" ";
    }
   }
}
void oddNumber(int a, int b){
    cout<< " Odd Number : ";
   for(int i=a; i<=b; i++){
    if(i%2!=0){
        cout<<i<<" ";
    }
   }
}
int main(){
int s,e;
cout<< "Enter Starting Number : ";
cin>>s;
cout<<endl<<" Enter Ending Number : ";
cin>>e;
evenNumber(s,e);
oddNumber(s,e);
    return 0;
}