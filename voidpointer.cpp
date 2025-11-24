#include<iostream>
using namespace std;
 void printN( int* nptr){
    cout<<*nptr<<endl;
 }
 void printC( char* cptr){
    cout<<*cptr<<endl;
 }
 void print(void* ptr, char type){
    switch(type){
        case 'i' : cout<<*((int*)ptr)<<endl;
        case 'c' : cout<<*((char*)ptr)<<endl;
    }
 }

   int main(){
    int number = 5;
    int num =4;
    char letter = 'a';
    char l = 'b';
    printN(&number);
    printC(&letter);
    print(&num, 'i');
    print(&l, 'c');
    
    return 0;
   }
    