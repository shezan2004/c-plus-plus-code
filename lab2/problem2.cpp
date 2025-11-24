#include<iostream>
using namespace std;

int main(){
    int size1, size2;
    cout<<"Enter first array size: "<<endl;
    cin>>size1;
    int arr1[size1];
    cout<<"Enter "<<size1<<" integer numbers for first array: "<<endl;
    for(int i = 0; i<size1 ; i++){
        cin>>arr1[i];
    }

    cout<<"Enter second array size: "<<endl;
    cin>>size2;
    cout<<"Enter "<<size2<<" integer numbers for second array: "<<endl;
    int arr2[size2];
    
    for(int i = 0; i<size2 ; i++){
        cin>>arr2[i];
    }

    int newArraySize; 
    if(size1<size2){ 
        newArraySize = size1;
    }else{
        newArraySize = size2;
    }

    int newArray[newArraySize];
    int commonEleCount = 0;
    int newArrayIndex = 0;
    for(int i=0 ; i<size1 ; i++){
        for(int j = 0; j<size2 ; j++){
            if(arr1[i] == arr2[j]){ //traversing both arrays with nested for loops and comparing their numbers
                int flag = 0;
                for(int k = 0; k < newArraySize; k++){
                    if(arr1[i] == newArray[k]){
                        flag = 1;
                    }
                }

                if(flag==0){
                    newArray[newArrayIndex++] = arr1[i];
                    commonEleCount++;
                }
            }
        }
    } 

    if(commonEleCount == 0){ //we started count's value as 0, and incremented each time when we found common element to put into the new array.
        cout<<"No common element!"; //so count == 0 means we did not find any common element to put into the new array
    }else{
        cout<<"Common elements between two arrays are: "<<endl;
        for(int i = 0; i<commonEleCount; i++){
            cout<<newArray[i]<<" ";
        }
    }
}

