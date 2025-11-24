#include <iostream>
using namespace std;

int main() {
    int n = 20;
    int house1 = 0, house2 = 1;

    cout << "First " << n << " house numbers are: ";
    cout << house1 << " " << house2 << " ";
    
    for (int i = 3; i <= n; i++) {
        int nextHouse = house1 + house2;
        cout << nextHouse << " ";
        house1 = house2;
        house2 = nextHouse;
    }

    cout << endl;
    return 0;
}
