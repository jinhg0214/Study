// adjacent_find() : ���� ���Ұ� ���� ���ҿ� �������� ù ������ �ݺ��ڸ� ��ȯ
// *adjacent : ������, ����� 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ������
// �� �� ���̿� ���̰� 10 �ʰ���� ���� ��ȯ
bool Pred(int a, int b){
    return abs(b-a) > 10;
}

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    // ���� [v.begin(), v.end())���� ���� ���ҿ� ���� ���Ұ� �������� ù ���� �ݺ��ڸ� ��ȯ
    iter = adjacent_find(v.begin(), v.end());

    if(iter != v.end()){
        cout << *iter << endl;
    }

    for(; iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl << "==================================" << endl;

    //////////// ���� ���ҿ� ���� ���Ұ� ���� ���Ұ� ���ٸ� ã�� ������ �� �ݺ��ڸ� ��ȯ! //////////
    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter_b = v.begin();
    vector<int>::iterator iter_e = v.begin()+2; 

    // ���� [iter_b, iter_e) �� ������ : 10, 20 �̹Ƿ�
    // ã�� ���Ұ� �����Ƿ�, ���ϰ��� iter�� ���� ���� iter_e�� ��ȯ��(30)
    iter = adjacent_find(iter_b, iter_e);

    if(iter != iter_e) // �´� ǥ��(iter�� iter_e�� ��)
        cout << *iter << endl;

    cout << "==================================" << endl;
    if(iter != v.end()) // Ʋ�� ǥ��(iter�� ���� �� v.end()�� ��)
        cout << *iter << endl; // �߸��� ������� ���ϵ�

    iter_b = v.begin();
    iter_e = v.end();
    iter = adjacent_find(iter_b, iter_e);

    // �� ��쿣 ������ ���� ��ü�̹Ƿ� iter_e��, v.end()�� ���ص� ���� ����� ���
    if(iter != v.end())
        cout << *iter << endl; // ������� �����Ƿ�, ������ ���� v.end()�� ��ȯ��

    if(iter != v.end()) 
        cout << *iter << endl; // ��������


    /////////////////////////////////////////////////////////////////////////////////
    // ���������� ������ ���Ұ� Ư�� ���ǿ� ���� �������� ã����� ���
    // adjacent_find(b,e,f) : f�� ���� ������ 

    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(90);

    iter = adjacent_find(v.begin(), v.end(), Pred); // Pred(*p, *(p+1))�� ���� ù ������ �ݺ��ڸ� ���� 
    if(iter != v.end())
        cout << *iter << endl; // 30

    for(; iter != v.end(); iter++) // 30���� �������� ���
        cout << *iter << " ";
    cout << endl;

    return 0;

}