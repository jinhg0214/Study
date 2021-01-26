/*
���� ���Ḯ��Ʈ List.
������ �߰��� ���Ҹ� ����, �����Ͽ��� ��� �ð� ���⵵�� ����.
��� ��� �����̳ʴ� ����, �����ص� �ݺ��ڰ� ��ȿȭ ���� ����, �׷��� �迭 ����� �޸𸮰� ���Ҵ� �� �� �־� ��ȿȭ �� ��������!!
*/

#include <iostream>
#include <list>

using namespace std;



void print(list<int> lt){

    list<int>::iterator iter;

    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

bool Predicate(int n){
    return n >= 100;
}

int main(){
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    list<int>::iterator iter;
    list<int>::iterator iter2;

    print(lt);
    
    /////////////////// push_front, push_back 
    lt.push_front(100);
    lt.push_back(200);

    print(lt);

    //////////////////// erase() Ư�� ���� ����
    iter = lt.begin(); // 100 10 20 30 40 50 200
    ++iter; ++iter; ++iter; // iter�� 30�� ����Ŵ

    iter2 = lt.erase(iter); // iter(30) ����

    print(lt);

    iter = iter2;
    iter2 = lt.insert(iter, 300); // iter2(40) �� ����Ű�� ��ġ�� 300�� ����

    print(lt);

    cout << " iter2 : " << *iter2 << endl;

    lt.remove_if(Predicate); // Predicate�� ���ϰ��� ���� ���� ����

    print(lt);
    
    return 0;

}
