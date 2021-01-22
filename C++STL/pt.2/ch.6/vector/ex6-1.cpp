/* vector 
 -���ʹ� ���� ���� �ݺ��ڸ� �����ϴ� �迭 ��� �����̳�!
 -���Ұ� �ϳ��� �޸� ��Ͽ� �����ϰ� �����.
 -���Ұ� �߰��ǰų� ���Եɶ�, �޸� ���Ҵ��� �Ͼ �� �ְ�, ����� ����� �����ؾ� �� ���� ����.
 �׷��� capacity() ��� �Լ��� �����Ͽ� �޸� �Ҵ� ũ�⸦ �˷���. 
 -at[], v[i] ��� ���� ���ҿ� �����ϴ� ������ ��������, insert(), erase(), push_back()���� ��������
 -���� ������ ��� �����̳��̹Ƿ�, front(), end(), push_back(), pop_back()�� ����
 -push_front(), pop_front()�� ��������!(�ſ� ��ȿ����)*/ 
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;  // int ������ �����̳� ����

    v.push_back(10); // v.push_back(x) : v�� x���Ҹ� �߰� 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i =0; i<v.size(); i++){ // v.size() : v�� ������ ���� ��ȯ
        cout << v[i] << endl;   // v[i] : v�� i��° ���Ҹ� ����
    }

    cout << v[6] << endl; 
    //v[i] �� v.at(i)�� ����!! v[i]�� ������ ���������� ���� �ʾ� �ӵ��� ����, �׷��� �߸��� ��!
    // v.at(i)�� ���� ������ �Ͽ� �����Ͻ� ���� �߻�

    cout << typeid(vector<int>::size_type).name() << endl; // -> vector<int>::size_type�� unsigned int��!

    cout << v.size() << endl;       // ���� ���� ũ��
    cout << v.capacity() << endl;   // ���� �Ҵ�� �޸� ������ ũ��
    cout << v.max_size() << endl;   // �����̳ʰ� ���� �� �ִ� �ִ� ������ ����

    return 0;
}