#include<iostream>
using namespace std;
struct Box {
    double l;
    double h;
    double w;
    double SurfaceArea ()
    {
        return 2*l*w + l*h +w*h;
    }
    int csa(Box b )
    {
        if(SurfaceArea() < b.SurfaceArea())
        {
            return -1;
        }
        else if(SurfaceArea()==b.SurfaceArea())
        {
            return 0;
        }
        else
            {return 1;}
    }
    void show()
    {
        cout<< "Length : "<<l;
        cout<< "Height : "<<h;
        cout<< "Weight : "<<w;
    }
};
int main()
{ Box b;
 b= {3,2,1};
 Box b1;
 b1= {4,5,6};
 b.show();
 cout<< " Surface Area : "<<b.SurfaceArea()<<endl;
 b1.show();
 cout<< "B1 Surface Area : "<<b.SurfaceArea()<<endl;
 cout<<b1.csa(b)<<endl;
 cout<<b.csa(b1)<<endl;


}
