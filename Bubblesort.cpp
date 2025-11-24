#include<iostream>
using namespace std;

void bubble(int arr[] , int n){
  
  for(int i = 0; i < n-1; i++) {
    bool flag = false;

    for(int j = 0; j < n-1-i; j++) {

        if(arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            flag = true;
        }
    }

    if(flag == false) {
        break;
    }
  }


}


int main(){

int size;
    cout<<"Enter the size of Arry : ";
    cin>>size;
    int arry[size];
    for(int i =0 ; i< size ; i++){
        cin>>arry[i];
    }
    bubble(arry , size);
    
     for(int i =0 ; i< size ; i++){
        cout<<arry[i];
    }

}


