
#include<iostream>;
using namespace std;
int main () {
   int col, row,n;
   cout<< "Input Number of rows : ";
   cin>>n;
   for(row=n; row>=1; row--)
   {
       for(col=1; col<=row; col++)
       {
           cout<< "*"<< " ";
       }
       cout<< endl;
   }

return 0;}
