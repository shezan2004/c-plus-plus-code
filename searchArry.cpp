#include<iostream>
using namespace std;
int main(){
    int n, m;

    cout<<"Enter Row and Coloum : ";
    cin>>n>>m;
    int arry[n][m];
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arry[i][j];
        }
    }
    int num;
    cout<<"Enter Any Number : ";
    cin>>num;
    bool flag = false;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
        if(num==arry[i][j]){
            cout<<i<<j<<endl;
            flag = true;
        }
    }
    
}
if(flag){
        cout<<"Element is found"<<endl;
    }
    else{
        cout<<"Element is not found";
    }

}