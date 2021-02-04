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
    // 1. make_heap(b,e)

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    cout << "v : ";

    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    cout << "========== 1. make_heap(b,e) ==========" << endl;
    make_heap(v.begin(),v.end()); // ��Ʈ�� ���� ū �ִ� �� ����

    cout << "v[�� ����] : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 2. push_heap(b,e) ==========" << endl;
   
    v.push_back(35);  // ���� push_back���� ���Ҹ� �߰� ��,

    push_heap(v.begin(), v.end()); // �� �߰� ������ �����Ѵ�. 

    cout << "v[�� �߰�] ���� ���� : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 3. pop_heap(b,e) ==========" << endl;
    pop_heap(v.begin(), v.end());

    cout << "v[�� ����] ���� ���� : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl; // ��Ʈ ����� 60�� ���� �ڷΰ�. ������ ���Ҵ� ���� ������

     //////////////////////////////////////////////////
    cout << "========== 4. sort_heap(b,e) ==========" << endl;
    sort_heap(v.begin(), v.end());

    cout << "v[�� ����] ���� ���� : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl; // �� ������ ���Ҵ� ������ �ȵɱ�?


    return 0;
}