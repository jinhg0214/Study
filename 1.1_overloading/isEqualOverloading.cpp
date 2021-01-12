#include <iostream>

using namespace std;

class Point{
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0):x(_x),y(_y) {}

    void Print() const { cout << x << ',' << y << endl; }
    
    // prefix
    const Point& operator++(){
        ++x;
        ++y;

        return *this;
    }

    //postfix
    const Point operator++(int){
        Point pt(x, y);
        ++x; // 내부 구현이므로 멤버 변수는 prefix 연산을 사용해도 무방합니다.
        ++y; // ''

        return pt;


    }

    //isEqual?
    bool operation==(const Point& arg) const{
        return x == arg.x && y == arg.y ? true : false;
    }

    // isEqual == 을 정의했으므로, 이 함수에서 ==로 this와 arg를 비교할 수 있다!!
    bool operation!=(const Point& arg) const{
        return !(*this==arg); 
    }

};
