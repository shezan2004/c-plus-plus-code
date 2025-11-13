#include<iostream>
using namespace std;

void sum(int x, int y)
{
    cout << x + y;
}

int main()
{
    int p = 32;
    sum(10, p); // Corrected the syntax to call the sum function
    return 0;
}
