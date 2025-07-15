// CGPAcalculator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string getRemarks(float cgpa) 
{
    if (cgpa >= 3.7) return "Excellent";
    else if (cgpa >= 3.3) return "Very Good";
    else if (cgpa >= 3.0) return "Good";
    else if (cgpa >= 2.0) return "Satisfactory";
    else return "Needs Improvement";
}

int main() 
{
    int numCourses;
    float grade, credit, totalCredits = 0, totalGradePoints = 0;
    string semester;

    cout << "Enter Semester: ";
    getline(cin, semester);

    cout << "Enter number of courses: ";
    cin >> numCourses;
    cin.ignore(); 

    string* courseNames = new string[numCourses];
    float* grades = new float[numCourses];
    float* credits = new float[numCourses];

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Course name: ";
        getline(cin, courseNames[i]);

        cout << "Enter grade: ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];
        cin.ignore();

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalGradePoints * totalCredits;

    cout << "\n\n====== CGPA Report: " << semester << " ======\n";
    cout << left << setw(25) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours" << endl;

    cout << "--------------------------------------------------\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(25) << courseNames[i]
             << setw(10) << fixed << setprecision(2) << grades[i]
             << setw(15) << credits[i] << endl;
    }

    cout << "--------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa << " (" << getRemarks(cgpa) << ")" << endl;

    delete[] courseNames;
    delete[] grades;
    delete[] credits;
	system("pause");
    return 0;
}
