#include <iostream>
#include <string>
using namespace std;

void searchTomato(string fridge[], int size) {
    for (int i = 0; i < size; i++) {
        if (fridge[i] == "tomato") {
            cout << "Tomato found at position " << i + 1 << " in the refrigerator." << endl;
            return;
        }
    }
    cout << "Tomato not found in the refrigerator." << endl;
}

int main() {
    string fridge[] = {"mutton", "fish", "tomato", "butter", "sauce", "ginger","sweets","orrange"};
    int size = sizeof(fridge) / sizeof(fridge[0]);

    searchTomato(fridge, size);

    return 0;
}
