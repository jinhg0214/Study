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