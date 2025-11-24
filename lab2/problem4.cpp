#include<iostream>
using namespace  std;
int main(){
     int A[10]={1, 3, 4, 5, 6, 8, 9, 1,6, 9};
    
    int b;
    cout<< " Input a number to search:  : "<<endl;
    cin>>b;
    int count =0;
    for(int i =0; i<10; i++){
        if(A[i]==b){
            count++;
        }
    }
    cout<< "The number "<<b<< " occurs "<<count<<" times in the array";
    
    return 0;
}