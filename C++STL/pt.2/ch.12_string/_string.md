### String �����̳�

## 01.string�� �ֿ� �������̽��� Ư¡

������ �����̳��̸�, �迭 ��� �����̳���   
ǥ�� C++ ���̺귯���� ���ڿ� ���õ� �� �����̳� string, wstring�� ����   
- string : char ������ ���ڸ� �����ϱ� ���� basic_string<char> �����̳��� typedef ����
- wstring : �����ڵ� ����(wchar_t)�� �����ϱ� ���� basic_string<wchar_t>�����̳��� typedef ����   

# �ֿ� �������̽� 
- append() 
- assign()
- c_str() : '\0' ���ڸ� ������ C-Style�� ���ڿ��� ��ȯ
- compare() : s1>s2 : 1, s1==s2 : 0, s1< s2 : -1   
            ���ڿ� �� ����(!=, == ,>, <, >=, <=)�� ��ü ���ڿ��� ��������, compare()�� �κ� ���ڿ��� �� ����
- copy() : '\0' ���� ���� ���ڿ��� ���� 
- find() : ����Լ��� ����, ���ڿ� �˻� 
- insert() : ����Ű�� ������ �տ� ����
- replace()
- substr() : �Ϻ� ���ڿ��� ����
- getline() : ��Ʈ�����κ��� string ��ü�� ���ڿ� �Է� ( >> ������ �Ǵ� getline() �̿�)

- at()
- begin()
- capacity()
- clear()
- empty()
- end()
- erase()
- max_size()
- push_back()
- rbegin()
- rend() 
- reverse()
- resize()
- size()
- swap()
- [] ����, �񱳿����� vector �����̳ʿ� ����� 