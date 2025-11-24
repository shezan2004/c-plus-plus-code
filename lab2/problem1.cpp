#include <iostream>
using namespace std;

int main() {
    int size1,size2;
    cout<< "Enter 1st array size : ";
    cin>>size1;
    int arry1[size1];
    for(int i= 0; i<size1; i++){
        cin>>arry1[i];
    }
    cout<< "Enter 2st array size : ";
    cin>>size2;
    int arry2[size2];
    for(int i= 0; i<size2; i++){
        cin>>arry2[i];
    }
    int newArry[size1+ size2];
     int count =0;
     for( int  i= 0; i<size1; i++){
        newArry[count++]=arry1[i];
    }
     for( int i= 0; i<size1 + size2; i++){
        newArry[count++]= arry2[i];
    }
     for( int i= size1 + size2-1 ; i>=0; i--){
         cout<<newArry[i]<<" ";
    }

}
