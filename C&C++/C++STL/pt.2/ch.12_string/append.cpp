#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1("He");
    string s2("He");
    string s3("He");
    string s4("He");
    string s5("He");
    string s6("He");
    string s7("He");
    string s8("He");
    string s9("He");
    string s10("He");

    string t("llo!");
    const char* p1 = "llo!";
    const char* p2 = p1+4;

    s1.append(t);           // t�� s1�� �߰�
    s2.append(t,0,4);       // t�� 0~4�� s1�� �߰�
    s3.append("llo!");      // ���ڿ��� ���� �߰�
    s4.append("llo!", 4);   // 4 ���ڿ��� ���� �߰�
    s5.append(t.begin(), t.end()); 
    s6.append(p1,p2);       // �����͸� �̿��� �߰�
    s7.append(5, 'H');      // H 5���� �߰�
    s8 += t;                // s8+t
    s9 += "llo!";           
        
    // iter�� �̿��� �߰�
    for(string::iterator iter=t.begin(); iter != t.end(); iter++){
        s10.push_back(*iter);
    }

    // s: string ��ü, sz: '\0'���ڿ�, c: ����, off: ������ġ, n: ����, iter: �ݺ���, p: ������
    cout << "s1.append(s): " << s1 << endl;
    cout << "s2.append(s,off,n): " << s2 << endl;
    cout << "s3.append(sz): " << s3 << endl;
    cout << "s4.append(sz,n): " << s4 << endl;
    cout << "s5.append(iter1,iter2): " << s5 << endl;
    cout << "s6.append(p1,p2): " << s6 << endl;
    cout << "s7.append(n,c): " << s7 << endl;
    cout << "s8+=s:  " << s8 << endl;
    cout << "s9+=sz: " << s9 << endl;
    cout << "s10.push_back(c): " << s10 << endl;



}