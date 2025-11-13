
#include <iostream>
using namespace std;


int main() {
    float a[3];
     cout<< "Enter three cgpa : ";
    for(int i=0; i<3;i++)

    {

        cin>>a[i];
    }//3 4 2
    float lowest = a[0];
    for( int i=1; i<3; i++)
    {
        if(a[i]<lowest)
        {
            lowest = a[i];
        }
    }

    cout<< " lOwest : "<<lowest;



    return 0;
}
create an arry to store 5 intiger number and 4 floating point number by asking the user for inputs. NOw, devolep a pogram that checks whether each number present in the array is an even number or an odd number and replace the even numbers with '0' and odd number with '1' later the pogrames prints the modified arry
