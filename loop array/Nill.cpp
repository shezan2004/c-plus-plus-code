#include <iostream>
using namespace std;

int main()
{
    int rows,columns;
    int arr1[rows][columns];
    int arr2[rows][columns];

    cout << "Enter the values of rows and columns = ";
    cin >> rows >> columns;

    cout << "Enter the elements of array 1 = ";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the elements of array 2 = ";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin >> arr2[i][j];
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }




}
