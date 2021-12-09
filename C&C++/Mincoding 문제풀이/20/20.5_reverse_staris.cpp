#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        for (int j = str.size() - 1 - i; j < str.size(); j++) {
            cout << str[j];
        }
        cout << endl;
    }

    return 0;
}