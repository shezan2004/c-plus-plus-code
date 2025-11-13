#include<iostream>
#include<string.h>
using namespace std;
class Student
{
private :
    string id = "";
    string name = "";
    double cgpa= 0.0;
public:
    char setId(string i)
    {
       id=i;
    }
    void setName(string n)
    {
        name=n;
    }
    void setCgpa (double cg)
    {
        if(cg>=0 && cg<=4)
        {
        cgpa =cg;
        }
    }
    void show()
    {
        cout<< "ID : "<<id<<endl;
        cout<< "Name : "<<name<<endl;
        cout<< " Cgpa : "<<cgpa<<endl;
    }
};
int main()
{
    Student s;
    s.setId("23-53748-3");
    s.setName("touhidul alam shezan");
    s.setCgpa(3.8);
    s.show();
    string str;
    getline(cin, str);
    cout<<str;
    return 0;
}

