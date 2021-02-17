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
역방향 반복자는 가리키는 다음 원소의 값을 참조함!