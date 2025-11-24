#include<iostream>
using namespace std;
int main(){
   int matrix[3][3], matrix2[3][3], matrix3[3][3];
   cout<< "Enter Matrix : ";
   for(int i =0 ; i<3; i++){
    for(int j =0; j<3; j++){
        cin>>matrix[i][j];
    }
   }
    cout<< "Enter Matrix2 : ";
    for(int i =0 ; i<3; i++){
       for(int j =0; j<3; j++){
        cin>>matrix2[i][j];
    }
   }
   cout<< "Enter Matrix3 : ";
    for(int i =0 ; i<3; i++){
       for(int j =0; j<3; j++){
        cin>>matrix3[i][j];
    }
   }
   cout<<" Summation of 3 matrix : "<<endl;
    for(int i = 0; i<3; i++){
        for(int j =0; j<3; j++){
         cout<< matrix[i][j] + matrix2[i][j] +matrix3[i][j]<< " ";
        }
        cout<<endl;
    }
}