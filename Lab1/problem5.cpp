#include <iostream>
using namespace std;
void factorial (int a){
     int flag =0;
     int  fact =1;
     if(a<2 && a>0){
        cout<< "Error , Not a prime Number";
    }
    if(a>2){
        for(int i=3; i<a/2; i++){
             if(a%i==0){
                flag =1;
                break;
               ;
           } 
        }
        
    }
    if(flag==0){
            cout<< a << " Prime Number"<<endl;
           for(int i=1; i<=a; i++){
        fact*= i;
             }
          cout<<a<< " Factorial is : "<< fact<<endl;
          }
          else{
            cout<< " Error, not a prime number ";
          }
}  
     
    
int main(){
    int a ;
    cout<< " Enter Integer Number : ";
    cin>>a;
    factorial (a);


    return 0;
}