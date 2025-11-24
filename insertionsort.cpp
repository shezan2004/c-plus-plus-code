#include<iostream>
using  namespace std; 
int main(){
    int n;
    cout<< "Enter the number of arry : "; //16, 56,30
    cin>>n;
    int arry[n]; 
    for(int i = 0; i<n; i++){
        cin>>arry[i];
    }
    for(int i =1; i<n; i++){
        int j = i - 1;
        int current = arry[i];
        while(j>=0 && arry[j]>current){
            arry[j + 1] = arry[j];
            j--;
        }
        arry[j+1]= current;
    }
    for(int i = 0; i<n; i++){
        cout<<arry[i]<< " ";
    }


}