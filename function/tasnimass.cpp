#include<iostream>
using namespace std;

struct box
{
    double length=0;
    double width=0;
    double height=0;
    double surfaceArea( )
    {
        int Area;
        Area= 2 * (length * width + width * height + height * length);
        return Area;
    }
    double volume( )
    {
        int vol;
        vol=length*width*height;
        return vol;
    }

    void show()
    {
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Height: "<<height<<endl;
        cout<<"Surface Area: "<<surfaceArea()<<endl;
        cout<<"Volume: "<<volume()<<endl;
    }

    int compareVolume(box b)
    {
        if(volume()<b.volume())
        {
            return -1;
        }
        else if(volume()>b.volume())
        {
            return 1;
        }
        else if(volume()==b.volume())
        {
            return 0;
        }
    }

    int compareSurfaceArea(box b)
    {
        if(surfaceArea()<b.surfaceArea())
        {
            return -1;
        }
        else if (surfaceArea()>b.surfaceArea())
        {
            return 1;
        }
        else if (surfaceArea()==b.surfaceArea())
        {
            return 0;
        }
    }
};

int main()
{
    box b1,b2;
    b1={2,1,2};
    b2={2,2,2};

    cout<<"All information of b1"<<endl;
    b1.show();
    cout<<endl<<"All information of b2"<<endl;
    b2.show();

    cout<<endl<<"Volume Comparison:"<<endl;

    if(b1.compareVolume(b2)==1)
    {
        cout<<"b1 is Bigger in Volume than b2."<<endl;
    }
    else if (b1.compareVolume(b2)==-1)
    {
        cout<<"b1 is Smaller in Volume than b2."<<endl;
    }
    else
    {
        cout<<"Both are same in Volume"<<endl;
    }

    cout<<endl<<"Surface Area Comparison:"<<endl;

    if(b1.compareSurfaceArea(b2)==1)
    {
        cout<<"b1 has Bigger Surface Area than b2."<<endl;
    }
    else if (b1.compareSurfaceArea(b2)==-1)
    {
        cout<<"b1 has Smaller Surface Area than b2."<<endl;
    }
    else
    {
        cout<<"Both has same Surface Area"<<endl;
    }

    return 0;
}
