# # # 1. 다음 빈 칸을 채우세요

1) 구간 [begin,end)에서 찾기 관련 알고리즘이 원소를 발견하지 못했다면 알고리즘은 (    ) 반복자를 반환합니다.   
2) bool 형식을 반환하는 함수나, 함수 포인터, 함수 객체를 (    )라 합니다.   
3) 모든 알고리즘은 삽입(insert) 모드가 아닌 (    ) 모드로 동작합니다.   

A) 끝 표시 반복자(past-the-end),   
   조건자(predicate),   
   덮어쓰기(overwrite)   

# # # 2. 다음 그림을 보고 알고리즘을 사용하여 vector의 원소를 제거하세요.

 전 : | 10 | 20 | 30 | 40 | 50 | N   
 후 : | 10 | 20 | 40 | 50 |   

A) v.erase(v.begin(), v.end(), 30)   

# # # 3. 다음 그림을 보고 알고리즘을 사용하여 vector의 일부 원소를 뒤집는 코드를 작성하세요.

 전 : | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | N   
 후 : | 50 | 40 | 30 | 20 | 10 | 60 | 70 | 80 | 90 | 100 | N   

A) reverse(v.begin(), v.begin()+5)   

# # # 4. 다음 그림을 보고 알고리즘을 사용하여 vector를 정렬하고 모든 원소가 유일하게 코드를 작성하세요/

 전 : | 70 | 20 | 32 | 40 | 33 | 60 | 32 | 33 | 90 | 50 | N   

A) sort(v.begin(),v.end()) // 정렬후   
   unique(v.begin(),v.end()) // 유일하게   

# # # 5. 다음 vector1의 원소를 vector2에 복사하고, vector1과 vector2의 원소의 합을 vector3에 출력하는 코드를 작성하세요.

    vector1 : | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | N   
       ↓   
    vector2 : | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | N   

    vector3 : 합   

A)
    struct Sum{
       int operator() (int left, int right) const{
          return left + right;
       }
    }

    copy(v1.begin(), v1.end(), v2.begin()) // vector1을 vector2로 복사   

    transform(v1.begin(), v1.end(), v2.begin(), v2.end(), Sum()); // transform를 이용하여 합 저장   

# # # 6. 다음 v1과 v2를 v3로 합병하는 코드를 작성하세요

 v1(size 5) : | 50 | 10 | 30 | 80 | 60 | N    
 v2(size 3) : | 20 | 70 | 40 | N   
  [merge]   
 v3(size 8) : | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | N   

A)
 // 먼저 두 순차열을 정렬한 뒤
 sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());

 // 합병 
 // v3의 size가 0이므로, 알고리즘이 삽입모드로 동작하게 inserter()를 사용함
 merge(v1.begin(),v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));

# # # 7. 다음에서 전 vector를 후 vector의 순차열로 만드는 코드를 작성하세요.

 전 : | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 | N    
 후 : | 70 | 80 | 90 | 100 | 10 | 20 | 30 | 40 | 50 | 60 | N   

A)
 rotate(v.begin(), v.begin() + v.size()/2 + 1, v.end()) 

# # # 8. 다음 v1+v2의 합 집합을 v3에 출력하는 코드 작성

 v1 : | 50 | 10 | 30 | 80 | 60 | N   
 v2 : | 20 | 70 | 40 | N   

A)
 // 먼저 두 순차열을 정렬한 뒤
 sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());

 set_union(v1.begin() ,v1.end(),v2.begin(), v2.end(), inserter(v3, v3.begin()));
    

