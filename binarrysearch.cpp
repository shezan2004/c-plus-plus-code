#include<iostream>
using namespace std;
int main(){
     int arr[10] = { 10,20,30,40,50,60,70,80,90,100};
     int num;
     cout<<" Enter the number you want to search : ";
     cin>>num;
     int start = 0, end = 9, position =-1;
     while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid]==num){
            position = mid;
            break;
        }
        else if(arr[mid]>num){
             end = mid - 1;
        }
        else if( arr[mid]<num){
            start = mid +1;
        }
     }
     if(position==-1){
        cout<< "Number not found";
     }
     else{
        cout<<num<< " is in "<<position<<" Index";
     }
}
