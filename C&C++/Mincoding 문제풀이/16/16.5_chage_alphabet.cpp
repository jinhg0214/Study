#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    char before, change;

    cin >> str;
    cin >> before >> change;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == before) {
            str[i] = change;
        }
    }

    cout << str;



    return 0;
}