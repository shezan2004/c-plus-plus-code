#include<iostream>
using namespace std;
struct Smartphone {
 string name;
 int storageSpace;
 string color;
 float price;
};
struct Person
{
  string name;
  int age;
  Smartphone smartphone;
};
void print(Smartphone smartphone)
{
    cout<< "Name : "<<smartphone.name<<endl;
     cout<< "Storage space  : "<<smartphone.storageSpace<<endl;
     cout<< "Color: "<<smartphone.color<<endl;
     cout<< "Price : "<<smartphone.price<<endl;
}
void personInfo(Person  person)
{
    cout<< "name : "<< person.name<<endl;
     cout<< " Age :"<< person.age<<endl;
     print(person.smartphone);

}
int main()
{

    Smartphone smartphone;
    smartphone.name= "Iphone 12 ";
    smartphone.storageSpace= 64;
    smartphone.color = " gray";
    smartphone.price = 999.99;

    Smartphone smartphone2;
    smartphone2.name = "SAmsung";
    smartphone2.storageSpace = 64;
    smartphone2.color = "Black";
     smartphone2.price = 99.99;
    /*print(smartphone);
    print(smartphone2);
    */

    Person p;
    p.name = "Shezan";
    p.age = 21;
    p.smartphone = smartphone2;

     personInfo(p);
};
