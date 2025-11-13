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
 void pacalsTRiangle(int rows )
 {
     for( int i=0; i<=rows; i++)
     {
         for(int j=0; j<=i; j++ )
         {
             cout << nCr(i , j)<< " ";
         }
         cout<<end;
     }
int main()
{
pacalsTRiangle(10);

    return 0;
}

