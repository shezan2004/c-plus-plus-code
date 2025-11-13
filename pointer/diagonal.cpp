#include<iostream>
using namespace std;
void matrix( int customMatrix [5][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++ )
        {
            cin>>customMatrix[i][j];
        }
    }
    void diagonnalSum(int customMatrix [5][5])
     {
        int sum =0;
        for(int i=0; i<5; i++)
        {
            sum += customMatrix[i][i];
            sum += customMatrix[i][4-i];
        }
        sum -= customMatrix[5/2][5/2];
        return sum;
    }
    void borderSum(int customMatrix[5][5])
    {
        int sum =0;
        for(int i=0; i<5; i++)
        {
            sum += customMatrix[i][0];
            sum += customMatrix[i][4];

        }
        if(i!=2)
        {
            sum +=customMatrix[0][i];
            sum +=customMatrix[4][i];
        }
    }
    int main ()
    {
        int customMatrix[5][5];
        matrix(customMatrix);
        cout<<diagonalMatrix(customMatrix)<<endl;
        cout<<borderMatrix(customMatrix)<<endl;
    }
