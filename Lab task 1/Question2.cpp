#include<bits/stdc++.h>
using namespace std;
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
long long calculateAgeInSeconds(int ageInYears, int currentYear) {
    long long totalDays = 0;
    int hoursInDay = 24;
    int minutesInHour = 60;
    int secondsInMinute = 60;
    
    
    int birthYear = currentYear - ageInYears;

  
    for (int year = birthYear; year < currentYear; year++) {
        if (isLeapYear(year)) {
            totalDays += 366;  
        } else {
            totalDays += 365;  
        }
    }
    long long ageInSeconds = totalDays * hoursInDay * minutesInHour * secondsInMinute;
    return ageInSeconds;
}
int main() {
    int ageInYears;
    int currentYear;
    cout << "Enter your age in years: ";
    cin >> ageInYears;
    cout << "Enter the current year: ";
    cin >> currentYear;
    long long ageInSeconds = calculateAgeInSeconds(ageInYears, currentYear);
    cout << "Your age in seconds is approximately: " << ageInSeconds << " seconds." << endl;
    return 0;
}
