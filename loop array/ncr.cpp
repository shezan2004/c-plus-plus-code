#include<iostream>
//returnType functionName(parameters){
//body//definition
//}
 double nCr(int n, int r)
 {
     double result = fact(n)/ (fact(r)*fact(n-r));
     //return = fact(n)/ (fact(r)*fact(n-r));
     return result;
 }

using namespace std;
int main()
{

cout<<nCr(3,2)<<endl;
    return 0;
}

