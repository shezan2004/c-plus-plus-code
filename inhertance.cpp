#include<iostream>
using namespace std;
class Parent{
    public:
    int x;
    protected :
    int y;
    private :
    int z;

};
class Child1: public Parent {
// x public
// y public
// z not  accessable
};
class Child2: private Parent{
//x private
// y private
// not acccesable
};


int main(){

    return 0;
}
