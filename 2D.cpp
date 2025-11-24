#include<iostream>
using namespace std;
int main(){
     int n, m;
     cin>>n>>m;
     int arry[n][m];
     for (int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arry[i][j];
        }
     }
      for(int i= 0; i< n; i++){
        for(int j =0; j<m; j++){
            cout<<arry[i][j];
            cout<< " ";
        }
        cout<<endl;

      }
}