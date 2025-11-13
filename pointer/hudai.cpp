#include<iostream>
using namespace std;

class Box {
private :
    double length = 0;
    double width  = 0;
    double height = 0;
   public :
       void setLength(double len)
       {
           if(len>=0)
           {
               length =len;
           }
           else {cout<< "Negative number.";}
       }
       void setWidth(double w)
       {
           if(w>=0)
           {
               width =w;
           }
           else {cout<< "Negative number.";}
       }
       void setHeigth(double h)
       {
           if(h>=0)
           {
                 height= h;
           }
           else {cout<< "Negative number.";}
       }
       double getLength(){return length;}
       double getwidth(){return length;}
       double getheigth(){return length;}

    double surfaceArea(Box b)
    {
        return 2 * (length*width) + (width * height) +(length * height);
    }
    void show()
    {
        cout<< " length :"<<length;
        cout<< " height :"<<height;
        cout<<  "width : "<<width;
    }


};
int main ()
{
    Box b;
    b.setLength(20);
     b.setWidth(20);
      b.setHeigth(20);
      b.show();
     cout<< b.surfaceArea();

}
