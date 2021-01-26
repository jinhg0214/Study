// reverse() ����Լ�
// ������ �������� �ݴ�� ������� �� ��� ���

// unique() ����Լ�
// ���Ҹ� �ߺ����� �ʰ� �ϳ����� ����.

// sort() ����Լ�
// list�� sort() �˰��� �̿� �Ұ�(���� ���� �ݺ��ڰ� �ƴϹǷ�)
// ��ü ���� ����Լ� sort() �� ������. �⺻�� �������� less <-> Greater()

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

    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    list<int>::iterator iter;

    print(lt);

    lt.reverse(); // ������ �������� �ݴ�� ������

    print(lt);

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    print(lt);

    lt.unique(); // ������ �ߺ��� ���Ҹ� ��ħ-> 10 10 10 20 30 20 30 -> 10 20 30 20 30 ...

    print(lt);

    // unique()�� ��� ���Ҹ� �����ϰ� ������� �Ѵٸ�, ���Ҹ� �����ϰ� �����ؾ���.

    lt.sort(); 
   

    lt.unique(); // 1010 2020 3030 4040 5050 -> 10 20 30 40 50 

    print(lt);

    return 0;

}