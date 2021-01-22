// vector�� �ݺ���

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //�ݺ��ڸ� �̿��� ���� ��ȸ.
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter){
        cout << *iter << endl;
    }

    //�ݺ��ڿ��� + - += -= [] ������ ������
    vector<int>::iterator iter2 = v.begin();
    cout << *iter2 << endl;
    cout << *++iter2 << endl; // ���� ���� ����
    *iter2 = 100; // �Ϲ� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����

    //��� �ݺ��� const_iterator �� ��� �����Ϳ� ����ϰ� ��밡��
    vector<int>::const_iterator citer = v.begin();
    cout << *citer << endl;
    cout << *++citer << endl;
    // *citer = 100; // ��� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����!!

    vector<int>::reverse_iterator riter; // ������ �ݺ���

    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

    for(riter = v.rbegin(); riter != v.rend(); ++riter){ // rbegin: ������ �ݺ����� ù ���� = ������ �ݺ����� �� , rend : ������ �ݺ����� �� = ������ �ݺ����� ����(begin)
        cout << *riter << " ";
    } cout << endl;

    return 0;

}