#include<iostream>
using namespace std;

int main() {
    int arry[10] = {1, 7, 2, 7, 5, 3, 3, 5, 2, 2};
    
    int temp[10];
    int tempIndex = 0;

    for (int i = 0; i < 10; i++) {
        int flag = 0;
        for (int j = 0; j < tempIndex; j++) {
            if (arry[i] == temp[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            int count = 0;
            for (int j = i; j < 10; j++) {
                if (arry[j] == arry[i]) {
                    count++;
                }
            }

            temp[tempIndex++] = arry[i];
            cout << arry[i] << " Occurs = " << count << " times" << endl;
        }
    }
    return 0;
}
