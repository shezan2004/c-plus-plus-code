#include<iostream>
using namespace std;
int main(){
 int arry[10];
 cout<< " Enter 10 integer here : ";
 for(int i = 0; i<10; i++){
      cin>>arry[i];
    } 
    int oddCount = 0;
    int evenCount= 0;
    for(int i =0; i<10; i++){
        if(arry[i]%2==0){
          evenCount++;
        }
        else{
            oddCount++;
        }
    }
    cout<< " Odd Numbers are : "<<evenCount<<endl;
    cout<< "Even Numbers are : "<<oddCount<<endl;
    return 0;
}