#include <iostream>
#include <string>
using namespace std;

int main(){
    string FullName;
    string StudentID;
    string Email;
    string homeTown;

    cout << "Enter your full name: ";
    getline(cin, FullName);
    cout << "Enter your student ID: ";
    getline(cin, StudentID);
    cout << "Enter your email: ";
    getline(cin, Email);
    cout << "Enter your hometown: ";
    getline(cin, homeTown);

    cout << "==============Student Information==================" << endl;
    cout << "Full Name: " << FullName << endl;
    cout << "Student ID: " << StudentID << endl;
    cout << "Email: " << Email << endl;
    cout << "Hometown: " << homeTown << endl;
    cout << "===================================================" << endl;
    return 0;
}