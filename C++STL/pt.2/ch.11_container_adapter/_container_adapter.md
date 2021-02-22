### �����̳� �����
�ٸ� �����̳��� �������̽��� ������ �����̳�   
- stack : LIFO
- queue : FIFO
- priority_queue : ���Ҹ� �켱������ ���� �����Ǵ� ť

## 01. stack �����̳�
deque�� ������� ������ LIFO ����� �����̳�   

    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& top()
    - const value_type& top() const

## 02. queue �����̳�
deque�� ������� �� FIFO ����� �����̳�   
    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& front()
    - const value_type& front() const
    - value_type& back()
    - const value_type& back() const

## 03. priority_queue �����̳�
vector�� ������� �� �켱���� queue�� ������ ���ø� Ŭ����   
�� ������ ��� ���� �켱������ ���� ���Ұ� ���� ������ ť   
    - bool empty() const
    - size_type size() const
    - void push(const value_type& x)
    - void pop()
    - value_type& top()
    - const value_type& top() const
