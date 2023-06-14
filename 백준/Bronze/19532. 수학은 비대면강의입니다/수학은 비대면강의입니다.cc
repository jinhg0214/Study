/*
브2 : 수학은 비대면 강의 
연립 방정식의 해를 구하는 문제

ax + by = c
dx + ey = f

a, b, c, d, e, f 가 주어질 때, (-999 <= a,b,c,d,e,f <= 999)

유일한 해의 쌍 x, y를 구하는 문제. (-999 <= x, y <= 999, x, y는 정수)

연립 방정식의 해를 구하는 방법은?
1) 대입법 : 한 방정식을 어느 한 미지수에 대하여 풀고, 그 식을 다른 한 방정식에 대입하여 푼다
2) 가감법 : 합 또는 차를 이용해서 푼다
여기선 대입법을 이용함

y = (c - ax)/b 를 2번 식에 대입
dx + e * (c-ax)/b = f
를 x에 대하여 정리하면,
x = (f - e*(c-ax)/b ) / d 가 된다.

필요 변수들
a, b, c, d, e, f 
x, y;

*/

#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	double x = ((c * e - b * f) / (a * e - b * d));
	double y = ((-c * d + a * f) / (a * e - b * d));

	cout << x << " " << y;

	return 0;
}