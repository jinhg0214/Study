# 정렬된 범위 알고리즘(sorted range algorithms)

정렬된 구간에서만 동작하는 알고리즘   
입력 순차열이 반드시 정렬돼 있어야 함   

- binary_search(b,e,x)   
구간 [b,e)의 순차열에서 x와 같은 원소가 있으면 참을 반환
순차열의 원소가 기본 정렬 기준인 less(<)로 정렬되어 있다는 전제하에 동작함   
순차열이 greater로 정렬 되어있고, greater<int>를 비교 조건자로 지정하면 greater(>)도 사용 가능함   

- include(b,e,b2,e2)   
[b2,e2)의 원소가 [b,e)의 원소에 포함되면 참을 반환   

- lower_bound(b,e,x), upper_bound(b,e,x)   
연관 컨테이너의 멤버 함수lower, upper bound와 같음      
lower_bound : [b,e)의 순차열에서 x 원소와 같은 첫 원소의 반복자를 반환   
upper_bound : [b,e)의 순차열에서 x 원소와 같은 마지막 원소의 "다음" 원소의 반복자를 반환   

- equal_range(b,e,x)    
순차열에서 찾는 원소의 반복자 쌍(구간)을 얻음   
구간 [b,e)의 순차열에서 x와 같은 원소의 반복자 쌍(p1, p2)을 반환   
결과는 lower_bound(), upper_bound()와 같음   

# # merge
- merge(b,e,b2,e2,t)   
정렬된 두 순차열을 하나의 목적지 순차열로 합병   
[b,e)의 순차열과 [b2,e2)의 순차열을 목적지 순차열 [t,p)로 합병함   

- inplace_merge(b,m,e)   
하나의 순차열이 두 구간으로 정렬돼 있다면(한 순차열에 두개의 정렬된 구간 존재)    
inplace_merge를 통해 하나의 구간으로 정렬 가능   
정렬된 [b,m)의 순차열과 정렬된 [m,e)의 순차열을 정렬된 [b,e) 순차열로 합병함    

# # 집합 관련 알고리즘
- set_union(b,e,b2,e2,t)   
[b,e)와 [b2,e2)의 순차열을 합집합 하여 목적지 순차열 [t,p)에 저장   
중복된 원소는 삭제됨!(집합이므로)     
ex) v1:10,20,30,40,50 v2:20,30,60 -> v3:10,20,30,40,50,60    

- set_interserctioni(b,e,b2,e2,t)   
두 순차열의 교집합을 구하는 알고리즘   
[b,e)와 [b2,e2)의 순차열을 교집합 하여 목적지 순차열 [t,p)에 저장    

- set_difference()   
두 순차열의 차집합을 구하는 알고리즘    

- set_symmetric_difference()    
두 순차열의 대칭 차집합을 구하는 알고리즘     