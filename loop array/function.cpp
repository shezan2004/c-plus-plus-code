#include<iostream>
//returnType functionName(parameters){
//body//definition
//}
 int fact (  int f){
int result=1;
 for(int i=1;i<=f; i++)
 {
     result = result * i;
 }
 return result;
 }
 double nCr(int n, int r)
 {
     double result = fact(n)/ (fact(r)*fact(n-r));
     return result;
 }
 double nPr(int n, int r)
 {
     double result = fact(n)/ fact(n-r);
     return result;
 }


using namespace std;
int main()
{

cout<< nCr(10,3)<<endl;
cout<< nPr(3,2)<<endl;
    return 0;
}
