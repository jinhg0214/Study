#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int main()
{
    
    string arr;
    cin >> arr;
    int a, b, c, d;
    int sum = 0;
    int v = 0;
    a = 0;
    c = 0;
    while (1) {
        a = arr.find('[', a);
        c = arr.find('{', c);
        if (a == -1)a = arr.length(); // 결과값이 없으면 마지막을 가리키게 설정
        if (c == -1)c = arr.length();
        if (a < c) {
            b = arr.find(']', a + 1);
            string re = arr.substr(a + 1, b - a - 1);
            v = stoi(re);
            sum = sum + v;
            a = b + 1;
        }
        else if (a > c) {
            d = arr.find('}', c + 1);
            string re = arr.substr(c + 1, d - c - 1);
            v = stoi(re);
            sum = sum * v;
            c = d + 1;
        }
        else {  // a == c이면 종료
            break;
        }
    }
    cout << sum;
    return 0;
}