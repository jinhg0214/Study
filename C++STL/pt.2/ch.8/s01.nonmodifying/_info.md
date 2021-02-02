<h1>원소를 수정하지 않는 알고리즘(nonmodifying algorithms)</h1>

원소의 순서나 원소의 값을 변경하지 않고

원소를 읽기만 하는 알고리즘.

- adjacent_find(b,e), adjacent_find(b,e,f)
// 구간 [v.begin(), v.end())에서 현재 원소와 다음 원소가 같아지는 첫 원소 반복자를 반환

- count(), count_if()
// 순차열에서 원소의 개수를 구하는 멤버 함수

- equal(b,e,b2) , equal(b,e,b2,f)
// 두 순차열의 원소가 모두 같은지 판별
// 또는 구간이 같은지 판별

- find(), find_if(), find_end(), find_first_of()
// 특정 원소를 찾는 알고리즘

- for_each()
// 순차열의 모든 원소에 사용자 동작을 적용
// nonmodifying, modifying에 모두 해당됨

- lexicographical_compare() 
// 문자열 비교처럼 순차열의 사전순 비교 
// [v1.begin(),v1.end())가, [v2.begin(), v2.end())보다 사전순서가 less인가? 혹은 greater인가?

- min(), max()
// 최대 최소값

- mismatch()
// [b, e)와 [b2, b2+(e-b))를 비교하여, 
// 원소 값이 서로 다른 첫 원소의 반복자 쌍을 반환함(v1과 v2의 값이 달라지는 지점)

- search()
// [v1.begin(), v1.end()) 와 [v2.begin(),v2.end())를 비교하여 순차열이 일치하는지 판단하여,
//일치하는 순차열 구간이 여러개라면 첫 번째 순차열의 첫 원소 반복자를 반환함

- search(b,e,n,x) 
// [b,e) 구간에서 원소 x가 n번 반복되는 첫 원소의 반복자를 반환