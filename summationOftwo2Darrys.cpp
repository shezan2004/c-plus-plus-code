#include<iostream>
using namespace std;
int main(){
int a[3][3]= {{12,5,8}, {6,7,4},{18,9,2}};
int b[3][3]= {{2,8,18}, {16,14,5},{8,19,12}};
int c [3][3];
for(int i =0; i<3; i++){
    for(int  j=0; j<3; j++){
        c[i][j]=a[i][j]+b[i][j];
    }
}
for(int i =0; i<3; i++){
    for(int j=0; j<3; j++){
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}

    return 0;
}