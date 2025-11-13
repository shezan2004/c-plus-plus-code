#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
    char name[]= "\" Abdul KAMAL\"";// \0
     cout<<name<<endl;
     for(int i=0; name[i]!= '\0'; i++)
     {
         cout<<name[i];
     }

    return 0;
}
