#include<iostream>
using namespace std;

  class Box {
   // Access modifiers/Access Specifires
 private:
 double length=0;
 double width=0;
 double height=0;
 public :
     //setter method
     void setLength(double len)
     { if(len >= 0)
     {
         length=len;
     }
     else{ cout<< "Negative value is not Allowed "<<endl;

     }
     }

     void setWidth(double w)
     { if(w>=0)
     {
         width=w;
     }
     else
     {cout<< "Negative value is not Allowed "<<endl;
     } }
      void setHeight(double h)
     { if(h>=0)
     {
         height=h;
     }
     else{cout<< "Negative value is not Allowed "<<endl;
     }
     }
     double getLength(){return length;}
     double getWidth(){return width;}
     double getHeight() {return height;}


 double surfaceArea (){
 return 2 *(length*width + length*height + width*height);
 }
 int compareSurfaceArea(Box b){
 if(surfaceArea() < b.surfaceArea()){return -1;}
 else if(surfaceArea()== b.surfaceArea ())

 {
     return 0;
 }
 else {return 1;}
 }

void show()
{
    cout<< "Length : "<<length<<endl;
    cout<< "width: "<<width<<endl;
    cout<< "Height : "<<height<<endl;
}
};


int main()
{
  Box b;
  b.setLength(2);
  b.setWidth(3);
  b.setHeight(4);
  b.show();
  cout<<b.surfaceArea()<<endl;
  Box b1;
  b1.setLength(20);
  b1.setWidth(15);
  b1.setHeight(10);
  b1.show();
  cout<<b1.surfaceArea();

  return 0;
  }
