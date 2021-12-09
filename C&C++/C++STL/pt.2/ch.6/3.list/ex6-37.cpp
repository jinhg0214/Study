// list�� splice() ����Լ�
// �ٸ� list �����̳��� �������� �߶� ���� �� ����

#include <iostream>
#include <list>

using namespace std;

void print(list<int> lt){

    list<int>::iterator iter;

    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

int main(){
    list<int> lt1;
    list<int> lt2;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    list<int>::iterator iter;

    cout << " lt1 : "; print(lt1);
    cout << " lt2 : "; print(lt2);

    iter = lt1.begin();
    ++iter;
    ++iter; // 30 ������ ��ġ�� ����Ŵ

    lt1.splice(iter, lt2); // iter�� ����Ű�� ��ġ�� lt2�� ��� ���Ҹ� �߶� ����

    cout << " lt1 : "; print(lt1);
    cout << " lt2 : "; print(lt2);

    return 0;
}