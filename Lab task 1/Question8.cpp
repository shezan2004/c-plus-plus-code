#include<bits/stdc++.h>
using namespace std;
void grading(int courses) {
    double cgpa = 0;
    double totalMarks = 0;
    double marks[courses];

    for (int i = 0; i < courses; i++) {
        double mark;
        cout << "Enter marks for Course " << (i + 1) << ": ";
        cin >> mark;
        marks[i] = mark;
        totalMarks += mark;

        if (mark >= 90) {
            cout << "Course: " << (i + 1) << " Grade is: A+" << endl;
            cgpa += 4.00;
        } else if (mark >= 85) {
            cout << "Course: " << (i + 1) << " Grade is: A" << endl;
            cgpa += 3.75;
        } else if (mark >= 80) {
            cout << "Course: " << (i + 1) << " Grade is: B+" << endl;
            cgpa += 3.50;
        } else if (mark >= 75) {
            cout << "Course: " << (i + 1) << " Grade is: B" << endl;
            cgpa += 3.00;
        } else if (mark >= 70) {
            cout << "Course: " << (i + 1) << " Grade is: C+" << endl;
            cgpa += 2.75;
        } else if (mark >= 65) {
            cout << "Course: " << (i + 1) << " Grade is: C" << endl;
            cgpa += 2.50;
        } else if (mark >= 60) {
            cout << "Course: " << (i + 1) << " Grade is: D+" << endl;
            cgpa += 2.25;
        } else if (mark >= 55) {
            cout << "Course: " << (i + 1) << " Grade is: D" << endl;
            cgpa += 2.00;
        } else if (mark >= 50) {
            cout << "Course: " << (i + 1) << " Grade is: E" << endl;
            cgpa += 1.50;
        } else {
            cout << "Course: " << (i + 1) << " Grade: F" << endl;
        }
    }

    double final_cgpa = cgpa / courses;
    cout << "Total Marks: " << totalMarks << endl;
    cout << "Total CGPA: " << final_cgpa << endl;

    cout << "Final Grade: ";
    if (final_cgpa >= 3.75) {
        cout << "A+" << endl;
    } else if (final_cgpa >= 3.50) {
        cout << "A" << endl;
    } else if (final_cgpa >= 3.00) {
        cout << "B+" << endl;
    } else if (final_cgpa >= 2.75) {
        cout << "B" << endl;
    } else if (final_cgpa >= 2.50) {
        cout << "C+" << endl;
    } else if (final_cgpa >= 2.00) {
        cout << "C" << endl;
    } else if (final_cgpa >= 1.50) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
}

int main() {
    int courses = 5;
    grading(courses);
    return 0;
}
