### 1. 임의 접근 반복자와 양방향 반복자의 차이점을 설명하세요. 

    임의 접근 반복자는 [], += 연산자등을 지원함
    양방향 반복자는 지원하지 않음

     A) 양방향 반복자는 노드 기반 컨테이너가 제공하는 반복자이며,   
     임의 접근 반복자는 연속 메모리 기반 컨테이너가 제공하는 반복자로   
     양방향 반복자 기느에 [], +=, -=, -, <, >, <= ,>= 연산을 더 제공합니다.


### 2. X::iterator와 X::const_iterator의 차이점을 설명하세요.

    iterator는 원소 값을 읽고 쓰기 가능   
    const_iterator는 값을 수정하지 못하고 읽기만 가능함

### 3. 다음 그림은 정방향 반복자(X::iterator) iter를 역방향 반복자(X::reverse_iterator) riter로 변환을 표현한 그림입니다. 다음 물음에 답하세요.

     정방향 반복자 iter
                   ↓
     V : 10 20 30 40 50 N
                  ↑
     역방향 반복자 riter

## 1) *iter와 *riter의 값을 각각 쓰세요.

    *iter : 40, *riter = 30(바로 앞의 원소를 가리킴)

## 2) *++iter와 *++riter의 값을 각각 쓰세요.

    *++iter : 50, *++riter : 20

## 3) X::iterator iter2 = riter가 가능한가요?

    불가능

## 4) X::reverse_iterator riter2 = iter가 가능한가요?

    가능

### 4. 다음은 v1과 v2를 v3로 합병 정렬하는 코드입니다. 오류를 찾고 코드를 알맞게 고치세요.

     int main(){
         vector<int> v1;
         v1.push_back(10);
         v1.push_back(40);
         v1.push_back(50);

         vecotr<int> v2;
         v2.push_back(20);
         v2.push_back(30);
         v2.push_back(60);

         vector<int> v3(6);

         merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

         for(vector<int>::size_type i = 0; i < v3.size(); ++i)
            cout << v3[i] << endl;

        return 0;
     }

    merge는 정렬 되어있어야 하므로, v1, v2에 정렬을 수행함
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ?? 이미 정렬 되어있는데
    
### 5. 다음 v 컨테이너의 원소를 copy() 알고리즘을 사용하여 화면에 출력하세요.

     int main(){
         vector<int> v;
         v.push_back(10);
         v.push_back(20);
         v.push_back(30);

         // copy 알고리즘

         return 0;
     }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "))