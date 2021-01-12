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
};

int main(){

    Point p1(2,3), p2(2,3);
    Point result;

    result = ++p1;
    p1.Print();
    result.Print();

    result = p2++;
    p2.Print();
    result.Print();


}