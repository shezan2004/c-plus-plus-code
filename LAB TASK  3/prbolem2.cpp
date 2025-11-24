#include<iostream>
#include<string>
using namespace std;
string encode( string s , int j){
    string encoded = s;

for(int i =j; i<encoded.length(); i= i+j+1){
    encoded [i] = encoded[i] + 2;
}
return encoded;
}


int main(){
    string s;
    cout<<"ENTER A SENTENCE : "<<endl;
    getline(cin,s);
    int j;
    cout<< " Enter a integer : "<<endl;
    cin>>j;
    string encodedString = encode(s,j);
    cout<<" Orginal : "<<s<<endl;
    cout<< "ENCODED : "<<encodedString<<endl;
    return 0;

}
