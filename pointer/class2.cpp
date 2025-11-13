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
    bool isQubic()
    {
        if(length == width && length == height )
        {
            return  true;
        }
        else {return false;}
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
    /*Box boxes[5];
    for( int i=0; i<5; i++)
 { double length,width,height;
  cin>>length>>width>>height;
  boxes[i].setLength(length);
  boxes[i].setWidth(width);
  boxes[i].setHeight(height);
 }
 for(int i=0; i<5; i++)
 {
     if( boxes[i].isQubic()){
     boxes[i].show();
 } } */
 Box boxes[5];
 for(int i=0 i<5; i++)
 return 0; }





