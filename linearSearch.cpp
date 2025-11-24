#include<iostream>
using namespace std;
int linearSearch(int arry[], int n, int key){
for(int i =0; i<n; i++){
    if(key==arry[i]){
        return i;
    }
    else return -1;
}
}
int main(){
int n;
cout<< "Enter the size of Arry : ";
cin>>n;
int arry[n];
for(int i = 0; i<n; i++){
   cin>>arry[i];
}
int key;
cout<<" Search Element : ";
cin>>key;
cout<<linearSearch(arry,n,key);
}