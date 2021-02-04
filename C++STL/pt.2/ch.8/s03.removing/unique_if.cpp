#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// p, p+1�� ���̰� 10 ���϶�� ��
bool Pred(int left, int right){
    return abs(right-left) < 10;
}

int main(){
    //////////////////////////////////////////////////
    // unique(b,e,f) : ���� [b,e)�� �ݺ��� p����, f(*p)�� ���� ������ ���Ҹ� �������� ������.
    cout << "========== 1. unique(b,e) ==========" << endl;

    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(30);
    v.push_back(32);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    vector<int>::iterator iter_end;
    iter_end = unique(v.begin(), v.end(), Pred);

    for_each(v.begin(), v.end(), Print<int>); cout << endl; // 10 30 40 50 (40 50)<- ���� ���� �� ���� ������. ���������� erase() �ʿ�

    for(vector<int>::iterator iter = v.begin(); iter != iter_end; iter++){
        cout << *iter << " ";
    } cout << endl;

    // unique_copy�� ������ �ߺ� ���Ҹ� �����Ͽ�, ������ �������� ������. �������� unique()�� ����

    return 0;

}