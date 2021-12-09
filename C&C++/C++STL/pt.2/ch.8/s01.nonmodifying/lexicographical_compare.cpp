// ������ ���� ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct Less{
    bool operator() (const T& left, const T& right) const{
        return left < right;
    }
};

int main(){

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(50);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);

    // [v1.begin(),v1.end())��, [v2.begin(), v2.end())���� ���������� less�ΰ�? 
    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end())){
        cout << "v1 < v2" << endl; // 10, 20�� ������ 30 < 50 �̹Ƿ�, true�� ��ȯ��.
    } else {
        cout << "v1 >= v2" << endl;
    }


    if(lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end())){
        cout << "v1 < v3" << endl;
    } else {
        cout << "v1 >= v3" << endl; // �� �������� �����Ƿ� false �� ��ȯ��
    }

    //////////////////////////////////////////////////////////////////////////////////
    // lexicographical_compare() ���� ������
    v2.clear();
    v2.push_back(10);
    v2.push_back(25);
    v2.push_back(30);

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>() ) ){
        cout << " ���� less, v1�� v2�� �� : true" << endl;
    } else {
        cout << " ���� less, v1�� v2�� �� : flase" << endl;
    }

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>() ) ){
        cout << " ���� greater, v1�� v2�� �� : true" << endl;
    } else {
        cout << " ���� greater, v1�� v2�� �� : flase" << endl;
    }

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), Less<int>() ) ){
        cout << " ����� ���� Less, v1�� v2�� �� : true" << endl;
    } else {
        cout << " ����� ���� Less, v1�� v2�� �� : flase" << endl;
    }


}