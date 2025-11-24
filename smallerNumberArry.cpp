#include<iostream>
using namespace std;
int main(){
    int arry[10]={10,15,45,25,6,1,100,65,99,100};
    int min = arry[0];
    for(int i=1; i<10;i++){
        if(min>arry[i]){
            min=arry[i];
        }
       
    }
     cout<<min<<endl;
    
    return 0;
}