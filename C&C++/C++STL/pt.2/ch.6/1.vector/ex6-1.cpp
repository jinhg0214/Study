/* vector 
 -벡터는 임의 접근 반복자를 지원하는 배열 기반 컨테이너!
 -원소가 하나의 메모리 블록에 연속하게 저장됨.
 -원소가 추가되거나 삽입될때, 메모리 재할당이 일어날 수 있고, 상당한 비용을 지불해야 할 수도 있음.
 그래서 capacity() 멤버 함수를 제공하여 메모리 할당 크기를 알려줌. 
 -at[], v[i] 등과 같이 원소에 접근하는 연산은 빠르지만, insert(), erase(), push_back()등은 느릴수도
 -또한 시퀸스 기반 컨테이너이므로, front(), end(), push_back(), pop_back()을 제공
 -push_front(), pop_front()는 제공안함!(매우 비효율적)*/ 
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;  // int 형식의 컨테이너 생성

    v.push_back(10); // v.push_back(x) : v에 x원소를 추가 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i =0; i<v.size(); i++){ // v.size() : v의 원소의 개수 반환
        cout << v[i] << endl;   // v[i] : v의 i번째 원소를 참조
    }

    cout << v[6] << endl; 
    //v[i] 와 v.at(i)의 차이!! v[i]는 연산자 범위점검을 하지 않아 속도가 빠름, 그러나 잘못된 값!
    // v.at(i)는 범위 점검을 하여 오류일시 예외 발생

    cout << typeid(vector<int>::size_type).name() << endl; // -> vector<int>::size_type은 unsigned int임!

    cout << v.size() << endl;       // 저장 원소 크기
    cout << v.capacity() << endl;   // 실제 할당된 메모리 공간의 크기
    cout << v.max_size() << endl;   // 컨테이너가 담을 수 있는 최대 원소의 개수

    return 0;
}