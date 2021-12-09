#include <iostream>

using namespace std;

int main()
{
    string str;

    cin >> str;

    string res;
    int a = 0;
    int b = 0;
    int c = 0;

    // 1. 괄호 제거 

    while (1) {
        a = str.find('(', a);
        if (a == -1)break;

        b = str.find(')', a + 1);
        if (b == -1) break;
            
        while (1) {
            c = str.find('(', a + 1);
            if (c == -1)break;
            if (c < b) {
                a = c;
            }
            else break;
        }

        res += str.substr(a, b - a + 1);

        a = a + 1;
        b = b + 1;
    }

    // 2. 웃는 눈이 ^^^인 경우 ^^로 정리
    a = res.find("^^^");
    if (a != -1) {
        res.replace(a, 3, "^^");
    }

    // 3. 눈과 눈 사이의 글자가 _가 아닌것들이 있다면 모두 _로 정리
    a = 0;
    while (1) {
        a = res.find('^', a);
        if (a == -1)break;

        if (res[a + 2] == '^') {
            res.replace(a + 1, 1, "_");
        }

        a = a + 1;
    }
       
    cout << res;

    return 0;
}