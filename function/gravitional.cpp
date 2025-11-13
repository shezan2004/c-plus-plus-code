#include <iostream>
#include <cmath>
using namespace std;

const double G = 6.67430e-11;

double calculateGravitationalForce(double mass1, double mass2, double distance) {

    if (distance == 0) {
        cout << "Error: Distance cannot be zero for gravitational force calculation." <<endl;

    }

    return (G * mass1 * mass2) / pow(distance, 2);
}

int main() {
    double mass1 = 5.0;
    double mass2 = 10.0;
    double distance = 2.0;

    double gravitationalForce = calculateGravitationalForce(mass1, mass2, distance);

   cout << "The gravitational force is: " << gravitationalForce << " Newtons" << endl;

    return 0;
}

