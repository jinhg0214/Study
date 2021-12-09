### String 컨테이너

## 01.string의 주요 인터페이스와 특징

시퀸스 컨테이너이며, 배열 기반 컨테이너임   
표준 C++ 라이브러리는 문자와 관련된 두 컨테이너 string, wstring를 제공   
- string : char 형식의 문자를 관리하기 위한 basic_string<char> 컨테이너의 typedef 형식
- wstring : 유니코드 문자(wchar_t)를 관리하기 위한 basic_string<wchar_t>컨테이너의 typedef 형식   

# 주요 인터페이스 
- append() 
- assign()
- c_str() : '\0' 문자를 포함한 C-Style의 문자열로 변환
- compare() : s1>s2 : 1, s1==s2 : 0, s1< s2 : -1   
            문자열 비교 연산(!=, == ,>, <, >=, <=)은 전체 문자열을 비교하지만, compare()는 부분 문자열을 비교 가능
- copy() : '\0' 문자 없는 문자열을 복사 
- find() : 멤버함수의 문자, 문자열 검색 
- insert() : 가리키는 원소의 앞에 삽입
- replace()
- substr() : 일부 문자열을 추출
- getline() : 스트림으로부터 string 객체로 문자열 입력 ( >> 연산자 또는 getline() 이용)

- at()
- begin()
- capacity()
- clear()
- empty()
- end()
- erase()
- max_size()
- push_back()
- rbegin()
- rend() 
- reverse()
- resize()
- size()
- swap()
- [] 연산, 비교연산은 vector 컨테이너와 비슷함 