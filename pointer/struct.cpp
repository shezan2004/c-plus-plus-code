#include<iostream>
using namespace std;
struct Complex
{ void show()
    {
        if(real !=0) {cout<<real;}
        if(img >0) {cout<< " + "<< img<< "i";}
        else if(img<0) {cout<<img<<"i";}
       cout<<endl;
    }

    double real=0;
    double img=0;
    Complex add(Complex c)
    {
       Complex result;
       result.real = real + c.real;
       result.img = img + c.img;
       return result;

    }
     Complex sub(Complex c)
    {
       Complex result;
       result.real = real - c.real;
       result.img = img - c.img;
       return result;

    }

};

int main ()
{
    Complex c1 = {3,5};
    Complex c2 = {2,-3};
    Complex c3 = {1,-1};

    c1.show();
    c2.show();
    c3.show();
   Complex result = c3.sub(c1.add(c2));
   result.show();



}
