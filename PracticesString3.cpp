#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    //step 1
    cout << "Nhap 1 cau (vi du: I love C++): ";
    getline(cin, sentence);

    //step 2
    cout << "\n--- Ket qua ---\n";
    cout << "Do dai cau: " << sentence.length() << " ky tu" << endl;

    //step 3
    string keyword = "C++";
    size_t pos = sentence.find(keyword);

    if (pos != string::npos) {
        cout << "Tim thay \"" << keyword << "\" tai vi tri: " << pos << endl;
    } else {
        cout << "Khong tim thay \"" << keyword << "\" trong cau!" << endl;
    }

    //step 4
    string part = sentence.substr(0, 10);
    cout << "10 ky tu dau tien: \"" << part << "\"" << endl;

    //step 5
    string newWord = "Java";
    string result = sentence; 
    if (pos != string::npos) {
        result.replace(pos, keyword.length(), newWord);
    }

    //step 6
    cout << "Cau sau khi thay the: \"" << result << "\"" << endl;

    return 0;
}