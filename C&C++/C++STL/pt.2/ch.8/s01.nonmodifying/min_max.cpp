#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
    int x, y;

public : 
    explicit Point(int _x = 0, int _y =0):x(_x), y(_y){}
    int GetX() const {return x;}
    int GetY() const {return y;}
    void Print() const {cout << '(' << x << "," << y << ')' << endl;}
};

// 두 Point클래스의 x값을 비교
bool XCompare(const Point& left, const Point& right){
    return left.GetX() < right.GetX();
}

bool YCompare(const Point& left, const Point& right){
    return left.GetY() < right.GetY();
}

bool Compare(const Point& left, const Point& right){
    if(left.GetX() < right.GetX()){
        return true;
    } else if(left.GetX() > right.GetX()) {
        return false;
    } else { // X값이 같은 경우
        return left.GetY() < right.GetY();
    }
}

int main(){
    int a=10, b=20;
    int r;

    r=max(a,b);
    cout << "max: " << r << endl;
    r = min(a,b);
    cout << "min: " << r << endl;

    Point pt1(5, 8), pt2(3, 9);
    Point pt3;

    // Point객체이므로, 비교 연산자가 없어 크기 비교가 불가능함.
    // XCompare라는 이항 조건자를 사용하여 Point객체의 x값으로 크기를 비교함.
    pt3 = max(pt1, pt2, XCompare); // pt1, pt2중에 x값이 큰 Point를 pt3에 저장 
    cout << "x max: "; pt3.Print();

    pt3 = max(pt1, pt2, YCompare); 
    cout << "y max: "; pt3.Print();

    //////////////////////////////////////////////////////////////////////////////
    // max_element(), min_element()
    cout <<"==============================" << endl;

    vector<int> v;
    v.push_back(30);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);

    vector<int>::iterator iter;
    iter = max_element(v.begin(), v.end()); // 범위 내 가장 큰 원소값을 가리키는 반복자를 반환
    cout << *iter << endl;

    iter = min_element(v.begin(), v.end()); 
    cout << *iter << endl;

    //////////////////////////////////////////////////////////////////////////////
    // max_element()의 조건자 버전
    cout <<"==============================" << endl;
    vector<Point> vp;

    vp.push_back(Point(3,2));
    vp.push_back(Point(2,5));
    vp.push_back(Point(1,5));
    vp.push_back(Point(3,3));
    vp.push_back(Point(3,2));

    vector<Point>::iterator piter;
    piter = max_element(vp.begin(), vp.end(), Compare);

    cout << "max: "; piter->Print();
    // cout << "max: "; (*piter).Print();

    return 0;
}