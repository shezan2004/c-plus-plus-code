#include<iostream>
using namespace std;
struct Complex
{
    double real=0;
    double img=0;
    void show()
    {
        if (real !=0)
        {
            cout<<real;
        }
        if(img>0)
        {
            cout<< " + "<<img<< "i";
        }
        else if(img<0)
        {
          cout<< " - "<<img<< "i";
        }
        cout<<endl;
    }
    Complex add (Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.img = img+c.img;
        return result;
    }
     Complex operator+ (Complex c)
    {
        return add(c);
    }
     Complex sub (Complex c)
    {
        Complex result;
        result.real = real - c.real;
        result.img = img - c.img;
        return result;
    }
    Complex operator- (Complex c)
    {
        return sub(c);
    }
    Complex mul(Complex c)
    {
        Complex result;
        result.real = real * c.real - img * c.img;
        result.img  = real * c.img  + img * c.real;
        return result;
    }
    Complex operator*(Complex c)
    {
        return mul(c);
    }

};
int main()
{
   Complex c1 = {3, 4};
   Complex c2 = {-4,-5};
    c1.show();
    c2.show();
    Complex res = c1.add(c2);
    Complex Res = c1+c2;
    Complex mal = c1*c2;
    res.show();
    Res.show();
    mal.show();

}
