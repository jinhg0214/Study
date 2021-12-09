#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

bool Pred(int n){
    return n < 40;
}

int main(){

    vector<int> v;

    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    vector<int>::iterator iter_sep;

    // 40�� pivot���� ������ �����ϸ鼭 �з�
    iter_sep = stable_partition(v.begin(), v.end(), Pred);
    cout << *iter_sep<< endl; // stable_partition�� ������ ����Ŵ

    cout << "40�̸��� ������: ";
    for(vector<int>::iterator iter = v.begin(); iter!= iter_sep; iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "40�̻��� ������: ";
    for(vector<int>::iterator iter = iter_sep; iter!= v.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
