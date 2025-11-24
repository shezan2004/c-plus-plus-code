#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int *arr, int s , int e , int k){

    if(s>e)
    return false;
    int mid = s + (e-s)/2;
    if(arr[mid] == k){
        return true;
    }
    if(arr[mid]<k){
        return binarySearch(arr, mid+1, e, k);
    }
    else{
       return binarySearch(arr, s, mid-1, k); 
    }
}


int main(){
 int arr[6]= { 1,2,3,4,5,6};
 int size =6;
 int k = 7;
  int ans = binarySearch(arr, 0,6, k);
  if(ans){
    cout<< "Present"<<endl;
  }
  else{
    cout<< " Not present"<<endl;
  }


    

    return 0;
}