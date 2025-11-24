#include<iostream>
using namespace std;
struct employee
{
    int eId;
    char favChar;
    float salary;
};
// typedef struct employee
// {
//     int eId;
//     char favChar;
//     float salary;
// }ep;
 union money
{
    int rice;
    char car;
    float pounds;
};

int main(){
    union money  m1;
    m1.rice =67;
    cout<<m1.rice<<endl;

struct employee harry ;
struct employee shezan;

harry.eId = 4;
harry.favChar = 'c';
harry.salary =34.78;
   cout<<harry.eId<<endl;
   cout<<harry.favChar<<endl;
   cout<<harry.salary<<endl;
   shezan.eId = 9;
   shezan.favChar = 'o';
   shezan.salary =4.78;
   cout<<shezan.eId<<endl;
   cout<<shezan.favChar<<endl;
   cout<<shezan.salary<<endl;
    return 0;
}