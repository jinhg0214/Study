# 반복자 

* * * 

## 반복자의 종류
- 입력 반복자(input iterator) : 전방향 읽기(istream)
    *iter(읽기), ->(멤버 읽기), ++(전방향 이동), ==(비교), !=(비교), iterator(iter) 연산을 제공

- 출력 반복자(output iterator) : 전방향 쓰기(ostream)
    *iter=x(쓰기), ++, iteraotr(iter)(복사 생성자) 연산 제공

- 순방향 반복자(foward iterator) : 전방향 읽기, 쓰기
    *iter, ->, ++, ==, !=, =(대입), iterator()(기본 생성자), iterator(iter) 연산 제공

- 양방향 반복자(bidirectional iterator) : 양방향 읽기, 쓰기(list, set, multiset, map, multimap)
    순방향 반복자 기능 + --(역방향 이동) 연산 제공

- 임의 접근 반복자(random access iterator) : 랜덤 읽기, 쓰기(vector, queue)
    양방향 반복자 기능 + 랜덤 연산인 [], +=, -=, +, -, <, >, <=, >= 연산을 제공

* * *

## X::iterator와 X::const_iterator
X::iterator : 정방향 반복자의 내장 형식, 반복자가 가리키는 원소 읽기, 쓰기 가능   
X::const_iterator : 정방향 반복자의 내장 형식, 반복자가 가리키는 원소 '읽기'만 가능

     vector<int>::iterator iter;                
     vector<int>::const_iterator citer;
     const vector<int>::iterator const_iter;
     const vector<int>::iterator const_citer;

     // iter는 모두 가능
     *iter = 100; // 가리키는 원소 변경 가능
     ++iter;      // 반복자 변경 가능

     // citer 
     *citer =200; // 가리키는 원소 변경 불가!
     ++citer;     // 반복자 변경 가능
    
     // const_iter
     *const_iter = 300; // 가리키는 원소 변경 가능
     ++const_iter;      // 반복자 변경 불가!

     // const_citer
     *const_citer = 400; // 가리키는 원소 변경 불가!
     ++const_citer;      // 반복자 변경 불가!

* * *

## X::reverse_iterator와 X::reverse_const_iterator
iterator 와 같은 기능을 제공하는 역방향 반복자 형식    
     
     for(vector<int>::reverse_iterator riter = v.rbegin(); riter != rend(); ++riter)
        cout << *riter << " ";

역방향 반복자는 반복자가 가리키는 원소와 실제 값이 다름!!   
역방향 반복자는 가리키는 다음 원소의 값을 참조   

* * *

## 삽입 반복자

순차열에 원소를 삽입(insert)할 수 있게 반복자를 변환하는 반복자 어댑터   
- inserter(): inserter_iterator 객체를 생성. 컨테이너의 insert() 멤버 함수를 호출해 삽입 모드로 동작   
- back_inserter(): back_inserter_iterator를 통해 push_back() 멤버 함수를 호출. (vector, deque, list만)
- front_inserter(): front_inserter_iterator ''(deque, list만)

* * *

## 입/출력 스트림 반복자

스트림과 연결된 반복자   
알고리즘이 스트림에 읽고 쓸 수 있게 하는 반복자 어댑터   
- istream_iterator<T> : 입력 스트림과 연결된 반복자로 T 형식의 값을 스트림에서 읽을 수 있음
- ostream_iterator<T> : 출력 ''

* * *

## 반복자 특성과 보조 함수
### 보조 함수
- advance(p,n) : p 반복자를 p+=n 의 위치로 이동시킴
- n = distance(p1, p2) : n은 p2-p1   

vector는 임의 접근 반복자를 제공하므로 v.end()-v.begin()이 가능하지만,   
list는 양방향 반복자를 제공하므로, lt.end()-lt.begin()이 불가능함

     iterator_traits<vector<int>::iterator>::difference_type n = distnace(lt.begin(), lt.end());
을 이용하여 거리를 구할 수 있음

* * *

### 반복자 특성
??