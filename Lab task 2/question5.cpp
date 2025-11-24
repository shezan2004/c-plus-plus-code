#include <iostream>
using namespace std;

float rectangleArea(float length, float width) {
    return length * width;
}

float squareArea(float side) {
    return side * side;
}

float rhombusArea(float diagonal1, float diagonal2) {
    return (diagonal1 * diagonal2) / 2;
}

float parallelogramArea(float base, float height) {
    return base * height;
}

float trapezoidArea(float base1, float base2, float height) {
    return (base1 + base2) * height / 2;
}

int main() {
    int choice;
    cout << "Choose a shape to calculate the area:\n";
    cout << "1. Rectangle\n";
    cout << "2. Square\n";
    cout << "3. Rhombus\n";
    cout << "4. Parallelogram\n";
    cout << "5. Trapezoid\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    float area = 0;

    switch (choice) {
        case 1: {
            float length, width;
            cout << "Enter the length and width of the rectangle: ";
            cin >> length >> width;
            area = rectangleArea(length, width);
            break;
        }
        case 2: {
            float side;
            cout << "Enter the side of the square: ";
            cin >> side;
            area = squareArea(side);
            break;
        }
        case 3: {
            float diagonal1, diagonal2;
            cout << "Enter the lengths of the diagonals of the rhombus: ";
            cin >> diagonal1 >> diagonal2;
            area = rhombusArea(diagonal1, diagonal2);
            break;
        }
        case 4: {
            float base, height;
            cout << "Enter the base and height of the parallelogram: ";
            cin >> base >> height;
            area = parallelogramArea(base, height);
            break;
        }
        case 5: {
            float base1, base2, height;
            cout << "Enter the lengths of the two bases and the height of the trapezoid: ";
            cin >> base1 >> base2 >> height;
            area = trapezoidArea(base1, base2, height);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    cout << "The area is: " << area << endl;

    return 0;
}
