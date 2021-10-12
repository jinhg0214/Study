#include<iostream>
#include<string>

using namespace std;

int findNum(string& str, int index) {
    int sz = str.length();

    for (int i = index; i < sz; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return i;
        }
    }
    return -1;
}

int findAlphabet(string& str, int index) {
    int sz = str.length();

    for (int i = index; i < sz; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            return i;
        }
    }

    return -1;
}

int main()
{
    string str;

    cin >> str;

    string name;
    string tmp;
    int serial;

    int a = 0;
    int b = 0;
    int c = 0;

    while (1) {
        a = findAlphabet(str, a);
        if (a == -1)break;

        b = findNum(str, a + 1);
        if (b == -1)break;

        name = str.substr(a, b - a);

        c = findAlphabet(str, b);
        if (c == -1) c=str.length();

        tmp = str.substr(b, c - b);
        serial = stoi(tmp) + 17;

        cout << name << "#" << serial <<endl;

        a = b + 1;
    }

    return 0;
}