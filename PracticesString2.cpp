#include <iostream>
#include <string>
using namespace std;

int main(){
    //step 1
    string s1 = "Hello";
    string s2 = "C++";
    cout << s1 << endl;
    cout << s2 << endl;

    //step 2
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    //step 3
    string first = "Hello";
    string second = "World";
    string message = first + " " + second;
    cout << message << endl;

    //step 4
    string z = "Hello";
    cout << "Length of string: " << z.length() << endl;

    //step 5
    string s = "Hello C++";
    cout << "First character: " << s[0] << endl;
    cout << "Third character: " << s[2] << endl;

    //step 6
    string text = "I love C++";
    size_t pos = text.find("C++");
    if (pos != string::npos) {
        cout << "'C++' found at position: " << pos << endl;
    } else {
        cout << "'C++' not found in the text." << endl;
    }

    //step 7
    string text = "Hello C++ World";
    string part = text.substr(6, 3); 
    cout << part << endl;

    //step 8
    string s1 = "apple";
    string s2 = "apple";
    if(s1.compare(s2) == 0) {
        cout << " The strings are equal " << endl;
    } else {
        cout << " The strings are different " << endl;
    }
    return 0;
}
 