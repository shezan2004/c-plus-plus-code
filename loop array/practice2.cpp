#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<< "Enter any letter :";
    cin>>ch;
    if((ch<= 'A' &&  ch>= 'Z') || (ch<= 'a' &&  ch>= 'z'))
    {


     switch (ch)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout<< "Vowel";
            break;
        default:
            cout<< "Consonant;";

        } }
    else
    {
        cout<< "not a valid charecter";;
    }

    return 0;

}
