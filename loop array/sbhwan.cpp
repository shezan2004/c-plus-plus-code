//Write a C++ program to find the smallest and second smallest elements in each array of integers.

#include<iostream>
using namespace std;

int main(){

int size;
cout<<"Enter the element num: ";
cin>>size;

int array[size];

for(int i=0; i<size; i++){
    cin>>array[i];
}


int smallest = array[0];
int second_smallest = INT16_MAX;


//Find the smallest.
for(int i=1; i<size; i++){

    if(array[i]<smallest){

    smallest=array[i];
    }
}

//Find the second smallest element
for(int i=0; i<size; i++){

    if(array[i]<second_smallest && array[i]!=smallest){
        second_smallest = array[i];
    }
}


cout<<"Smallest: "<<smallest<<endl;
cout<<"Second smallest: "<<second_smallest;


    return 0;
}
