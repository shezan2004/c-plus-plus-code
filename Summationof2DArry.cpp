#include<iostream>
using namespace std;
int main(){
int arry[3][3] ={ {12,5,8}, {6,7,4}, {18,9,2}};
int sum =0;
for(int i =0; i<3; i++){
    for(int j =0; j<3; j++){
        sum+= arry[i][j];
    }
}
cout<<"Summation : "<<sum;
    return 0;
}