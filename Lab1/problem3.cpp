#include<iostream>
using namespace std;
void findingOdd(int start, int end)
{
    for(int i = start ; i <= end ; i++)
    {
        if( i % 2 !=0)
        {
            cout<< i<< " ";
        }
    }
}
int main()
{
    int start, end;
    cout<< " Enter starting number : ";
    cin>> start;
    cout<<" enter ending number : ";
    cin>>end;
    findingOdd(start,end);

    return 0;
}

