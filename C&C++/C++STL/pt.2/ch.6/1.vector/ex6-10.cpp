// swap�� ����� �Ҵ� �޸� ����
// v.clear()�� ����Ͽ� ���͸� �����Ͽ��� �޸𸮴� ���ŵ��� �ʰ� �����ִ� ���� �߻�

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v(5); // size�� 5�̰�, ��� ���Ұ� 0���� �ʱ�ȭ �� ���� ����

    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    vector<int>().swap(v); // �⺻ �����ڷ� ���� vector�����̳ʿ� v�����̳ʸ� swap�Ͽ� �޸𸮸� 0����

    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;

    return 0;
}