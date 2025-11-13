#include<iostream>
using namespace std;
int main()
{

    double utb =110.83;
    double etb =120.28;
    double cdtb = 81.14;
    double audtb= 72.11;
    char choice;
    do
    {
        cout << "Choose currency to convert to BDT:" << endl;
        cout << "1. US Dollar (USD)" << endl;
        cout << "2. Euro (EUR)" << endl;
        cout << "3. Canadian Dollar (CAD)" << endl;
        cout << "4. Australian Dollar (AUD)" << endl;
        int currencychoice;
        cout<< "Enter your choice(1-4) : ";
        cin>>currencychoice;
        double amount;
        cout<< " Enter the amount of selected currency : ";
        cin>>amount;
        double cv;

        switch (currencychoice)
            {


        case 1 :
            cv= amount * utb;
            break;
             case 2 :
            cv= amount * etb;
            break;
            case 3:
            cv= amount * cdtb;
            break;
             case 4 :
            cv= amount * audtb;
            break;
             default :
                cout<< "Not a valid choice"<<endl;
                continue;
            }
             cout  <<  "Converted currency in bdt : " <<cv<<endl;
            cin>>choice;
             cout << "Do you want to convert another currency? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice== 'Y');
     cout<< "Tata bye bye";
    return 0;
}
