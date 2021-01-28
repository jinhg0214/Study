/*
set�� key�� �Ҹ��� ������ �������� �̷���� �����̳�. 
- ���Ҹ� �����ϴ� insert() ����Լ��� ����. -> insert���н� ��ȯ��(bool)�� ���� ���и� �� �� ����
- ��� ���Ұ� ������ <-> �ߺ��� ����ؾ� �Ѵٸ� multiset ���
- Ư�� ���� ���ؿ� ���� ���Ҹ� �ڵ� �����ϴ� ���� �����̳�

*/

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

    pair<set<int>::iterator, bool> pr;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    pr = s.insert(90);
    // ���� ��, �ڵ� ���ĵ�.

    cout << pr.second << endl;

    set<int>::iterator iter; // �⺻ ���� ������ less�� set�� ����� �ݺ���
   
    print(s);

    //////////////////////////////////////////////////////////////////////////////////////
    pr = s.insert(50); // �ߺ��� ����(key)�� �����Ѵ�. !! ����!!
    s.insert(50);

    cout << pr.second << endl;

    print(s);

    /////////////////////////////////////////////////////////////////////////////////////
    pr = s.insert(90); 
    // ���Խõ� ��, �ݺ��ڴ� ������ ��� ������ ���Ҹ� ����Ű��,
    // ���н�, ������ ��ġ�� ����Ű�� �ݺ��ڰ� ��.

    s.insert(pr.first, 85);// 90�� ������ �ݺ��ڿ���(�ݺ��ڰ� ����Ű�� ��ġ����) �˻� ���� �� ����(�ӵ���)

    print(s);


    ///////////////////
    set<int, greater<int> > s2;// ���� �������� greater<int> �����ڸ� ���(�������� ����)
    s2.insert(50);
    s2.insert(30);
    s2.insert(80);
    s2.insert(40);
    s2.insert(10);
    s2.insert(70);

    for(iter = s2.begin(); iter != s2.end() ; iter++)
        cout<< *iter << " ";
    cout << endl;

    return 0;

}