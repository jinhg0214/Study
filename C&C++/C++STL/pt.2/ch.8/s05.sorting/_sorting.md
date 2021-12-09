# 정렬 알고리즘(sorting algorithms)

* * * 

변경 알고리즘의 특수한 형태.   
특정 정렬 기준으로 원소의 순서를 변경하면서 정렬.

## 힙 알고리즘(heap)   
make_heap(), push_heap(), pop_heap(), sort_heap()   
트리 내의 모든 원소가 부모 노드보다 큰 값(혹은 작은값)을 갖는 완전 이진 트리.   
루트는 가장 큰값(혹은 작은값)을 가진다.   

- make_heap(b,e)    
구간 [b,e)의 순차열을 힙 구조로 만듬   

- push_heap(b,e)   
구간 [b,e)의 힙에 원소를 추가하는 알고리즘   
일반적으로 push_back()과 함께 사용함. push_back() 이후 push_heap 호출   

- pop_heap(b,e)   
힙에서 루트 노드를 제거   
[b,e)의 첫 원소를 가장 끝 원소와 교환한 후 힙이 유지되게 연산을 수행함   

- sort_heap(b,e)   
힙을 정렬함   
make_heaP()으로 생성된 알고리즘에만 적용됨    
ex) (60,50,30,40,20,10) -> (10,20,30,40,50,60)   

## nth_element(b,m,e)   
구간 [b,e)의 원소 중 m-b개 만큼의 원소를 선별    

## 순차열의 원소를 정렬   
sort(), stable_sort(), partial_sort()   

- sort(b,e), sort(b,e,f)   
퀵정렬을 기반으로 동작   
O(Nlog2N)~O(N2)의 복잡도   

- stable_sort(b,e), stable_sort(b,e,f)   
머지 정렬을 기반으로 동작   
O(Nlog2N)~O(Nlog2Nlog2N)의 복잡도   
원소의 상대적인 순서가 유지됨   

- partial_sort(b,m,e), partial_sort(b,m,e,f)   
힙정렬을 기반으로 동작   
O(Nlog2N)의 복잡도   
sort()보다 성능이 떨어짐 (매번 다운힙을 실행해야하기 때문)   
순차열의 상위 구간만을 정렬하거나, 힙 정렬이 필요할 때 사용   

- partial_sort_copy(b,e,b2,e2), partial_sort_copy(b,e,b2,e2,f)   
구간 [b,e)의 원소 중 e2-b2개의 상위 원소를 정렬하여, [b2,e2)의 순차열로 복사함   
