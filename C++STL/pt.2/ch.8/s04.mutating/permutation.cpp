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

// Point 객체 cout 출력을 위한 연산자 오버로딩
ostream& operator << (ostream& out , const Point& arg){
    out << "(" << arg.GetX() << "," << arg.GetY() << ")";
    return out;
}

// 순열의 비교 기준으로 사용될 이항 조건자(y값을 이용해 순열 생성)
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

    // Point y를 기준으로 마지막 순열이므로,  next_permutation()은 false를 반환함
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end(), Pred) << endl;

    // 다시 1을 반환한다
    // cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    //  cout << next_permutation(v.begin(), v.end(), Pred) << endl;
    */
    do{
        cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    }while(next_permutation(v.begin(), v.end(), Pred));
    
    return 0;
}