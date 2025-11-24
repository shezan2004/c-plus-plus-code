#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<< " enter any letter : " ;
    cin>>ch;
    switch(ch){
       case 'a' : 
       cout<< "vowel";
       break;
       case 'e' :
       cout<<" Vowel" ;
        break;
       case 'i' : 
       cout<< "vowel";
       break;
       case 'o' : 
       cout<< "vowel";
       break;
       case 'u' : 
       cout<< "vowel";
       break;
       default: 
       cout<< " Consonant";
    }
    return 0;
}