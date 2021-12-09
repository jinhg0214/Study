### 컨테이너 어댑터
다른 컨테이너의 인터페이스를 변경한 컨테이너   
- stack : LIFO
- queue : FIFO
- priority_queue : 원소를 우선순위에 의해 관리되는 큐

## 01. stack 컨테이너
deque를 기반으로 구현한 LIFO 방식의 컨테이너   

    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& top()
    - const value_type& top() const

## 02. queue 컨테이너
deque를 기반으로 한 FIFO 방식의 컨테이너   
    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& front()
    - const value_type& front() const
    - value_type& back()
    - const value_type& back() const

## 03. priority_queue 컨테이너
vector를 기반으로 한 우선순위 queue를 구현한 템플릿 클래스   
들어간 순서에 상관 없이 우선순위가 높은 원소가 먼저 나오는 큐   
    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& top()
    - const value_type& top() const
