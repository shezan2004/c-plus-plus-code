#include<iostream>
using namespace std;

class Box {
private :
    double length = 0;
    double width  = 0;
    double height = 0;
public :
    void setLength( double len)
    { if(len>=0)
    {
        length=len;
        }
        else cout<< "Number is not affective .";
        }
    void setWidth( double w)
    { if(w>=0)
    {
        width=w;
        }
        else cout<< "Number is not affective .";
        }
         void setHeight( double h)
    { if(h>=0)
    {
        height = h;
        }
        else cout<< "Number is not affective .";
        }
        double getLength (){return length;}
        double getWidth () {return width;}
        double getHeight () {return height;}
        double surfaceArea()
        {
            return 2 * (length * height) + (length * width)+ (height *width);
        }
        void show()
        {
            cout<< " Length :  "<<length<<endl;
            cout<< "  Width :  "<<width<<endl;
            cout<< " Height :  "<<height<<endl;
        }

 };
 int main()
 {
     Box b;
     b.setLength(10);
     b.setWidth(15);
     b.setHeight(20);
     b.show();
     cout<<b.surfaceArea()<<endl;
     return 0;

 }
