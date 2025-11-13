#include<iostream>
#include<string>
using namespace std;

string lower(string s){

 for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='A'&& s[i]<= 'Z')
        {
            s[i]=s[i]+32;
        }
    }
return s;
}







int main (){
    string str = "ABC";

    cout<< lower(str);

return 0;
}
