#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� ������ ���̰� 5 �̸��̸� ���� ��ȯ
bool Pred(int left, int right){
    return abs(right-left) < 5;
}

int main(){
    //////////////////////////////////////////////////////////////////////////
    // equal(b,e,b2) : [b,e)�� ��������, ���� [b2,b2+(e-b))�� �������� ������ �Ǵ��ϴ� �˰���
    vector<int> v1, v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;   

    // ���� [v1.begin(), v1.end())�� ���� [v2.begin(), v2.begin()+3)�� ��
    if(equal(v1.begin(), v1.end(), v2.begin()))
        cout << "�� �������� �����ϴ�" << endl;
    cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // equal(b,e,b2,f) : ���� �����ڷ� �� �������� �ݺ��� p,q�� ���� f(*p, *q)�� ��� ���̸� equal()�� ���� ��ȯ

    v1.clear(); v2.clear();

    v1.push_back(10);
    v1.push_back(21);
    v1.push_back(30);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(33);

     cout << "v1 : ";
    for(vector<int>::size_type i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;   

    if(equal(v1.begin(), v1.end(), v2.begin(), Pred)){
        cout << "�� �������� ���̴� 5�̸��Դϴ�." << endl;
    }

    return 0;
}
