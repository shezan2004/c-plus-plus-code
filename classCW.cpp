#include<iostream>
using namespace std;
class fruit{
    public:  
string name;
string colour;
fruit(string n, string c){
   name =n;
   colour =c;
}

};

int main(){
  fruit mango("Mango", "yellow");
  cout<<mango.name<<endl;
  cout<<mango.colour<<endl;
  

    return 0;
}