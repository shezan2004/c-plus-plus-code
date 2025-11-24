#include<iostream>
using namespace std;
int main(){
 int arry[10]={12, 32,43, 1,54,53,15,64,3,13};
 cout<< " Normal elements are : ";
 for(int i = 0; i<10; i++){
      cout<< arry[i]<< " ";
 } cout<<endl;

 cout<< " Reverse elements are : ";
     for(int  i =9;i>0; i--){
         cout<<arry[i]<<" ";
     }

    return 0;
}