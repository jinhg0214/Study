#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    cout << "==========1.copy()==========" << endl;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(5); // �˰����� ����� ������� �����ϹǷ�, ������ ������ �����߻���!

    vector<int>::iterator iter;

    //���� [v1.begin(), v1.end())�� ��� ���Ҹ� [v2.begin(), v2.begin()+(v1.end() -v1.begin()))�� �������� ����
    iter = copy(v1.begin(), v1.end(), v2.begin()); // 10,20,30,40,50 ������ ����

    cout << "v2 ������ ����: " << *(iter-1) << endl; // copy �˰����� ������ �� �ݺ��ڸ� ��ȯ��. 

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////
    // copy_backward()
    cout << "==========2.copy_backward()==========" << endl;
    v2.resize(10);
    v2.clear();

    // v2�� ��� ���Ҹ� 0���� �ʱ�ȭ
    iter = v2.begin();
    v2.insert(iter,10,0);
    
    // [v1.begin(), v1.end())�� ���Ҹ�
    // [iter, v2.end())�� �������� ������ ���Һ��� ����(50,40,30,20,10)
    iter = copy_backward(v1.begin(), v1.end(), v2.end()); // ������ ���� �ݺ��ڸ� ��ȯ��

    cout << "v2 ù ����: " << *iter << endl;

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;



    return 0;
}