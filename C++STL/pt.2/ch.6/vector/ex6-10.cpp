// swap을 사용한 할당 메모리 제거
// v.clear()를 사용하여 벡터를 제거하여도 메모리는 제거되지 않고 남이있는 문제 발생

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v(5); // size가 5이고, 모든 원소가 0으로 초기화 된 벡터 생성

    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    vector<int>().swap(v); // 기본 생성자로 만든 vector컨테이너와 v컨테이너를 swap하여 메모리를 0으로

    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    return 0;
}