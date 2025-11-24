 #include<iostream>
 using namespace std;
 
 int main(){
    int luckyNumber[5];
    // cout<<luckyNumber<<endl; 
    // cout<<&luckyNumber[0]<<endl;
    // cout<< luckyNumber[2]<<endl;
    // cout<<*(luckyNumber + 2)<<endl;
    for(int i=0 ; i<5; i++){
        cout<<" Number : ";
        cin>>luckyNumber[i];
    }
    // for(int i =0; i<5; i++){
    //    cout<< luckyNumber[i]<<" "; 
    // }
    for(int i =0; i<5; i++){
       cout<< *(luckyNumber+i)<<" "; 
   
     }
     cout<<endl;
     int* ptr = luckyNumber;
     for(int i =0; i<5; i++){
      cout<<*ptr<<" ";
      *ptr++;
     }

    return 0;
 }