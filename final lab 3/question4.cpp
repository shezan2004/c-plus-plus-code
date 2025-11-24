#include <iostream>
#include <climits>
using namespace std;


int matrixChainMultiplication(int dimensions[], int n) {
    int dp[n][n]; 

    
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    
    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX; 

            
            for (int k = i; k < j; k++) {
          
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                dp[i][j] = min(dp[i][j], cost); 
            }
        }
    }

  
    return dp[1][n - 1];
}

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    int dimensions[n + 1];
    cout << "Enter the dimensions of the matrices (array of size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }

    int result = matrixChainMultiplication(dimensions, n + 1);
    cout << "Minimum number of multiplications is: " << result << endl;

    return 0;
}
