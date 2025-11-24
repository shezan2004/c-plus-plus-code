#include<iostream>
using namespace std;
    struct phone{
      string phoneName;
      int storage;
      string color;
      float price;
    };
    void showPhoneDetails(phone mobile){
        cout<< " Phone Model : "<<mobile.phoneName<<endl;
        cout<< " Phone storage : "<<mobile.storage<<endl;
        cout<<" phone color : "<<mobile.color<<endl;
        cout<<" Phone Price : "<<mobile.price<<endl;
    }
   
   
     struct person{
        string name;
        int age;
        phone mobile;
        
    };
    void showPersonInfo(person person){
         cout<<" Name : "<<person.name<<endl;
        cout<<"Age : "<<person.age<<endl;
        showPhoneDetails(person.mobile);
    }

    int main(){
        phone iphone;
        iphone.phoneName = "Iphone12";
        iphone.storage = 4;
        iphone.color =" blue";
        iphone.price =56.89;
        phone nokia;
        nokia.phoneName = "Nokia xs";
        nokia.storage = 9;
        nokia.color =" red";
        nokia.price =6.89;
        // showPhoneDetails(iphone);
        // showPhoneDetails(nokia);
        person shezan;
        shezan.name = "Shezan";
        shezan.age = 22;
        shezan.mobile = nokia;
        showPersonInfo(shezan);

        return 0;
    }
