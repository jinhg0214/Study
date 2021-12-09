#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    //////////////////////////////////////////////////
    // remove(b,e)
    cout << "========== 1. remove(b,e) ==========" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    vector<int>::iterator iter_end;

    iter_end = remove(v.begin(), v.end(), 30); // 30�� ����(40�� 30���� ����� ��ĭ�� ���)

    for_each(v.begin(), v.end(), Print<int>); cout << endl; // ��� ��� 10, 20, 40, 50, 50 �� ����. (50�� 2��)

    cout << "remove �� [v.begin(), iter_end) ������ : ";
    for(vector<int>::iterator iter=v.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;

    // ���� [iter_end, v.end())�� ���Ҹ� ������ ���� (50 ����)
    v.erase(iter_end, v.end());
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // remove_if ���� 

    //////////////////////////////////////////////////
    // remove_copy(b,e)
    cout << "========== 2. remove_copy(b,e,t) ==========" << endl;

    v.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);

    // [v.begin(), v.end())���� / ������ �����ϴ� ���Ҹ� ������ ��� ���Ҹ� / v2.begin()���� ����
    iter_end = remove_copy(v.begin(), v.end(), v2.begin(), 30);

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    cout << "v : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    cout << "[v2.begin(), iter_end) ������ : ";
    for(vector<int>::iterator iter=v2.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}