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
        ++x; // ���� �����̹Ƿ� ��� ������ prefix ������ ����ص� �����մϴ�.
        ++y; // ''

        return pt;


    }

    //isEqual?
    bool operation==(const Point& arg) const{
        return x == arg.x && y == arg.y ? true : false;
    }

    // isEqual == �� ���������Ƿ�, �� �Լ����� ==�� this�� arg�� ���� �� �ִ�!!
    bool operation!=(const Point& arg) const{
        return !(*this==arg); 
    }

};
