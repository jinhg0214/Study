<h1> Set </h1>
- 연관 컨테이너이자 노드 기반 컨테이너
- 연관 컨테이너는 특정 정렬 기준에 의해 원소가 자동 정렬되는 컨테이너
- 원소 검색을 로그 시간 복잡도에 수행
- 균형 이진트리로 구현되며, 여러 찾기 관련 함수를 제공함
- set, multiset, map, multimap 등 연관 컨테이너 모두 같은 인터페이스 함수 제공

- count(), find(), lower_bound(), upper_bound(), equal_range(), insert()
- 양방향 반복자 지원 begin(), end(), rbegin(), rend() 반복자 반환