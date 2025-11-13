#include<iostream>
using namespace std;
void getMinandMax(int num[], int size, int *min, int *max)
{
    for(int i=1; i<size; i++)
    {
        if(num[i]<*min)
        {
            *min = num[i];
        }
        if(num[i]>*max)
        {
            *max = num[i];
        }
    }
}

int main ()

{
    int num[5] = {1 , 3, 4,7, 8};
    int min = num[0];
    int max = num[0];
    getMinandMax(num,5, &min, &max);
    cout<< "Min : "<<min<<endl;
    cout<< "Max : "<<max<<endl;


return 0;
}
