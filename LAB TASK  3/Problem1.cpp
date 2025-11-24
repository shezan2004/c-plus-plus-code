#include<iostream>
using namespace std;
int main(){
    int a[3][4] ={ {1, 6 ,7,9} , {2, 4, 8,5}, {3,1,9,4}};
    int temp[4][3];
    for(int i = 0; i<3; i++){
        for(int j =0; j<4;j++){
         temp[j][i]= a[i][j];
        }
    }
    for(int i =0; i<4; i++){
        for(int j =0; j<3; j++)
        {
            cout<<temp[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}