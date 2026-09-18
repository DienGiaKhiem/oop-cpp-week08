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
    string s = "Hello C++";
    cout << "Length of string: " << s.length() << endl;

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

    return 0;
}
 