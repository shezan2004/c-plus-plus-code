#include<iostream>
using namespace std;

struct Box
{
    double length = 0;
    double width = 0;
    double height = 0;

    double SurfaceArea()
    {
        return 2 * (length * width + width * height + height * length);
    }

    double Volume()
    {
        return length * width * height;
    }

    void displayInfo(){
        cout <<"Length: "<<length<<endl;
        cout <<"Width: " <<width <<endl;
        cout <<"Height: " <<height<<endl;
        cout <<"Surface Area: "<<SurfaceArea()<<endl;
        cout <<"Volume: "<<Volume()<<endl;
    }

    int compareVolume(Box otherBox)
    {
        if (Volume() < otherBox.Volume()){
            return -1;
        }
        else if (Volume() > otherBox.Volume()){
            return 1;
        }
        else if (Volume() == otherBox.Volume()){
            return 0;
        }
    }

    int compareSurfaceArea(Box otherBox)
    {
        if (SurfaceArea() < otherBox.SurfaceArea()){
            return -1;
        }

        else if (SurfaceArea() > otherBox.SurfaceArea()){
                return 1;
        }
        else if (SurfaceArea() == otherBox.SurfaceArea()){
                return 0;
        }

    }
};

int main()
{
    Box b1, b2;
    b1 = {2, 1, 2};
    b2 = {2, 2, 2};


    b1.displayInfo();

    b2.displayInfo();

    cout<<"Volume Compare:"<<b1.compareVolume(b2)<<endl;


    cout<<"Surface Area Comparison:"<<b1.compareSurfaceArea(b2)<<endl;


return 0;
}
