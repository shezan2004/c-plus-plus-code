#include<iostream>
using namespace std;
int main(){
    
    int i, n=5,k, nimo[10]={2,3,5,6,7};
    nimo[n++] =8; //2 3 5 6 7 8
    for(i =n; i>0; i--){
        nimo[i]= nimo[i-1];
    }
    nimo[0]=1; n++;//n=7
    //1 2 3 5 6 7 8
    // for(i =0; i<10; i++){
    //     cout<<nimo[i]<< " ";
    // }
    k=3; 
    for(i =n; i>k; i--){
        nimo[i]= nimo[i-1];
    }
    nimo[k]=4; n++; //n=8
    for(i=0; i<n; i++){
        cout<<nimo[i]<< " ";
    }
    return 0;
}