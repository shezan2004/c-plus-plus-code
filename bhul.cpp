#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< " Enter Size Of Arry : ";
    cin>>n;
    int a[n];
    for(int i=0 ; i<n; i++){
        cin>>a[i];
    }
     int b = a[0];
    for(int i =0; i<n; i++){
        if(a[i]>b){
        b=a[i];    
        }   
    }
    cout<< b<< " ";
    return 0;
}
