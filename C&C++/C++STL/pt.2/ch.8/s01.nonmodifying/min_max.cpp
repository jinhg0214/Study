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

// �� PointŬ������ x���� ��
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
    } else { // X���� ���� ���
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

    // Point��ü�̹Ƿ�, �� �����ڰ� ���� ũ�� �񱳰� �Ұ�����.
    // XCompare��� ���� �����ڸ� ����Ͽ� Point��ü�� x������ ũ�⸦ ����.
    pt3 = max(pt1, pt2, XCompare); // pt1, pt2�߿� x���� ū Point�� pt3�� ���� 
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
    iter = max_element(v.begin(), v.end()); // ���� �� ���� ū ���Ұ��� ����Ű�� �ݺ��ڸ� ��ȯ
    cout << *iter << endl;

    iter = min_element(v.begin(), v.end()); 
    cout << *iter << endl;

    //////////////////////////////////////////////////////////////////////////////
    // max_element()�� ������ ����
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