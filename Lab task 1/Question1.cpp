#include<bits/stdc++.h>
using namespace std;

double triangleBaseAndHieght(double base, double height){
    return (base * height)/2;
}
double triangelethreeSides( double a, double b, double c){
     double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(){

double base , height;
double a, b,c;
    
    cout<< " Enter base and Height : ";
    cin>> base>> height;
    cout<< " Area of triangle ( base & height ) : " <<triangleBaseAndHieght<<endl;

    cout << "Enter three sides of the triangle: ";
    cin >> a >> b >> c;
    cout << "Area of triangle (three sides):"<<triangelethreeSides<< endl;
    
    return 0;
}