#include <bits/stdc++.h>
using namespace std;

int denomination[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2};
int n = sizeof(denomination) / sizeof(denomination[0]);

void findMin(int V)
{
    sort(denomination, denomination + n);

    vector<int> ans;
    vector<int> count(n, 0);
    int totalCoins = 0; 

    for (int i = n - 1; i >= 0; i--) {
        while (V >= denomination[i]) {
            V -= denomination[i];
            ans.push_back(denomination[i]);
            count[i]++; 
            totalCoins++; 
        }
    }

    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            cout << denomination[i] << " x " << count[i] << endl;
        }
    }

    
    cout << "Total number of coins: " << totalCoins << endl;
}

int main()
{
    int n = 2887;
    cout << "Following is minimal number of change for " << n << " : \n";

    findMin(n);
    return 0;
}
