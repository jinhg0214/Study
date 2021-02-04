<h1>변경 알고리즘(mutating algorithms)</h1>

- next_permutation(b,e), next_permutation(b,e,f)
    구간 [b,e)의 순차열을 이용해 순열을 생성하는 알고리즘. 
    더 이상 다음 순열이 없는 마지막 순열이라면 false를 리턴함
    ex) 1,2,3(1) -> 1,3,2(1) -> 2,1,3(1) -> 2,3,1(1) -> 3,1,2(1) -> 3,2,1(0)

- prev_permutation(b,e), prev_permutation(b,e,f)
    순차열 이전의 순열을 만들어냄. 첫 순열일때 false를 반환

- partitaion(b,e,f)
    순차열의 원소를 특정 조건에 따라 분류함
    [b,e)의 반복자가 p일때, f(*p)가 참인 원소는 [b,p)의 순차열에, 거짓인 원소는 [p,e)의 순차열로 분류함.
    퀵소트에서 pivot값을 기준으로 큰 값과 작은 값을 분류하듯이 f(*p) 값을 기준으로 참인 원소와 거짓인 원소를 분류함.

- stable_partitation(b,e,f)
    원소의 상대적인 순서를 유지하면서, 특정 조건에 따라 분류함

- random_shuffle(b,e)
    [b,e) 구간을 랜덤으로 뒤섞음
    시드값 #include <ctime> srand((unsigned)time(NULL)); 을 이용

- reverse(b,e)
    [b,e) 구간의 순차열을 역순으로 뒤집음

- reverse_copy(b,e,t)
    뒤집힌 순차열을 목적지 순차열로 복사함
    목적지 순차열에 복사할 때 덮어쓰기 모드로 동작하므로, t는 [b,e)이상의 size를 가져야함!

- rotate(b,m,e)
    순차열을 회전시키는 알고리즘
    첫 원소와 마지막 원소가 연결된 것처럼 왼쪽으로 m-e만큼씩 회전함\

- rotate_copy(b,m,e,t)
    순차열을 회전시켜 목적지 순차열에 복사.