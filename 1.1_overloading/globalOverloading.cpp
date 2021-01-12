/*
전역함수 오버로딩
p1.operator-(p2) 가 아닌, operator-(p1,p2) 로 해석됨
무슨 차이?


*/


#include <iostream>

using namespace std;



class Point{
    int x;
    int y;
public:
    Point (int _x=0, int _y=0) : x(_x), y(_y) {}
    void Print() const { cout << x << ',' << y << endl;}
    int GetX() const {return x;}
    int GetY() const {return y;}
};

//Global Overloading
const Point operator-(const Point& argL, const Point& argR){
    // 직접 getter로 호출해서 결과를 포인터 형식으로 리턴해줌
    return Point( argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
};

int main(){
    Point p1(2,3), p2(5,5);
    Point p3;
    
    p3 = p1 - p2;

    p3.Print();

    return 0;
}