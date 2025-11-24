#include<iostream>
using namespace std;
int main(){
    int n;
    cout<< "Enter elements : "; //16, 56,30
    cin>>n;
    int arry[n];
    for(int i =0; i<n; i++){
        cin>>arry[i];
    }
  for(int i = 0 ; i< n-1; i++){
    int minIndex = i;
    for(int j = i+1; j<n; j++){
        if(arry[j]<arry[i]){
            minIndex = j;
        }
    }
    if(minIndex !=i){
        int temp = arry[i];
        arry[i]= arry[minIndex];
        arry[minIndex] = temp;
    }
  }
     for(int i =0; i<n; i++){
        cout<<arry[i]<< " ";
     }
}