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
������ �ݺ��ڴ� ����Ű�� ���� ������ ���� ������!