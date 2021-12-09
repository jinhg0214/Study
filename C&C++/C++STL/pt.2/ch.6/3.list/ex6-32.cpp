/*
이중 연결리스트 List.
순차열 중간에 원소를 삽입, 제거하여도 상수 시간 복잡도를 가짐.
노드 기반 컨테이너는 삽입, 제거해도 반복자가 무효화 되지 않음, 그러나 배열 기반은 메모리가 재할당 될 수 있어 무효화 될 수도있음!!
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

    //////////////////// erase() 특정 원소 삭제
    iter = lt.begin(); // 100 10 20 30 40 50 200
    ++iter; ++iter; ++iter; // iter는 30을 가리킴

    iter2 = lt.erase(iter); // iter(30) 제거

    print(lt);

    iter = iter2;
    iter2 = lt.insert(iter, 300); // iter2(40) 이 가리키는 위치에 300을 삽입

    print(lt);

    cout << " iter2 : " << *iter2 << endl;

    lt.remove_if(Predicate); // Predicate의 리턴값이 참인 원소 삭제

    print(lt);
    
    return 0;

}
