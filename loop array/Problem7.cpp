#include<iostream>
using namespace std;

int main(){
int n;
cout<<"Input the value of N: ";
cin>>n;


int a[n];

for(int i=0; i<n; i++){
    cin>>a[i];
}


for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
}

cout<<endl;

for(int i=0; i<n; i++){

   bool isPrime = true;

   for(int l=2; l<=a[i]/2; l++){

    if(a[i]%l==0){

        isPrime = false;
        break;
    }
   }

    if(isPrime==true && a[i]>=2){
        cout<<a[i]<<" is a prime number."<<endl;
    }
    else{
        cout<<a[i]<<" is a non-prime number."<<endl;
    }

}



    return 0;
}
