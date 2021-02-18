# �ݺ��� 

* * * 

## �ݺ����� ����
- �Է� �ݺ���(input iterator) : ������ �б�(istream)
    *iter(�б�), ->(��� �б�), ++(������ �̵�), ==(��), !=(��), iterator(iter) ������ ����

- ��� �ݺ���(output iterator) : ������ ����(ostream)
    *iter=x(����), ++, iteraotr(iter)(���� ������) ���� ����

- ������ �ݺ���(foward iterator) : ������ �б�, ����
    *iter, ->, ++, ==, !=, =(����), iterator()(�⺻ ������), iterator(iter) ���� ����

- ����� �ݺ���(bidirectional iterator) : ����� �б�, ����(list, set, multiset, map, multimap)
    ������ �ݺ��� ��� + --(������ �̵�) ���� ����

- ���� ���� �ݺ���(random access iterator) : ���� �б�, ����(vector, queue)
    ����� �ݺ��� ��� + ���� ������ [], +=, -=, +, -, <, >, <=, >= ������ ����

* * *

## X::iterator�� X::const_iterator
X::iterator : ������ �ݺ����� ���� ����, �ݺ��ڰ� ����Ű�� ���� �б�, ���� ����   
X::const_iterator : ������ �ݺ����� ���� ����, �ݺ��ڰ� ����Ű�� ���� '�б�'�� ����

     vector<int>::iterator iter;                
     vector<int>::const_iterator citer;
     const vector<int>::iterator const_iter;
     const vector<int>::iterator const_citer;

     // iter�� ��� ����
     *iter = 100; // ����Ű�� ���� ���� ����
     ++iter;      // �ݺ��� ���� ����

     // citer 
     *citer =200; // ����Ű�� ���� ���� �Ұ�!
     ++citer;     // �ݺ��� ���� ����
    
     // const_iter
     *const_iter = 300; // ����Ű�� ���� ���� ����
     ++const_iter;      // �ݺ��� ���� �Ұ�!

     // const_citer
     *const_citer = 400; // ����Ű�� ���� ���� �Ұ�!
     ++const_citer;      // �ݺ��� ���� �Ұ�!

* * *

## X::reverse_iterator�� X::reverse_const_iterator
iterator �� ���� ����� �����ϴ� ������ �ݺ��� ����    
     
     for(vector<int>::reverse_iterator riter = v.rbegin(); riter != rend(); ++riter)
        cout << *riter << " ";

������ �ݺ��ڴ� �ݺ��ڰ� ����Ű�� ���ҿ� ���� ���� �ٸ�!!   
������ �ݺ��ڴ� ����Ű�� ���� ������ ���� ����   

* * *

## ���� �ݺ���

�������� ���Ҹ� ����(insert)�� �� �ְ� �ݺ��ڸ� ��ȯ�ϴ� �ݺ��� �����   
- inserter(): inserter_iterator ��ü�� ����. �����̳��� insert() ��� �Լ��� ȣ���� ���� ���� ����   
- back_inserter(): back_inserter_iterator�� ���� push_back() ��� �Լ��� ȣ��. (vector, deque, list��)
- front_inserter(): front_inserter_iterator ''(deque, list��)

* * *

## ��/��� ��Ʈ�� �ݺ���

��Ʈ���� ����� �ݺ���   
�˰����� ��Ʈ���� �а� �� �� �ְ� �ϴ� �ݺ��� �����   
- istream_iterator<T> : �Է� ��Ʈ���� ����� �ݺ��ڷ� T ������ ���� ��Ʈ������ ���� �� ����
- ostream_iterator<T> : ��� ''

* * *

## �ݺ��� Ư���� ���� �Լ�
### ���� �Լ�
- advance(p,n) : p �ݺ��ڸ� p+=n �� ��ġ�� �̵���Ŵ
- n = distance(p1, p2) : n�� p2-p1   

vector�� ���� ���� �ݺ��ڸ� �����ϹǷ� v.end()-v.begin()�� ����������,   
list�� ����� �ݺ��ڸ� �����ϹǷ�, lt.end()-lt.begin()�� �Ұ�����

     iterator_traits<vector<int>::iterator>::difference_type n = distnace(lt.begin(), lt.end());
�� �̿��Ͽ� �Ÿ��� ���� �� ����

* * *

### �ݺ��� Ư��
??