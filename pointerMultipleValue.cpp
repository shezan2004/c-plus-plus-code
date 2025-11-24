#include<iostream>
using namespace std;
// int getMin( int numbers[], int size){
//     int min=numbers[0];
// for(int i = 1;i<size; i++){
//      if(numbers[i]<min){
//         min = numbers[i];
//      }
// }
//      return min;
// }
// int getMax(int numbers[], int size){
//  int max = numbers[0];
//  for(int i =1; i<size; i++){
//     if(numbers[i]>max){
//         max = numbers[i];
//     }
//  }
//  return max;
// }
void getMinMax(int number[], int size, int* min, int* max){
    for(int i = 0; i<size; i++ ){
        if(*min>number[i] ){
         *min = number[i];
        }
        if(*max<number[i]){
            *max = number[i];
        }
    }
    
}
int main(){
    int numbers[5] = { 5, 4, -2, 29, 6};
    int min = numbers[0];
    int max = numbers[0];
   getMinMax(numbers, 5, &min, &max);
   cout<< " Max : "<<max<<endl;
   cout<<" Min : "<<min<<endl;
    // cout<<" min : "<<getMin(numbers,5)<<endl; // cout<< " Max : "<<getMax(numbers,5);
    return 0;
}