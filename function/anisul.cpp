#include <iostream>
#include <string>

using namespace std;

struct Employee {
    // Data Members
    string EmployeeName;
    int EmployeeID;  // Assuming Employee ID is an integer
    string Designation;
    double MonthlySalary;
    double YearOfService;

    // Member Functions
    void SetEmployeeInfo(string name, int id, string desig, double salary, double years) {
        EmployeeName = name;
        EmployeeID = id;
        Designation = desig;
        MonthlySalary = salary;
        YearOfService = years;
    }

    void GetEmployeeInfo() const {
        cout << "Employee Name: " << EmployeeName << endl;
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Designation: " << Designation << endl;
        cout << "Monthly Salary: " << MonthlySalary << endl;
        cout << "Years of Service: " << YearOfService << endl;
    }

    void EmployeeBonus() const {
        double bonus = 0.0;

        if (Designation == "Collection agent" && YearOfService > 4) {
            bonus = 0.10 * MonthlySalary * 12;  // 10% bonus on annual salary
        } else if (Designation == "Account executive" && YearOfService > 3) {
            bonus = 0.25 * MonthlySalary * 12;  // 25% bonus on annual salary
        } else if (Designation == "Account manager" && YearOfService > 2.5) {
            bonus = 0.2734 * MonthlySalary * 12;  // 27.34% bonus on annual salary
        }

        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    Employee emp1, emp2;

    // Set employee information
    emp1.SetEmployeeInfo("John Doe", 12345, "Collection agent", 5000, 5);
    emp2.SetEmployeeInfo("Jane Smith", 67890, "Account manager", 8000, 3);

    // Display employee information
    cout << "Employee 1 Information:\n";
    emp1.GetEmployeeInfo();
    emp1.EmployeeBonus();
    cout << "\nEmployee 2 Information:\n";
    emp2.GetEmployeeInfo();
    emp2.EmployeeBonus();

    return 0;
}
