#include<iostream>
using namespace std;

void matrix(int m[5][5])
{
    cout << "Enter the elements:\n";
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cout << "Enter Element at position (" << i + 1 << "," << j + 1 << ") : ";
            cin >> m[i][j];
        }
    }
}

int main()
{
    int mainmatrix[5][5];
    matrix(mainmatrix);

    cout << "Entered Matrix:\n";
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cout << mainmatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

