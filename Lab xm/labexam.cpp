#include<iostream>
using namespace std;
int main(){

    int size;
    cout<<" Enter the number of element  :";
    cin>>size;
    int arry[size];
    for(int i =0; i<size; i++){
        cin>>arry[i];
    }
    for(int i=1; i< size; i++){
        int j= i -1;
        int current = arry[i];
        while(j>=0 && arry[j]>current){
            arry[j+1] =arry[j];
            j--;
        }
        arry[j+1]= current;
        
    }
    for(int i =0; i<size; i++){
        cout<<arry[i]<< " ";
    }

}