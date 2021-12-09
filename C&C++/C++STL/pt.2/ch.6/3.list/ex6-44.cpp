// merge() ����Լ�
// �ΰ��� "���ĵ�" list�� �ϳ��� ���ĵ� list�� �պ���
// �պ��� �� list�� ������������ ���ĵǾ� �ִٴ� ���� �Ͽ� ������
// ���ĵǾ����� ���� ���, ������ �߻��Ҽ�������
// slice() ����Լ��� ���Ͽ� �˾ƵѰ�!!

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
    
    lt2.push_back(35);
    lt2.push_back(25);
    lt2.push_back(60);

    list<int>::iterator iter;

    cout << "lt1 : "; print(lt1);
    cout << "lt2 : "; print(lt2);

    lt1.merge(lt2); // lt2�� lt1���� �պ� ����. ���� ������ less

    cout << "lt1 : "; print(lt1);
    cout << "lt2 : "; print(lt2);  
    


    return 0;
}