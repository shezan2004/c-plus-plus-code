#include<iostream>
using namespace std;
 int main(){
int n;
cout<<" Enter the number of Elements : ";
cin>>n;
int arry[n];
cout<<"Enter Element: ";
for(int i =0; i<n; i++){
    cin>>arry[i];
}
for(int i=n-1; i>=0; i--){
    cout<<arry[i]<< " ";
}
int max =arry[0];
for(int i =0; i<n; i++){
    if(arry[0]<arry[i]){
     max=arry[i];
    }
}
    cout<< endl<<"MAXIMUM NUMBER : "<<max<<endl;
    int min =arry[0];
for(int i =0; i<n; i++){
    if(arry[0]>arry[i]){
     max=arry[i];
    }
}
    cout<< "MINIMUM NUMBER : "<<min<<endl;
int avg =0;
for(int i =0; i<n; i++){
    avg += arry[i];
}
float sum =avg/n;
cout<<"Avarage : "<<sum;


    return 0;

}