### 1. ���� ���� �ݺ��ڿ� ����� �ݺ����� �������� �����ϼ���. 

    ���� ���� �ݺ��ڴ� [], += �����ڵ��� ������
    ����� �ݺ��ڴ� �������� ����

     A) ����� �ݺ��ڴ� ��� ��� �����̳ʰ� �����ϴ� �ݺ����̸�,   
     ���� ���� �ݺ��ڴ� ���� �޸� ��� �����̳ʰ� �����ϴ� �ݺ��ڷ�   
     ����� �ݺ��� ����� [], +=, -=, -, <, >, <= ,>= ������ �� �����մϴ�.


### 2. X::iterator�� X::const_iterator�� �������� �����ϼ���.

    iterator�� ���� ���� �а� ���� ����   
    const_iterator�� ���� �������� ���ϰ� �б⸸ ������

### 3. ���� �׸��� ������ �ݺ���(X::iterator) iter�� ������ �ݺ���(X::reverse_iterator) riter�� ��ȯ�� ǥ���� �׸��Դϴ�. ���� ������ ���ϼ���.

     ������ �ݺ��� iter
                   ��
     V : 10 20 30 40 50 N
                  ��
     ������ �ݺ��� riter

## 1) *iter�� *riter�� ���� ���� ������.

    *iter : 40, *riter = 30(�ٷ� ���� ���Ҹ� ����Ŵ)

## 2) *++iter�� *++riter�� ���� ���� ������.

    *++iter : 50, *++riter : 20

## 3) X::iterator iter2 = riter�� �����Ѱ���?

    �Ұ���

## 4) X::reverse_iterator riter2 = iter�� �����Ѱ���?

    ����

### 4. ������ v1�� v2�� v3�� �պ� �����ϴ� �ڵ��Դϴ�. ������ ã�� �ڵ带 �˸°� ��ġ����.

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

    merge�� ���� �Ǿ��־�� �ϹǷ�, v1, v2�� ������ ������
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ?? �̹� ���� �Ǿ��ִµ�
    
### 5. ���� v �����̳��� ���Ҹ� copy() �˰����� ����Ͽ� ȭ�鿡 ����ϼ���.

     int main(){
         vector<int> v;
         v.push_back(10);
         v.push_back(20);
         v.push_back(30);

         // copy �˰���

         return 0;
     }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "))