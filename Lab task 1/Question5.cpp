#include<bits/stdc++.h>
using namespace std;

double annualBalance(double amount , int years) {
	double currBalance = amount;
	double rate = 6.5 / 100;
    int countYear = 1;

	while(countYear <= years) {
    for(int i = 1; i <= 12; i++) {
       currBalance = currBalance + (currBalance * rate);
    } 
    cout << "Balance in year: " << countYear << " is: " << currBalance << endl;
    countYear ++;
	}

     
  return currBalance;	
}

int main() {

   cout << "Final Balance: " << annualBalance(100000 , 6) << endl; 
   


    return 0;
}