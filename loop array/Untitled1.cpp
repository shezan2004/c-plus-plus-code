#include <iostream>
#include <vector>
using namespace std;



int main() {
   int ar[]= {17,26,6,20,24};
   int *p = &ar[2];
   cout<<*p<<endl;;
   cout<<*(p--)<<endl;;
   cout<<*(p-1)<<endl;
   cout<<*p<<endl;;
   *(++p);
   cout<<++(*p);

    return 0;
}
