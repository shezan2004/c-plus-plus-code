#include<iostream>
using namespace std;
int main(){
    //summation
   int arry[10] ={10,15,45,20,25,6,1,100,65,99};
   int sum =0;
   for(int i = 0; i<10; i++){
    sum+= arry[i];
   }
   cout<< "Sum of arry : "<<sum<<endl;
   //sumation of even number
   int sumOdd = 0;
   for(int i =0; i<10; i++){
    if(arry[i]%2==0){
        sumOdd+= arry[i];
    }
   }
  cout<<"Summation of odd numbers : "<<sumOdd<<endl;
  //sumation of even index
  int sumI=0;
  for(int i =0; i<10; i++)
  {
    if(i%2==0){
        sumI += arry[i];
    }
  } 
  cout<<"Summation of Even Index : "<<sumI<<endl;
    return 0;
}