/* deque�� vector�� ����������, �޸� ��� �Ҵ� ��å�� �ٸ�.
vector�� �ϳ��� �޸� ��� �Ҵ� ��å -> �����Ͽ� �а� ���µ��� ��������, ���Ұ� �߰��ɶ� ���Ҵ��� �� ���� �߻�
deque�� ���� �޸� ����� �Ҵ��ϰ�, ����ڿ��Դ� �ϳ��� ���̰� ��. ���� �޸𸮰� ������ ������, ���� �Ҵ��ϰ� �����ϴ� �۾� ���� ��밡��

*/

#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;

    for(deque<int>::size_type i =0; i<10; ++i){
        dq.push_back((i+1)*10);
    }

    deque<int>::iterator iter;
    deque<int>::iterator iter2;

    for(iter = dq.begin(); iter != dq.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    iter = dq.begin()+2;

    iter2 = dq.insert(iter, 500); // iter�� ��ġ�� 500�� �߰�. vector�� �ٸ��� �޸� ���Ҵ��� �Ͼ�� �ʰ� ���Ե�.
    cout << *iter2 << endl;

    for(iter = dq.begin(); iter != dq.end(); ++iter)
        cout << *iter << " ";
    cout << endl;  

    return 0;

}