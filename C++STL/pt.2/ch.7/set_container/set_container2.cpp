#include <iostream>
#include <set>

using namespace std;

void print(set<int> s){

    set<int>::iterator iter;

    for(iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

int main(){

    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    print(s);

    cout << "���� 50�� ����: " << s.count(50) << endl; // ������ ������ ��ȯ�ϴ� ����Լ�(set�� ������ ���Ҹ� �����Ƿ� 0, 1)
    cout << "���� 100�� ����: " << s.count(100) << endl;

    /////////////////////////////

    set<int>::iterator iter;
    iter = s.find(30); // �˻� ����� �ݺ��ڸ� ��ȯ, ������ s.end()�� ���� �ݺ��� ���� ��ȯ��

    if(iter != s.end()) 
        cout << *iter << "�� s�� �ִ�" << endl;
    else
        cout << "30�� s�� �����ϴ�." << endl;

    // !!!!!!!!!! ���� �����̳��� ã�� ���� ����Լ��� key(����)�� ã�� �� == ������ ������� ����!! 
    

    // ���� �˻� lower_boudn, upper_bound
    set<int>::iterator iter_lower; 
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30); // ã�� ������ ���� �ݺ��ڸ� ��ȯ
    iter_upper = s.upper_bound(30); // ã�� ������ ���� ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
    // [lower_bound(), upper_bound()) �� ǥ�� ����

    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);

    if(iter_lower != iter_upper)
        cout << "55�� s�� ����!" << endl;
    else    // ã�� ���Ұ� ���� ��� lower==upper
        cout << "55�� s�� ����!" << endl;

    // �Ǵ� equal_range()�� ���� ���� �˻� ���� 
    // equal_range()�� lower_bound(), upper_bound()�� pair�� ������

    pair<set<int>::iterator, set<int>::iterator> iter_pair; // equal_range�� ���ϰ��� �����ϱ� ���� iter_pair
    iter_pair = s.equal_range(30);

    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);

    if(iter_pair.first != iter_pair.second)
        cout << "55�� s�� ����!" << endl;
    else    // ã�� ���Ұ� ���� ��� lower==upper
        cout << "55�� s�� ����!" << endl;

    return 0;
}