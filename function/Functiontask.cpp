#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//1. create a function to make a string uppercase
string upper(string y) {
    for (int i = 0; i < y.length(); i++) {
        if (y[i] >= 'a' && y[i] <= 'z') {
            y[i] = y[i] - 32;  // Subtract 32 to convert to uppercase
        }
    }
    return y;
}

//2. create a function to make a string lowercase
string lower(string s){

 for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='A'&& s[i]<= 'Z')
        {
            s[i]=s[i]+32;
        }
    }
return s;
}


//3. create a function that find and returns max of two value
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

//4. create a function that returns an absolute value of the given integer
int absoluteValue(int num) {
    return abs(num);
}


//5. create a function that converts an array of integer to it's absolute value using your function
void arrayToAbsolute(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = abs(arr[i]);
    }
}


//6. create a function to reverse an integer array
void reverseArray(int iarray[], int a) {
    for (int i = 0; i < a / 2; ++i) {
        swap(iarray[i], iarray[a - i - 1]);
    }
}
//7. create a function that swaps two value
void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//8. create a function that returns the Force value when mass and acceleration. (F = ma)
double calculateForce(double mass, double acceleration) {
    return mass * acceleration;
}

//9. create a function that returns the Gravitational Force
		//when Mass 1, Mass 2 and distance d is given, (F = G*m1*m2/d^2)
		const double G = 6.67430e-11;

double calculateGravitationalForce(double mass1, double mass2, double distance) {

    if (distance == 0) {
        cout << "Error: Distance cannot be zero for gravitational force calculation." <<endl;

    }

    return (G * mass1 * mass2) / pow(distance, 2);
}

//10. create a function that calculates multiplication of two 3X3 matrix/2D .
void multiplyMatrices(const double matrix1[3][3], const double matrix2[3][3], double result[3][3]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = 0.0;
        }
    }


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void displayMatrix(const double matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



int main(){
    string stri = "Hello world";

    cout << upper(stri)


    cout<<endl;
     string str = "Hello World";

    cout<< lower(str)<<endl;

    int num1 = 10;
    int num2 = 20;

    cout << "The maximum of " << num1 << " and " << num2 << " is: " << findMax(num1, num2) <<endl;


    double double1 = 3.14;
    double double2 = 2.71;

   cout << "The maximum of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) <<endl;
   cout<<endl;

    int num = -9;
    int absValue = absoluteValue(num);

   cout << "The absolute value of " << num << " is: " << absValue << endl;

   int size = 5;
    int myArray[size] = {-2, 5, -8, 10, -4};

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
       cout << myArray[i] << " ";
    }

    arrayToAbsolute(myArray, size);

    cout << "\nArray after conversion to absolute values: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
 cout <<endl;
 int a = 5;
    int iarray[a] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < a; ++i) {
        cout << iarray[i] << " ";
    }

    reverseArray(iarray, a);

    cout << "\nArray after reversal: ";
    for (int i = 0; i < a; ++i) {
        cout << iarray[i] << " ";
    }

    cout << endl;
    int value1 = 5;
    int value2 = 10;

   cout << "Before swapping: value1 = " << value1 << ", value2 = " << value2 << endl;

    swapValues(value1, value2);

    cout << "After swapping: value1 = " << value1 << ", value2 = " << value2 << endl;

   cout<<endl;
   double mass = 5.0;
    double acceleration = 9.8;

    double force = calculateForce(mass, acceleration);

    cout << "The force is: " << force << " Newtons" << endl;

    cout<<endl;
    double mass1 = 5.0;
    double mass2 = 10.0;
    double distance = 2.0;

    double gravitationalForce = calculateGravitationalForce(mass1, mass2, distance);

   cout << "The gravitational force is: " << gravitationalForce << " Newtons" << endl;
 cout<<endl;
  double matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Matrix 1:" << endl;
    displayMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    displayMatrix(matrix2);


    double resultMatrix[3][3];
    multiplyMatrices(matrix1, matrix2, resultMatrix);

    cout << "Resultant Matrix:" << endl;
    displayMatrix(resultMatrix);






return 0;
}


