#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
    int x, y;
public:
    explicit Point(int _x=0, int _y=0):x(_x), y(_y){}
    int GetX() const{return x;}
    int GetY() const{return y;}
};

// Point ��ü cout ����� ���� ������ �����ε�
ostream& operator << (ostream& out , const Point& arg){
    out << "(" << arg.GetX() << "," << arg.GetY() << ")";
    return out;
}

// ������ �� �������� ���� ���� ������(y���� �̿��� ���� ����)
bool Pred(const Point& left, const Point& right){
    return left.GetY() < right.GetY();
}

int main(){
    vector<Point> v;

    v.push_back(Point(5,1));
    v.push_back(Point(7,2));
    v.push_back(Point(5,3));

    /*
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;

    // Point y�� �������� ������ �����̹Ƿ�,  next_permutation()�� false�� ��ȯ��
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;

    // �ٽ� 1�� ��ȯ�Ѵ�
    // cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    //  cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    */
    do{
        cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    }while(next_permutation(v.begin(), v.end(), Pred));
    
    return 0;
}