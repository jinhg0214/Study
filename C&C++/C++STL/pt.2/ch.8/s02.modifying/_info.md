<h1>원소를 수정하는 알고리즘(modifying algorithms)</h1>

- 원소의 값을 변경하거나 목적지 순차열로 원소를 복사하는 알고리즘

- copy(b,e,t), copy_backward()
// 순차열에서 다른 순차열로 원소를 복사
// 두가지 모드 존재. 덮어쓰기 모드(overwrite), 삽입 모드(insert).
// 기본 동작은 덮어쓰기 모드이며, 반복자 어댑터(insert_iterator)등을 사용하여 알고리즘을 삽입 모드로 동작할 수 있음

- fill(), fill_n()
// 순차열을 특정 값으로 채우고자 할 때 사용하는 알고리즘

- for_each() 
// 원소를 수정하지 않는 알고리즘이기도 하나, 원소를 수정할 수도 있음
// [b,e)의 반복자가 p라면, 모든 원소에 f(*p)를 적용함. (f는 함수자, 함수, 함수 포인터 등)

- generate()
// 순차열의 모든 원소를 단순한 동작의 값으로 수정하고자 할 때 사용.

- iter_swap(), swap()
// 반복자가 가리키는 값을 교환, 단순 값을 교환

- merge() 
// 정렬된 두 순차열을 하나의 정렬된 순차열로 합병
// merge(b, e, b2, e2, t) : 정렬된 구간 [b,e)와 [b2,e2)의 순차열을 [t,t+(e-b)+(e2-b2))의 순차열로 합병 정렬함.

- replace(b,e,x,x2), replace_if(b,e,f,x2), replace_copy(), replace_copy_if(b,e,b2,f,x2)
// 순차열의 특정 원소(x)를 다른 값(x2)으로 수정

- swap_ranges(b, e, b2)
// [b,e)의 모든 원소와 [b2, b2+(e-b))의 모든 원소를 교환

