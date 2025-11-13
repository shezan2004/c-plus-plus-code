#include<iostream>
using namespace std;
int main()
{int i,j,k;
    int counter =0 ;
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=4;j++)
        {
            for(k=1; k<=4; k++)
            {
                if(i!=k && j!=k && j!=i )
                {
                    cout<<i<<j<<k<< " ";
                    counter++;
                }
        }
    }
}
 cout<<endl;
cout<< " Total counter : "<<counter;

}
