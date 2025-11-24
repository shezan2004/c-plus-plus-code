#include<iostream>
using namespace std;
int main(){
     int arry[10] ={10,15,45,20,45,6,1,100,45,99 };
     int  count =0;
     int a;
     cout<<" Enter which number you want to search : ";
     cin>>a;
    for(int i =0; i<10; i++){
        if(a==arry[i]){
            count++;
        }
 
    }
    cout<<a<<" is here "<<count<<" times";

     return 0;
}