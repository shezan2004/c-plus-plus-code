 #include<iostream>
 #include<list>
 using namespace std;
 class Employee{
 private :
 int A,B,C;
 public:
 int d,e;
 void setData(int a, int b, int c){
 A=a;
 B=b;
 C=c;}
 void getdata(){
    cout<<"Value Of a : "<<A<<endl;
    cout<<"Value of b : "<<B<<endl;
    cout<<"Value of c : "<<C<<endl;
 }
 };
 
 int main(){
Employee m;
m.setData(3,5,7);
m.d=10;
m.e = 89;
m.getdata(); 

    return 0;
 }