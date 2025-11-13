#include<iostream>
#include<string.h>
using namespace std;

class Student{
    private :
        string id= "";
        string name = "";
        double cgpa = 0.00;
    public :
        void setId (string i)
        {
            id=i;
        }
        void setName(string n)
        {
            name = n;
        }
        void setCgpa(double c)
        {
            cgpa = c;
        }
        void show()
        {
            cout<< "Id : "<<id;
            cout<< "Name :"<<name;
            cout<< "cgpa : "<<cgpa;
        }
};
int main()
{
  Student s;
  s.setId    ("23-53748-3");
  s.setName  ("SHEZANNNNNNNNN");
  s.setCgpa (3.8);
  s.show();
}
