#include<iostream>
using namespace std;
int main(){
    int a[5][4];
    for(int i =0; i<5; i++){
        for(int j= 0; j<4; j++){
            cin>>a[i][j];
        }
    }
    int ans[4][5];

    for(int i = 0; i<5; i++){
        for(int j =0; j<4;j++){
        
        ans[j][i] = a[i][j];
         
        }
    }
    for(int i =0; i<4; i++){
        for(int j =0; j<5; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}